#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "ParametersReadFromSensor.h"
#include "BatteryParametersUnderTest.h"
int checkBatteryStatus(void);

#ifdef UNIT_TEST_ENVIRONMENT

int Test_PrintOnConsoleWithBreachLevel = 0;
int Test_PrintOnConsole = 0;

void PrintMessageOnConsoleWithBreachLevel_Stub(char messageToBePrinted[], float breachLevel)
{
  Test_PrintOnConsoleWithBreachLevel++;
}

void PrintMessageOnConsole_Stub(char messageToBePrinted[])
{
  Test_PrintOnConsole++;
}

int checkBatteryStatus(void)
{
  float valueRead;
  void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float) = PrintMessageOnConsoleWithBreachLevel_Stub;
  void (*Fn_Ptr_PrintMessageOnConsole)(char[]) = PrintMessageOnConsole_Stub;
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

int main()
{
  checkBatteryStatus();
}

#endif
