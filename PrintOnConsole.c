#include <stdio.h>
#include "PrintOnConsole.h"
#include "BatteryParametersConfiguration.h"

void PrintMessageOnConsoleWithBreachLevel(char messageToBePrinted[], float breachLevel)
{
  if(breachLevel == BREACH_LEVEL_NEED_NOT_BE_PRINTED)
  {
      printf("\n%s\n",messageToBePrinted);
  }
  else
  {
    printf("%s %.1f",messageToBePrinted,breachLevel);
  }
}
