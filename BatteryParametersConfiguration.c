#include "BatteryParametersConfiguration.h"
#include "ParametersReadFromSensor.h"
#include "BatteryParametersUnderTest.h"

struct batteryParam_st batteryInputAndValidationDetails[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED] =
{
  {.MinimumThresholdLimit = MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,
   .MaximumThresholdLimit = MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,
    .ReadBatteryParameters = &ReadBatteryTemperature, 
   .ValidateBatteryParametersRead = &CheckBatteryTemperature
   },
  {.MinimumThresholdLimit = MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE,
   .MaximumThresholdLimit = MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE,
    .ReadBatteryParameters = &ReadBatteryStateOfCharge,
   .ValidateBatteryParametersRead = &CheckBatteryStateOfCharge
   },
  { .MinimumThresholdLimit = MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,
    .MaximumThresholdLimit = MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE,
    .ReadBatteryParameters = &ReadBateryChargeRate,
   .ValidateBatteryParametersRead = &CheckBatteryChargeRate
   }
};

char messageToBePrintedForBatteryParameterValidation[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED][100] =
{
  "Battery parameter under test is Temperature",
  "Battery parameter under test is State Of Charge (SOC)",
  "Battery parameter under test is Charge rate"
}
