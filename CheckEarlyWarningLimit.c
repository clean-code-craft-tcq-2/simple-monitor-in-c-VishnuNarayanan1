#include <stdio.h>

float ReturnToleranceLimit(float tolerancePercentage,  float batteryParameterValue)
{
  return (batteryParameterValue * tolerancePercentage * 0.01)
}
