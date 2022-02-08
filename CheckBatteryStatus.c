#include <stdio.h>
#include <string.h>
#include "BatteryParametersConfiguration.h"
#include "BatteryParametersUnderTest.h"

int CheckBatteryStatus(void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float))
{
  float valueRead;
  int batteryParametersUnderTest = 0;
  int OverallbatteryStatus = 0;
  int batteryStatus = 0;
  char successMessage[75] = "Battery status is safe !!!";
  char failureMessage[75] = "Battery status is unsafe, call service person !!!";
  char messageToBePrinted[100];
  while(batteryParametersUnderTest < MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED)
  {
    strcpy(messageToBePrinted, messageToBePrintedForBatteryParameterValidation[batteryParametersUnderTest]);
    valueRead = batteryInputAndValidationDetails[batteryParametersUnderTest].ReadBatteryParameters();
    batteryStatus = CheckBatteryParameterLimits(messageToBePrinted, valueRead, batteryInputAndValidationDetails[batteryParametersUnderTest].MinimumThresholdLimit,
                                                batteryInputAndValidationDetails[batteryParametersUnderTest].MaximumThresholdLimit,Fn_Ptr_PrintMessageOnConsoleWithBreachLevel);
    OverallbatteryStatus = (OverallbatteryStatus | batteryStatus);
    batteryParametersUnderTest++;
  }
  if(OverallbatteryStatus)
  {
     Fn_Ptr_PrintMessageOnConsoleWithBreachLevel(failureMessage,BREACH_LEVEL_NEED_NOT_BE_PRINTED);
  }
  else
  {
      Fn_Ptr_PrintMessageOnConsoleWithBreachLevel(successMessage,BREACH_LEVEL_NEED_NOT_BE_PRINTED);
  }
  return OverallbatteryStatus;
}
