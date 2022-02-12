#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "BatteryParametersUnderTest.h"

int CheckBatteryStatus(void (*FnPtrPrintMsgOnConsoleWithBreachLevel)(char[], float))
{
  float valueRead;
  int batteryParameter = 0, OverallbatteryStatus = 0, batteryStatus = 0;
  char successMessage[75] = "Battery status is safe !!!";
  char failureMessage[75] = "Battery status is unsafe, call service person !!!";
  while(batteryParameter < MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED)
  {
    valueRead = BatteryParamInfo[batteryParameter].ReadBatteryParameters();
    if(BatteryParamInfo[batteryParameter].ToleranceWarningRequiredOrNot == TOLERANCE_WARNING_REQUIRED)
    {
      CheckBatteryToleranceLimits(MessageToBePrinted[batteryParameter], valueRead, BatteryParamInfo[batteryParameter].MinimumThreshold,
                                   BatteryParamInfo[batteryParameter].MaximumThreshold,FnPtrPrintMsgOnConsoleWithBreachLevel);
    }
    batteryStatus = CheckBatteryParameterLimits(MessageToBePrinted[batteryParameter], valueRead, BatteryParamInfo[batteryParameter].MinimumThreshold,
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
