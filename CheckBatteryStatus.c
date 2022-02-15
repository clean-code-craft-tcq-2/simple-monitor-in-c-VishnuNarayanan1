#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "BatteryParametersUnderTest.h"

int CheckBatteryStatus(void (*FnPtrPrintMsgOnConsoleWithBreachLevel)(char[], float))
{
  ValueLimits_st valueLimits;
  int batteryParameter = 0, OverallbatteryStatus = 0, batteryStatus = 0;
  while(batteryParameter < MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED)
  {
    valueLimits = ReadBatteryParameters[batteryParameter].FnPtrReadBatteryParam ();
    batteryStatus = CheckBatteryParameterLimits(MessageToBePrinted[(batteryParameter * MAX_POSSIBLE_LANGUAGES) + LanguageChoosen], valueLimits.Value, valueLimits.MinLimit,
                                                valueLimits.MaxLimit,FnPtrPrintMsgOnConsoleWithBreachLevel);
    OverallbatteryStatus = (OverallbatteryStatus | batteryStatus);
    batteryParameter++;
  }
  
  return OverallbatteryStatus;
}
