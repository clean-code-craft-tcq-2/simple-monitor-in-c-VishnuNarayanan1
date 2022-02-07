#include <stdio.h>
#include <BatteryParametersConfiguration.h>
#include <ParametersReadFromSensor.h>
#include <BatteryParametersUnderTest.h>

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

#endif
