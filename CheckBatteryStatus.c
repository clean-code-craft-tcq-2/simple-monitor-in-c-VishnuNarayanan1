#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "BatteryParametersUnderTest.h"
#include "CheckToleranceLimit.h"

int CheckBatteryStatus(void (*FnPtrPrintMsgOnConsoleWithBreachLevel)(char[], float))
{
  float valueRead;
  int batteryParameter = 0, OverallbatteryStatus = 0, batteryStatus = 0;
  while(batteryParameter < MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED)
  {
    valueRead = BatteryParamInfo[batteryParameter].ReadBatteryParameters();
  // CheckIfToleranceToBeChecked(batteryParameter,MessageToBePrinted[batteryParameter], valueRead, BatteryParamInfo[batteryParameter].MinimumThreshold,
                                  // BatteryParamInfo[batteryParameter].MaximumThreshold,BatteryParamInfo[batteryParameter].ToleranceLimit ,FnPtrPrintMsgOnConsoleWithBreachLevel);
    
    batteryStatus = CheckBatteryParameterLimits(MessageToBePrinted[batteryParameter], valueRead, BatteryParamInfo[batteryParameter].MinimumThreshold,
                                                BatteryParamInfo[batteryParameter].MaximumThreshold,FnPtrPrintMsgOnConsoleWithBreachLevel);
    OverallbatteryStatus = (OverallbatteryStatus | batteryStatus);
    batteryParameter++;
  }
  
  return OverallbatteryStatus;
}
