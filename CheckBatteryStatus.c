#include <stdio.h>
#include "BatteryParametersConfiguration.h"

int CheckBatteryStatus(void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float),void (*Fn_Ptr_PrintMessageOnConsole)(char[]))
{
  float valueRead;
  int batteryParametersUnderTest = 0;
  int OverallbatteryStatus = 0;
  int batteryStatus = 0;
  char successMessage[75] = "Battery status is safe";
  char failureMessage[75] = "Battery status is unsafe, call service person";
  while(batteryParametersUnderTest < MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED)
  {
    valueRead = batteryInputAndValidationDetails[batteryParametersUnderTest].ReadBatteryParameters();
    batteryStatus = batteryInputAndValidationDetails[batteryParametersUnderTest].ValidateBatteryParametersRead(valueRead,Fn_Ptr_PrintMessageOnConsoleWithBreachLevel,Fn_Ptr_PrintMessageOnConsole);
    OverallbatteryStatus = (OverallbatteryStatus | batteryStatus);
    batteryParametersUnderTest++;
  }
  if(OverallbatteryStatus)
  {
     Fn_Ptr_PrintMessage(failureMessage);
  }
  else
  {
      Fn_Ptr_PrintMessage(successMessage);
  }
  return OverallbatteryStatus;
}
