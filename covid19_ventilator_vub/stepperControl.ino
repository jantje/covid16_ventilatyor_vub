int STEPPER_DIR_PIN;
int STEPPER_STEP_PIN;
bool STEPPER_enable;
int STEPPER_speed = 0;
int STEPPER_direction = 0;
unsigned int toggle = 0;
int ref_point = 256;
int max_diff = 10;
//----------------------------------------------------------------------
void Stepper_SETUP(int DIR, int STEP)
{
  STEPPER_DIR_PIN = DIR;
  STEPPER_STEP_PIN = STEP;
  pinMode(STEPPER_DIR_PIN,OUTPUT);
  pinMode(STEPPER_STEP_PIN,OUTPUT);
  noInterrupts();           // disable all interrupts
  //set timer4 interrupt at 1Hz
   TCCR4A = 0;// set entire TCCR1A register to 0
   TCCR4B = 0;// same for TCCR1B
   TCNT4  = 0;//initialize counter value to 0
   // set compare match register for 1hz increments
   OCR4A = 65536;// = (16*10^6) / (1*1024) - 1 (must be <65536)
   // turn on CTC mode
   TCCR4B |= (1 << WGM12);
   // Set CS12 and CS10 bits for 1024 prescaler
   TCCR4B |= (1 << CS12) | (1 << CS12);
   // enable timer compare interrupt
   TIMSK4 |= (1 << OCIE4A);
  interrupts();             // enable all interrupts
}
//----------------------------------------------------------------------
void Stepper_Speed(int spd)
{
   if (spd<0)
   {
    if (STEPPER_direction==1)
    {
      spd = 0;
    }
    else
    {
      spd = -spd;
    }
    STEPPER_direction = 0;
    digitalWrite(STEPPER_DIR_PIN,STEPPER_direction);
   }
   else
   {
    STEPPER_direction = 1;
    digitalWrite(STEPPER_DIR_PIN,STEPPER_direction);
   }

   STEPPER_speed = ref_point-spd;
   if (STEPPER_speed>ref_point) STEPPER_speed = ref_point;
   if (STEPPER_speed<1) STEPPER_speed = 1;

   //Serial.print("Stepper speed: ");
   //Serial.println(STEPPER_speed);

   TCNT4  = 0;
   OCR4A = STEPPER_speed;
}
//----------------------------------------------------------------------
void Stepper_ENABLE(bool en)
{
   STEPPER_enable = en;
}
//----------------------------------------------------------------------
void Stepper_SetDirection(int dir)
{
  STEPPER_direction = dir;
  digitalWrite(STEPPER_DIR_PIN,STEPPER_direction);
}
//----------------------------------------------------------------------
ISR(TIMER4_COMPA_vect)
{
  if ((STEPPER_speed>0)&&(STEPPER_enable))
  {
    digitalWrite(STEPPER_STEP_PIN,toggle);
    toggle = !toggle;
  }
}
//----------------------------------------------------------------------
