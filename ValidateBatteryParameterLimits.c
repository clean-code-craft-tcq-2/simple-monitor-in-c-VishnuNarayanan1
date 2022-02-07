#include <stdio.h>
#include "ValidateBatteryParameterLimits.h"

int ValidateIfBatteryParameterValueIsLessThanMinOperatingLimit(float minOperatingLimitOfBatteryParameter,  float batteryParameterValue, void (*Fn_Ptr)(char[],float))
{
   int batteryParameterIsInSafeState = 1;
   float ParameterBreachLevel;
   char breachMessage[75] = "Battery parameter under test is less than minimum threshold limit by ";
   if(batteryParameterValue < minOperatingLimitOfBatteryParameter)
   {
     batteryParameterIsInSafeState = 0;
     ParameterBreachLevel =  (minOperatingLimitOfBatteryParameter - batteryParameterValue);
     Fn_Ptr(breachMessage,ParameterBreachLevel);
   }
   return (batteryParameterIsInSafeState);
}

int ValidateIfBatteryParameterValueIsGreaterThanMaxOperatingLimit(float maxOperatingLimitOfBatteryParameter,  float batteryParameterValue, void (*Fn_Ptr)(char[],float))
{
   int batteryParameterIsInSafeState = 1;
   float ParameterBreachLevel;
   char breachMessage[75] = "Battery parameter under test is greater than maximum threshold limit by ";
   if(batteryParameterValue > maxOperatingLimitOfBatteryParameter)
   {
     batteryParameterIsInSafeState = 0;
      ParameterBreachLevel = (batteryParameterValue - maxOperatingLimitOfBatteryParameter);
      Fn_Ptr(breachMessage,ParameterBreachLevel);
   }
   return (batteryParameterIsInSafeState);
}

