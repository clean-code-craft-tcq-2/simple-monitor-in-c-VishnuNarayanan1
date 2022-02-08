#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "BatteryParametersUnderTest.h"
#include "ValidateBatteryParameterLimits.h"


int CheckBatteryParameterLimits(char message[],float measuredTemperatureValueUnderTest,float minLimit, float maxLimit, 
                                void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float), void (*Fn_Ptr_PrintMessage)(char[]))
{
  int batteryParameterStatus = 1;
  Fn_Ptr_PrintMessage(message);
  if(ValidateIfBatteryParameterValueIsLessThanMinOperatingLimit(minLimit,measuredTemperatureValueUnderTest,Fn_Ptr_PrintMessageWithBreachLevel) 
    && ValidateIfBatteryParameterValueIsGreaterThanMaxOperatingLimit(maxLimit,measuredTemperatureValueUnderTest,Fn_Ptr_PrintMessageWithBreachLevel))
  {
    batteryParameterStatus = 0;
  }
  return batteryParameterStatus;
}

