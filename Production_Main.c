#ifdef PRODUCTION_ENVIRONMENT
#include <stdio.h>
#include "BatteryPrametersConfiguration.h"
#include "PrintOnConsole.h"
#include "CheckBatteryStatus.h"

int main()
{
  void (*Fn_Ptr_PrintMessageOnConsoleWithBreachLevel)(char[], float) = PrintMessageOnConsoleWithBreachLevel;
   while(1)
    {   
        if(!CheckBatteryStatus(Fn_Ptr_PrintMessageOnConsoleWithBreachLevel))
        {
        }
        else
        {
          exit(0);
        }    
    }
}

#endif
