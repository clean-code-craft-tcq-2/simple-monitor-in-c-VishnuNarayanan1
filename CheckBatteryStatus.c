#include <stdio.h>
#include "BatteryParametersConfiguration.h"

int CheckBatteryStatus(void)
{
  float valueRead;
  void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float) = PrintMessageOnConsoleWithBreachLevel;
  void (*Fn_Ptr_PrintMessageOnConsole)(char[]) = PrintMessageOnConsole;
  int batteryParametersUnderTest = 0;
  int OverallbatteryStatus = 0;
  int batteryStatus = 0;
  while(batteryParametersUnderTest < MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED)
  {
    valueRead = batteryInputAndValidationDetails[batteryParametersUnderTest].ReadBatteryParameters();
    batteryStatus = batteryInputAndValidationDetails[batteryParametersUnderTest].ValidateBatteryParametersRead(valueRead,Fn_Ptr_PrintMessageOnConsoleWithBreachLevel,Fn_Ptr_PrintMessageOnConsole);
    OverallbatteryStatus = (OverallbatteryStatus | batteryStatus);
    batteryParametersUnderTest++;
  }
  return OverallbatteryStatus;
}
