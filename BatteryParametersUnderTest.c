#include <stdio.h>
#include "BatteryPrametersConfiguration.h"
#include "BatteryParametersUnderTest.h"

//---------------------------------------------------------------------------------------------
/// Battery Temperature under test
///
//---------------------------------------------------------------------------------------------
int CheckBatteryTemperature(float measuredTemperatureValueUnderTest, void (*Fn_Ptr_PrintMessage)(const char[]),void (*Fn_Ptr_PrintMessageWithBreachLevel)(const char[],float) )
{
  int batteryTemperatureStatus = 1;
  const char message[50] = "Battery parameter under test is Temperature";
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
int CheckBatteryStateOfCharge(float measuredStateOfChargeUnderTest, void (*Fn_Ptr_PrintMessage)(const char[]),void (*Fn_Ptr_PrintMessageWithBreachLevel)(const char[],float) )
{
  int batteryStateOfChargeStatus = 1;
  const char message[50] = "Battery parameter under test is State Of Charge (SOC)";
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
int CheckBatteryChargeRate(float measuredChargeRateUnderTest, void (*Fn_Ptr_PrintMessage)(const char[]),void (*Fn_Ptr_PrintMessageWithBreachLevel)(const char[],float) )
{
  int batteryChargeRateStatus = 1;
  const char message[50] = "Battery parameter under test is Charge rate";
  Fn_Ptr_PrintMessage(message);
  if(ValidateIfBatteryParameterValueIsGreaterThanMaxOperatingLimit(MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE,measuredChargeRateUnderTest,Fn_Ptr_PrintMessageWithBreachLevel ) )
  {
    batteryChargeRateStatus = 0;
  }
  return batteryChargeRateStatus;
}
