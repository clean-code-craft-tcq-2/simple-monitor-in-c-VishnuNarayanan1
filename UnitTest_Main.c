#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "ParametersReadFromSensor.h"
#include "BatteryParametersUnderTest.h"
#include "PrintOnConsole.h"
#include "CheckBatteryStatus.h"

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

int main()
{
  void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float) = PrintMessageOnConsoleWithBreachLevel_Stub;
  void (*Fn_Ptr_PrintMessageOnConsole)(char[]) = PrintMessageOnConsole_Stub;
  
  TemperatureFromSensorMock = 100;
  SOCFromSensorMock = 30;
  ChargeRateFromSensorMock = 0.9;
  CheckBatteryStatus(Fn_Ptr_PrintMessageOnConsoleWithBreachLevel,Fn_Ptr_PrintMessageOnConsole);
}

#endif
