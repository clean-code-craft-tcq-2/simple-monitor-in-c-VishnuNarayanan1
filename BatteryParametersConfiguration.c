#include <BatteryParametersConfiguration.h>
#include <ParametersReadFromSensor.h>
#include <BatteryParametersUnderTest.h>

batteryParam_st batteryInputAndValidationDetails[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED] =
{
  {&ReadBatteryTemperature, &CheckBatteryTemperature},
  {&ReadBatteryStateOfCharge,&CheckBatteryStateOfCharge},
  {&ReadBateryChargeRate,&CheckBatteryChargeRate}
}
