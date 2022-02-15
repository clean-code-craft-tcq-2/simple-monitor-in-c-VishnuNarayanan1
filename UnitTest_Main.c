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
    printf("\n-------Language : English  , Temperature unit : Celcius--------------------------\n");
  LanguageChoosen = English;
  tempUnit  = Celcius;
   // Test if temperature, SOC and charge rate are within permissible range
   Test_BatteryStatus(25,50,0.5,0,0,3); 
   // Test if temperature, SOC and charge rate all are exactly in the upper boundary of the permissible range 
   Test_BatteryStatus(45,80,0.8,0,0,6);
   // Test if temperature, SOC and charge rate all are exactly in the lower boundary of the permissible range 
   Test_BatteryStatus(0,20,0.2,0,0,9);
   // Test if temperature is below the lower boundary of the permissible range , SOC and charge rate are within permissible range
   Test_BatteryStatus(-10,20,0.5,1,1,12);
   // Test if SOC is below the lower boundary of the permissible range , temperature and charge rate are within permissible range
   Test_BatteryStatus(25,10,0.5,1,2,15);
   // Test if charge rate is below the lower boundary of the permissible range , temperature and SOC are within permissible range
   Test_BatteryStatus(25,50,0.1,1,3,18);
    // Test if temperature and SOC are below the lower boundary of the permissible range , charge rate is within permissible range
   Test_BatteryStatus(-20,-10,0.5,1,5,21);
   // Test if SOC and charge rate are below the lower boundary of the permissible range , temperature is within permissible range
   Test_BatteryStatus(25,-10,0,1,7,24);
    // Test if temperature and charge rate are below the lower boundary of the permissible range , SOC is within permissible range
   Test_BatteryStatus(-1,50,-1,1,9,27);
    // Test if temperature, SOC and charge rate all are below the lower boundary of the permissible range
   Test_BatteryStatus(0,0,0,1,11,30);
     // Test if temperature is above the upper boundary of the permissible range , SOC and charge rate are within permissible range
   Test_BatteryStatus(46,50,0.5,1,12,33);
   // Test if SOC is above the upper boundary of the permissible range , temperature and charge rate are within permissible range
   Test_BatteryStatus(25,81,0.5,1,13,36);
   // Test if charge rate is above the upper boundary of the permissible range , temperature and SOC are within permissible range
   Test_BatteryStatus(25,50,0.9,1,14,39);
    // Test if temperature and SOC are above the upper boundary of the permissible range , charge rate is within permissible range
   Test_BatteryStatus(100,100,0.5,1,16,42);
   // Test if SOC and charge rate are above the upper boundary of the permissible range , temperature is within permissible range
   Test_BatteryStatus(25,100,100,1,18,45);
    // Test if temperature and charge rate are above the upper boundary of the permissible range , SOC is within permissible range
   Test_BatteryStatus(200,50,10,1,20,48);
    // Test if temperature, SOC and charge rate all are upper the lower boundary of the permissible range
   Test_BatteryStatus(100,100,100,1,23,51);
  
   printf("\n-------Language : German  , Temperature unit : Farenheit--------------------------\n");
   LanguageChoosen = German;
   tempUnit = Farenheit;
   // Test if temperature, SOC and charge rate are within permissible range
   Test_BatteryStatus(77,50,0.5,0,23,54); 
   // Test if temperature, SOC and charge rate all are exactly in the upper boundary of the permissible range 
   Test_BatteryStatus(113,80,0.8,0,23,57);
   // Test if temperature, SOC and charge rate all are exactly in the lower boundary of the permissible range 
   Test_BatteryStatus(32,20,0.2,0,23,60);
   // Test if temperature is below the lower boundary of the permissible range , SOC and charge rate are within permissible range
   Test_BatteryStatus(14,20,0.5,1,24,63);   
    // Test if temperature and SOC are below the lower boundary of the permissible range , charge rate is within permissible range
   Test_BatteryStatus(-4,-10,0.5,1,26,66); 
    // Test if temperature and charge rate are below the lower boundary of the permissible range , SOC is within permissible range
   Test_BatteryStatus(30.2,50,-1,1,28,69);
    // Test if temperature, SOC and charge rate all are below the lower boundary of the permissible range
   Test_BatteryStatus(32,0,0,1,30,72);
     // Test if temperature is above the upper boundary of the permissible range , SOC and charge rate are within permissible range
   Test_BatteryStatus(114.8,50,0.5,1,31,75);
    // Test if temperature and SOC are above the upper boundary of the permissible range , charge rate is within permissible range
   Test_BatteryStatus(212,100,0.5,1,33,78);
    // Test if temperature and charge rate are above the upper boundary of the permissible range , SOC is within permissible range
   Test_BatteryStatus(392,50,10,1,35,81);
    // Test if temperature, SOC and charge rate all are upper the lower boundary of the permissible range
   Test_BatteryStatus(212,100,100,1,38,84);
}

void Test_BatteryStatus(float temperature, float SOC , float ChargeRate, int batteryStatusToAssert, int NumOfPrintMessagesWithBreachToAssert, int NumOfPrintMessagesToAssert)
{
  int batteryStatus;
  void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float) = PrintMessageOnConsoleWithBreachLevel_Stub;
  TemperatureFromSensorMock = temperature;
  SOCFromSensorMock = SOC;
  ChargeRateFromSensorMock = ChargeRate;
  batteryStatus = CheckBatteryStatus(Fn_Ptr_PrintMessageOnConsoleWithBreachLevel);
  printf("\n%d",batteryStatus);
   printf("\n%d",Test_PrintOnConsoleWithBreachLevel);
   printf("\n%d",Test_PrintOnConsole);
  assert(batteryStatus == batteryStatusToAssert);
  assert(NumOfPrintMessagesWithBreachToAssert == Test_PrintOnConsoleWithBreachLevel);
  assert(NumOfPrintMessagesToAssert == Test_PrintOnConsole); 
}
#endif
