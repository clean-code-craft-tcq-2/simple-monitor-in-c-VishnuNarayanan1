#include <stdio.h>
#include <assert.h>
#include "BatteryParametersConfiguration.h"
#include "ParametersReadFromSensor.h"
#include "BatteryParametersUnderTest.h"
#include "PrintOnConsole.h"
#include "CheckBatteryStatus.h"

#ifdef UNIT_TEST_ENVIRONMENT

void Test_BatteryStatus(float temperature, float SOC , float ChargeRate, int batteryStatusToAssert, int NumOfPrintMessagesWithBreachToAssert, int NumOfPrintMessagesToAssert);

int Test_PrintOnConsoleWithBreachLevel = 0;
int Test_PrintOnConsole = 0;

void PrintMessageOnConsoleWithBreachLevel_Stub(char messageToBePrinted[], float breachLevel)
{
  printf("\n%s %.1f\n",messageToBePrinted,breachLevel);
  Test_PrintOnConsoleWithBreachLevel++;
}

void PrintMessageOnConsole_Stub(char messageToBePrinted[])
{
  printf("\n%s\n",messageToBePrinted);
  Test_PrintOnConsole++;
}

int main()
{
   // Test if temperature, SOC and charge rate are within permissible range
   Test_BatteryStatus(25,50,0.5,0,0,4); 
   // Test if temperature, SOC and charge rate all are in the upper boundary of the permissible range 
   Test_BatteryStatus(45,80,0.8,0,0,8);
   // Test if temperature, SOC and charge rate all are in the lower boundary of the permissible range 
   Test_BatteryStatus(0,20,0.8,0,0,12);
   // Test if temperature is below the lower boundary of the permissible range , SOC and charge rate are within permissible range
   Test_BatteryStatus(-10,20,0.8,1,0,12);
}

void Test_BatteryStatus(float temperature, float SOC , float ChargeRate, int batteryStatusToAssert, int NumOfPrintMessagesWithBreachToAssert, int NumOfPrintMessagesToAssert)
{
  int batteryStatus;
  void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float) = PrintMessageOnConsoleWithBreachLevel_Stub;
  void (*Fn_Ptr_PrintMessageOnConsole)(char[]) = PrintMessageOnConsole_Stub;
  TemperatureFromSensorMock = temperature;
  SOCFromSensorMock = SOC;
  ChargeRateFromSensorMock = ChargeRate;
  batteryStatus = CheckBatteryStatus(Fn_Ptr_PrintMessageOnConsoleWithBreachLevel,Fn_Ptr_PrintMessageOnConsole);
  assert(batteryStatus == batteryStatusToAssert);
  printf("\n%d\n",Test_PrintOnConsoleWithBreachLevel);
   printf("\n%d\n",Test_PrintOnConsole);
 // assert(NumOfPrintMessagesWithBreachToAssert == Test_PrintOnConsoleWithBreachLevel);
 // assert(NumOfPrintMessagesToAssert == Test_PrintOnConsole);
}
#endif
