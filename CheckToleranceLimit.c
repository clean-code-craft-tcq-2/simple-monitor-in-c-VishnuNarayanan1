#include <stdio.h>
#include "CheckToleranceLimit.h"
#include "BatteryParametersConfiguration.h"
#include "ValidateBatteryParameterLimits.h"

int CheckIfToleranceToBeChecked(int batteryParam,char message[],float measuredBatteryParam,float minLimit, float maxLimit, float toleranceLimit, void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float))
{
  int functionStatus = 0;
  if(BatteryParamInfo[batteryParam].ToleranceWarningRequiredOrNot == TOLERANCE_WARNING_REQUIRED)
  {
    functionStatus = CheckBatteryToleranceLimits(message,measuredBatteryParam, minLimit, maxLimit, toleranceLimit, Fn_Ptr_PrintMessageWithBreachLevel);
  }
  return functionStatus;
}
int CheckBatteryToleranceLimits(char message[],float measuredBatteryParam,float minLimit, float maxLimit, float toleranceLimit, void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float))
{
  float toleranceValue;
  int functionStatus = 1;
  char toleranceMessageMin[75] = "Battery parameter under test is less than minimum tolerance limit by ";
  char toleranceMessageMax[75] = "Battery parameter under test is greater than maximum tolerance limit by ";
  toleranceValue = ReturnToleranceLimit(toleranceLimit,maxLimit);
    if(ValidateBatteryParamMinLimit((minLimit + toleranceValue), measuredBatteryParam, toleranceMessageMin, Fn_Ptr_PrintMessageWithBreachLevel) 
    && ValidateBatteryParamMaxLimit((maxLimit - toleranceValue), measuredBatteryParam, toleranceMessageMax, Fn_Ptr_PrintMessageWithBreachLevel))
  {
      functionStatus = 0;
  }
  return functionStatus;
}
float ReturnToleranceLimit(float tolerancePercentage,  float batteryParameterValue)
{
  return (batteryParameterValue * tolerancePercentage * 0.01);
}
