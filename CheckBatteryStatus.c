#include <stdio.h>
#include <string.h>
#include "BatteryParametersConfiguration.h"
#include "BatteryParametersUnderTest.h"

int CheckBatteryStatus(void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float))
{
  float valueRead;
  int batteryParameter = 0, OverallbatteryStatus = 0, batteryStatus = 0;
  char successMessage[75] = "Battery status is safe !!!";
  char failureMessage[75] = "Battery status is unsafe, call service person !!!";
  char messageToBePrintedOnConsole[100];
  while(batteryParameter < MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED)
  {
    strcpy(messageToBePrintedOnConsole, messageToBePrinted[batteryParameter]);
    valueRead = batteryParamInfo[batteryParametersUnderTest].ReadBatteryParameters();
    batteryStatus = CheckBatteryParameterLimits(messageToBePrintedOnConsole, valueRead, batteryParamInfo[batteryParameter].MinimumThreshold,
                                                batteryParamInfo[batteryParameter].MaximumThreshold,Fn_Ptr_PrintMessageOnConsoleWithBreachLevel);
    OverallbatteryStatus = (OverallbatteryStatus | batteryStatus);
    batteryParameter++;
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
