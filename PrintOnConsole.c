#include <stdio.h>
#include "PrintOnConsole.h"

void PrintMessageOnConsoleWithBreachLevel(char messageToBePrinted[], float breachLevel)
{
  printf("%s %.1f",messageToBePrinted,breachLevel);
}

void PrintMessageOnConsole(char messageToBePrinted[])
{
  printf("\n%s\n",messageToBePrinted);
}
