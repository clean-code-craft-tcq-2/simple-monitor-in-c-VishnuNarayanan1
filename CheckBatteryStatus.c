#include <stdio.h>
#include <string.h>
#include "BatteryParametersConfiguration.h"
#include "BatteryParametersUnderTest.h"

int CheckBatteryStatus(void (*FnPtrPrintMsgOnConsoleWithBreachLevel)(char[], float))
{
  float valueRead;
  int batteryParameter = 0, OverallbatteryStatus = 0, batteryStatus = 0;
  char successMessage[75] = "Battery status is safe !!!";
  char failureMessage[75] = "Battery status is unsafe, call service person !!!";
  char messageToBePrintedOnConsole[100];
  while(batteryParameter < MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED)
  {
    strcpy(messageToBePrintedOnConsole, MessageToBePrinted[batteryParameter]);
    valueRead = BatteryParamInfo[batteryParameter].ReadBatteryParameters();
    batteryStatus = CheckBatteryParameterLimits(messageToBePrintedOnConsole, valueRead, BatteryParamInfo[batteryParameter].MinimumThreshold,
                                                BatteryParamInfo[batteryParameter].MaximumThreshold,FnPtrPrintMsgOnConsoleWithBreachLevel);
    OverallbatteryStatus = (OverallbatteryStatus | batteryStatus);
    batteryParameter++;
  }
  if(OverallbatteryStatus)
  {
     FnPtrPrintMsgOnConsoleWithBreachLevel(failureMessage,BREACH_LEVEL_NEED_NOT_BE_PRINTED);
  }
  else
  {
     FnPtrPrintMsgOnConsoleWithBreachLevel(successMessage,BREACH_LEVEL_NEED_NOT_BE_PRINTED);
  }
  return OverallbatteryStatus;
}
