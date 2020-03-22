unsigned long timestamp; 
unsigned long time_diff = 5; // try to loop every 40 ms​
unsigned int STEP_PIN=9;
unsigned int DIR_PIN=10;
#define ENDSIWTCH_FULL_PIN 7
#define ENDSWITCH_PUSH_PIN 6
unsigned long motor_time;
enum motor_state_t{UP,DOWN};
motor_state_t motor_state=DOWN;

float CurrentPressurePatient;
//----------------------------------------------------------------------------------------------------
//-----------------------------------------    BEGIN OF SETUP ----------------------------------------
void beademing_setup()
{
	SerialOutput.println(F("1"));
  timestamp = millis();
  SerialOutput.println(F("2"));
  BME280_Setup(); 
  SerialOutput.println(F("3"));
  Stepper_SETUP(DIR_PIN, STEP_PIN);
  SerialOutput.println(F("4"));
  Stepper_ENABLE(true);
  SerialOutput.println(F("5"));
  pinMode(ENDSIWTCH_FULL_PIN,INPUT);
  SerialOutput.println(F("6"));
  pinMode(ENDSWITCH_PUSH_PIN,INPUT);
  SerialOutput.println(F("7"));
}
//----------------------------------------------------------------------------------------------------
//-----------------------------------------    END OF SETUP ------------------------------------------
void beademing_loop()
{   
  BREATHE_CONTROL_setPointInhalePressure(30);  
  long new_time = millis();
  //--- read buttons here
  int END_SWITCH_VALUE_STOP = digitalRead(ENDSIWTCH_FULL_PIN);
  int END_SWITCH_VALUE_START = digitalRead(ENDSWITCH_PUSH_PIN);
  if (timestamp+time_diff<=new_time)
  {
    if (BME280_readPressurePatient(&CurrentPressurePatient))
    {    
      
      BREATHE_CONTROL_setInhalePressure(CurrentPressurePatient);
      float angle = BREATHE_CONTROL_Regulate();  
      Stepper_Speed((int)angle);     
      BREATHE_setToEXHALE(END_SWITCH_VALUE_STOP);
      BREATHE_setToINHALE(END_SWITCH_VALUE_START);
       
      Serial.print("Pinhale: ");
      Serial.print(CurrentPressurePatient);       
      Serial.print(" PID: ");
      Serial.print(angle);
      Serial.print(" , stop?: ");
      Serial.println(END_SWITCH_VALUE_STOP);
    }
    else
    {
      Serial.println("Pressure sensors failing");
    }
    timestamp=new_time;
  }

}
