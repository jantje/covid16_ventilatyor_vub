#ifndef BREATHE_CONTROL_H
#define BREATHE_CONTROL_H

// update very 40ms
float PRESSURE_INHALE_SETPOINT = 50;
float VOLUME_SETPOINT = 600; // in ml;
float BREATHING_SPEED_SETPOINT = 10; // in # per second
float current_inhale_pressure = 0;

float Vlung = 0;
bool is_blocking = false;

float MAX_DISPLACEMENT=500;
float offset = 130;
float exhale_speed = 200;

//----------------------------------
float Kp = 4;
float Ki = 0.1;
//----------------------------------
float PID_value = 0;
float PID_value_P = 0;
float PID_value_I = 0;
//----------------------------------
float PLUNGER_POSITION = 0;

enum BREATHE_PHASE{INHALE, EXHALE, BLOCK};
BREATHE_PHASE Breathe_mode = INHALE;

int EXHALE_TIME = 0;
//------------------------------------------------------------------------------
void BREATHE_CONTROL_setPointInhalePressure(float setting)
{
  PRESSURE_INHALE_SETPOINT = setting;
}
//------------------------------------------------------------------------------
float BREATHE_CONTROL_getPointInhalePressure()
{
  return PRESSURE_INHALE_SETPOINT;
}
//------------------------------------------------------------------------------
void BREATHE_CONTROL_setInhalePressure(float setting)
{
  current_inhale_pressure = setting;
}
//------------------------------------------------------------------------------
float BREATHE_CONTROL_getInhalePressure()
{
  return current_inhale_pressure;
}
//------------------------------------------------------------------------------
float BREATHE_getPID()
{
  return PID_value;
}
//------------------------------------------------------------------------------
void BREATHE_setToEXHALE(int end_switch)
{
  if (end_switch==1)
  {
    PID_value_I=0;
    PID_value_P=0;
    Breathe_mode=EXHALE;
  }
}
//------------------------------------------------------------------------------
void BREATHE_setToINHALE(int end_switch)
{
    if (end_switch==1)
    {
      Breathe_mode=INHALE;
    }
}
//------------------------------------------------------------------------------
float BREATHE_CONTROL_Regulate()
{
    float diff = current_inhale_pressure-PRESSURE_INHALE_SETPOINT;
    if (Breathe_mode==INHALE)
    {
      PID_value_P = Kp*diff;
      PID_value_I += Ki*diff;
      PID_value_I = (PID_value_I>offset)?offset:PID_value_I;
      PID_value_I = (PID_value_I<-offset)?-offset:PID_value_I;
      PID_value = PID_value_P + PID_value_I;
      if (PID_value>0) PID_value=0;
      return PID_value;
    }
    else if (Breathe_mode==EXHALE)
    {
      PID_value_I=0;
      PID_value_P=0;
      return exhale_speed;
    }
}
//------------------------------------------------------------------------------
#endif
