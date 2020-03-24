unsigned long oldTime;
unsigned long time_diff = 5; // try to loop every 5 ms
unsigned int STEP_PIN=9;
unsigned int DIR_PIN=10;
#define ENDSIWTCH_FULL_PIN 7
#define ENDSWITCH_PUSH_PIN 6
unsigned long motor_time;
enum motor_state_t{UP,DOWN};
motor_state_t motor_state=DOWN;
uint32_t numberOfSteps=1000;
bool isInhale();
void setNumberOfSteps(uint32_t newNumberOfSteps){
	numberOfSteps=newNumberOfSteps;
}
uint32_t getNumberOfSteps( ){
	return numberOfSteps;
}

#define LOG(x)    // 	SerialOutput.println(F(x));delay (10);

float CurrentPressurePatient;
//----------------------------------------------------------------------------------------------------
//-----------------------------------------    BEGIN OF SETUP ----------------------------------------
void beademing_setup()
{
  //Serial.begin(115200);
  oldTime = millis();
  BME280_Setup();
  Stepper_SETUP(DIR_PIN, STEP_PIN);
  Stepper_ENABLE(true);
  pinMode(ENDSIWTCH_FULL_PIN,INPUT);
  pinMode(ENDSWITCH_PUSH_PIN,INPUT);
}
//----------------------------------------------------------------------------------------------------
//-----------------------------------------    END OF SETUP ------------------------------------------
void beademing_loop()
{   
  BREATHE_CONTROL_setPointInhalePressure(75);  
  unsigned long new_time = millis();
  //--- read buttons here
  int END_SWITCH_VALUE_STOP = digitalRead(ENDSIWTCH_FULL_PIN);
  int END_SWITCH_VALUE_START = digitalRead(ENDSWITCH_PUSH_PIN);

  if (new_time-oldTime> time_diff)
  {
    //if (BME280_readPressurePatient(&CurrentPressurePatient))
    {   
      BREATHE_setCurrentTime(new_time);      
      //BREATHE_CONTROL_setInhalePressure(CurrentPressurePatient);
      float angle = BREATHE_CONTROL_Regulate();  
      Stepper_Speed((int)angle);     
      if( ( stepper_GetStepsStepped() >numberOfSteps) && isInhale()){
    	  BREATHE_setToEXHALE(1);
      }else{
      BREATHE_setToEXHALE(END_SWITCH_VALUE_STOP);
      BREATHE_setToINHALE(END_SWITCH_VALUE_START);
      }

      
      /*Serial.print("P:");
      Serial.print(CurrentPressurePatient);       
      Serial.print(";PID=");
      Serial.print(angle);
      Serial.print(";bpm=");
      Serial.println(BREATHE_getBPM());*/
    }
    //else
    {
      //Serial.println("Pressure sensors failing");
    }
    /*float sens = getSensor1();
    //Serial.print(new_time);
    //Serial.print(";");
    Serial.println(sens-1020);*/
    oldTime=new_time;
  }

}
