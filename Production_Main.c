#ifdef PRODUCTION_ENVIRONMENT
#include <stdio.h>
#include "BatteryPrametersConfiguration.h"
#include "PrintOnConsole.h"
#include "CheckBatteryStatus.h"

int main()
{
  void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float) = PrintMessageOnConsoleWithBreachLevel;
  void (*Fn_Ptr_PrintMessageOnConsole)(char[]) = PrintMessageOnConsole;
    while(1)
    {   
        if(!CheckBatteryStatus(Fn_Ptr_PrintMessageOnConsoleWithBreachLevel,Fn_Ptr_PrintMessageOnConsole))
        {
        }
        else
        {
          exit(0);
        }    
    }
}
