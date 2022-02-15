#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "ValidateBatteryParameterLimits.h"

int ValidateBatteryParamMinLimit(float minLimitOfBatteryParameter,  float batteryParameterValue, char messageToPrint[], void (*Fn_Ptr)(char[],float))
{
   int batteryParameterIsInSafeState = 1;
   float ParameterBreachLevel;
   if(batteryParameterValue < minLimitOfBatteryParameter)
   {
     batteryParameterIsInSafeState = 0;
     ParameterBreachLevel =  (minLimitOfBatteryParameter - batteryParameterValue);
     Fn_Ptr(messageToPrint,ParameterBreachLevel);
   }
   return (batteryParameterIsInSafeState);
}

int ValidateBatteryParamMaxLimit(float maxLimitOfBatteryParameter,  float batteryParameterValue, char messageToPrint[], void (*Fn_Ptr)(char[],float))
{
   int batteryParameterIsInSafeState = 1;
   float ParameterBreachLevel;
   if(batteryParameterValue > maxLimitOfBatteryParameter)
   {
     batteryParameterIsInSafeState = 0;
      ParameterBreachLevel = (batteryParameterValue - maxLimitOfBatteryParameter);
      Fn_Ptr(messageToPrint,ParameterBreachLevel);
   }
   return (batteryParameterIsInSafeState);
}

