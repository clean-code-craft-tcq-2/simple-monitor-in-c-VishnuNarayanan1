#ifdef PRODUCTION_ENVIRONMENT
#include <stdio.h>
#include <BatteryPrametersConfiguration.h>
#include <PrintOnConsole.h>

int main()
{
    while(1)
    {   
        if(!CheckBatteryStatus())
        {
        }
        else
        {
          exit(0);
        }    
    }
}


int checkBatteryStatus(void)
{
  float valueRead;
  void Fn_Ptr_PrintMessageOnConsoleWithBreachLevel(char[], float) = PrintMessageOnConsoleWithBreachLevel;
  void Fn_Ptr_PrintMessageOnConsole(char[]) = PrintMessageOnConsole;
  int batteryParametersUnderTest = 0;
  int OverallbatteryStatus = 0;
  for(batteryParametersUnderTest < MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED)
  {
    valueRead = batteryInputAndValidationDetails[batteryParametersUnderTest].ReadBatteryParameters();
    batteryStatus = batteryInputAndValidationDetails[batteryParametersUnderTest].ValidateBatteryParametersRead(valueRead,Fn_Ptr_PrintMessageOnConsoleWithBreachLevel,Fn_Ptr_PrintMessageOnConsole);
    OverallbatteryStatus = (OverallbatteryStatus | batteryStatus);
  }
  return OverallbatteryStatus;
}
#endif
