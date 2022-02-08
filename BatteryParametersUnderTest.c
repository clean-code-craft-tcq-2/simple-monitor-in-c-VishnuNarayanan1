#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "BatteryParametersUnderTest.h"
#include "ValidateBatteryParameterLimits.h"


int CheckBatteryParameterLimits(char message[][100],float measuredTemperatureValueUnderTest,float minLimit, float maxLimit, 
                                void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float), void (*Fn_Ptr_PrintMessage)(char[]))
{
  int batteryParameterStatus = 1;
  Fn_Ptr_PrintMessage(message);
  if(ValidateIfBatteryParameterValueIsLessThanMinOperatingLimit(minLimit,measuredTemperatureValueUnderTest,Fn_Ptr_PrintMessageWithBreachLevel) 
    && ValidateIfBatteryParameterValueIsGreaterThanMaxOperatingLimit(maxLimit,measuredTemperatureValueUnderTest,Fn_Ptr_PrintMessageWithBreachLevel ) )
  {
    batteryParameterStatus = 0;
  }
  return batteryParameterStatus;
}


//---------------------------------------------------------------------------------------------
/// Battery Temperature under test
///
//---------------------------------------------------------------------------------------------
int CheckBatteryTemperature(float measuredTemperatureValueUnderTest,void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float), void (*Fn_Ptr_PrintMessage)(char[]))
{
  int batteryTemperatureStatus = 1;
  char message[75] = "Battery parameter under test is Temperature";
  Fn_Ptr_PrintMessage(message);
  if(ValidateIfBatteryParameterValueIsLessThanMinOperatingLimit(MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,measuredTemperatureValueUnderTest,Fn_Ptr_PrintMessageWithBreachLevel) 
    && ValidateIfBatteryParameterValueIsGreaterThanMaxOperatingLimit(MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,measuredTemperatureValueUnderTest,Fn_Ptr_PrintMessageWithBreachLevel ) )
  {
    batteryTemperatureStatus = 0;
  }
  return batteryTemperatureStatus;
}


//---------------------------------------------------------------------------------------------
/// Battery State Of Charge under test
///
//---------------------------------------------------------------------------------------------
int CheckBatteryStateOfCharge(float measuredStateOfChargeUnderTest,void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float), void (*Fn_Ptr_PrintMessage)(char[]))
{
  int batteryStateOfChargeStatus = 1;
  char message[75] = "Battery parameter under test is State Of Charge (SOC)";
  Fn_Ptr_PrintMessage(message);
  if(ValidateIfBatteryParameterValueIsLessThanMinOperatingLimit(MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE,measuredStateOfChargeUnderTest,Fn_Ptr_PrintMessageWithBreachLevel) 
    && ValidateIfBatteryParameterValueIsGreaterThanMaxOperatingLimit(MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE,measuredStateOfChargeUnderTest,Fn_Ptr_PrintMessageWithBreachLevel ) )
  {
    batteryStateOfChargeStatus = 0;
  }
  return batteryStateOfChargeStatus;
}


//---------------------------------------------------------------------------------------------
/// Battery Charge rate under test
///
//---------------------------------------------------------------------------------------------
int CheckBatteryChargeRate(float measuredChargeRateUnderTest,void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float), void (*Fn_Ptr_PrintMessage)(char[]))
{
  int batteryChargeRateStatus = 1;
  char message[75] = "Battery parameter under test is Charge rate";
  Fn_Ptr_PrintMessage(message);
  if(ValidateIfBatteryParameterValueIsGreaterThanMaxOperatingLimit(MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE,measuredChargeRateUnderTest,Fn_Ptr_PrintMessageWithBreachLevel ) )
  {
    batteryChargeRateStatus = 0;
  }
  return batteryChargeRateStatus;
}
