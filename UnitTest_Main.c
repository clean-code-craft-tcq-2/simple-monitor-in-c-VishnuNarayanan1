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
  if(breachLevel == BREACH_LEVEL_NEED_NOT_BE_PRINTED)
  {
      printf("\n%s\n",messageToBePrinted);
      Test_PrintOnConsole++;
  }
  else
  {
      printf("\n%s %.1f\n",messageToBePrinted,breachLevel);
     Test_PrintOnConsoleWithBreachLevel++;
  }

}

int main()
{
   // Test if temperature, SOC and charge rate are within permissible range
   Test_BatteryStatus(25,50,0.5,0,0,4); 
   // Test if temperature, SOC and charge rate all are exactly in the upper boundary of the permissible range 
   Test_BatteryStatus(45,80,0.8,0,0,8);
   // Test if temperature, SOC and charge rate all are exactly in the lower boundary of the permissible range 
   Test_BatteryStatus(0,20,0.2,0,0,12);
   // Test if temperature is below the lower boundary of the permissible range , SOC and charge rate are within permissible range
   Test_BatteryStatus(-10,20,0.5,1,1,16);
   // Test if SOC is below the lower boundary of the permissible range , temperature and charge rate are within permissible range
   Test_BatteryStatus(25,10,0.5,1,2,20);
   // Test if charge rate is below the lower boundary of the permissible range , temperature and SOC are within permissible range
   Test_BatteryStatus(25,50,0.1,1,3,24);
    // Test if temperature and SOC are below the lower boundary of the permissible range , charge rate is within permissible range
   Test_BatteryStatus(-20,-10,0.5,1,5,28);
   // Test if SOC and charge rate are below the lower boundary of the permissible range , temperature is within permissible range
   Test_BatteryStatus(25,-10,0,1,7,32);
    // Test if temperature and charge rate are below the lower boundary of the permissible range , SOC is within permissible range
   Test_BatteryStatus(-1,50,-1,1,9,36);
    // Test if temperature, SOC and charge rate all are below the lower boundary of the permissible range
   Test_BatteryStatus(0,0,0,1,11,40);
     // Test if temperature is above the upper boundary of the permissible range , SOC and charge rate are within permissible range
   Test_BatteryStatus(46,50,0.5,1,12,44);
   // Test if SOC is above the upper boundary of the permissible range , temperature and charge rate are within permissible range
   Test_BatteryStatus(25,81,0.5,1,13,48);
   // Test if charge rate is above the upper boundary of the permissible range , temperature and SOC are within permissible range
   Test_BatteryStatus(25,50,0.9,1,14,52);
    // Test if temperature and SOC are above the upper boundary of the permissible range , charge rate is within permissible range
   Test_BatteryStatus(100,100,0.5,1,16,56);
   // Test if SOC and charge rate are above the upper boundary of the permissible range , temperature is within permissible range
   Test_BatteryStatus(25,100,100,1,18,60);
    // Test if temperature and charge rate are above the upper boundary of the permissible range , SOC is within permissible range
   Test_BatteryStatus(200,50,10,1,20,64);
    // Test if temperature, SOC and charge rate all are upper the lower boundary of the permissible range
   Test_BatteryStatus(100,100,100,1,23,68);
}

void Test_BatteryStatus(float temperature, float SOC , float ChargeRate, int batteryStatusToAssert, int NumOfPrintMessagesWithBreachToAssert, int NumOfPrintMessagesToAssert)
{
  int batteryStatus;
  void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float) = PrintMessageOnConsoleWithBreachLevel_Stub;
  TemperatureFromSensorMock = temperature;
  SOCFromSensorMock = SOC;
  ChargeRateFromSensorMock = ChargeRate;
  batteryStatus = CheckBatteryStatus(Fn_Ptr_PrintMessageOnConsoleWithBreachLevel);
  assert(batteryStatus == batteryStatusToAssert);
  assert(NumOfPrintMessagesWithBreachToAssert == Test_PrintOnConsoleWithBreachLevel);
  assert(NumOfPrintMessagesToAssert == Test_PrintOnConsole);
}
#endif
