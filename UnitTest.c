#include <stdio.h>

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
