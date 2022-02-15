#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "BatteryParametersUnderTest.h"

int CheckBatteryStatus(void (*FnPtrPrintMsgOnConsoleWithBreachLevel)(char[], float))
{
  ValueLimits paramValues;
  int batteryParameter = 0, OverallbatteryStatus = 0, batteryStatus = 0;
  while(batteryParameter < MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED)
  {
    paramValues = ReadBatteryParameters[batteryParameter].FnPtrReadBatteryParam ();
    batteryStatus = CheckBatteryParameterLimits(MessageToBePrinted[(batteryParameter * MAX_POSSIBLE_LANGUAGES) + LanguageChoosen], paramValues.Value, paramValues.MinLimit,
                                                paramValues.MaxLimit,FnPtrPrintMsgOnConsoleWithBreachLevel);
    OverallbatteryStatus = (OverallbatteryStatus | batteryStatus);
    batteryParameter++;
  }
  
  return OverallbatteryStatus;
}
