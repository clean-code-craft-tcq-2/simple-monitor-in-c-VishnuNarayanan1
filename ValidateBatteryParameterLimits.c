#include <stdio.h>
#include "ValidateBatteryParameterLimits.h"

int ValidateBatteryParamMinLimit(float minLimitOfBatteryParameter,  float batteryParameterValue, void (*Fn_Ptr)(char[],float))
{
   int batteryParameterIsInSafeState = 1;
   float ParameterBreachLevel;
   char breachMessage[75] = "Battery parameter under test is less than minimum threshold limit by ";
   if(batteryParameterValue < minLimitOfBatteryParameter)
   {
     batteryParameterIsInSafeState = 0;
     ParameterBreachLevel =  (minLimitOfBatteryParameter - batteryParameterValue);
     Fn_Ptr(breachMessage,ParameterBreachLevel);
   }
   return (batteryParameterIsInSafeState);
}

int ValidateBatteryParamMaxLimit(float maxLimitOfBatteryParameter,  float batteryParameterValue, void (*Fn_Ptr)(char[],float))
{
   int batteryParameterIsInSafeState = 1;
   float ParameterBreachLevel;
   char breachMessage[75] = "Battery parameter under test is greater than maximum threshold limit by ";
   if(batteryParameterValue > maxLimitOfBatteryParameter)
   {
     batteryParameterIsInSafeState = 0;
      ParameterBreachLevel = (batteryParameterValue - maxLimitOfBatteryParameter);
      Fn_Ptr(breachMessage,ParameterBreachLevel);
   }
   return (batteryParameterIsInSafeState);
}

