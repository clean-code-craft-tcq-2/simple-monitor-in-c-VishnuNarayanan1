#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "BatteryParametersUnderTest.h"
#include "ValidateBatteryParameterLimits.h"

int CheckBatteryParameterLimits(char message[],float measuredBatteryParam,float minLimit, float maxLimit, void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float))
{
  int batteryParameterStatus = 1;
  char breachMessageMin[75] = "Battery parameter under test is less than minimum threshold limit by ";
  char breachMessageMax[75] = "Battery parameter under test is greater than maximum threshold limit by ";
  Fn_Ptr_PrintMessageWithBreachLevel(message,BREACH_LEVEL_NEED_NOT_BE_PRINTED);
  if(ValidateBatteryParamMinLimit(minLimit, measuredBatteryParam, breachMessageMin, Fn_Ptr_PrintMessageWithBreachLevel) 
    && ValidateBatteryParamMaxLimit(maxLimit, measuredBatteryParam, breachMessageMax, Fn_Ptr_PrintMessageWithBreachLevel))
  {
    batteryParameterStatus = 0;
  }
  return batteryParameterStatus;
}

