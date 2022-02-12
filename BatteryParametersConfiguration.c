#include "BatteryParametersConfiguration.h"
#include "ParametersReadFromSensor.h"
#include "BatteryParametersUnderTest.h"

struct batteryParam_st batteryInputAndValidationDetails[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED] =
{
  {.MinimumThresholdLimit = MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,
   .MaximumThresholdLimit = MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,
   .ToleranceLimit = TOLERANCE_PERCENTAGE_LIMIT_BATTERY_TEMPERATURE,
    .ToleranceWarningRequiredOrNot = TOLERANCE_WARNING_REQUIRED,
    .ReadBatteryParameters = &ReadBatteryTemperature, 
   },
  {.MinimumThresholdLimit = MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE,
   .MaximumThresholdLimit = MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE,
   .ToleranceLimit = TOLERANCE_PERCENTAGE_LIMIT_BATTERY_STATE_OF_CHARGE,
   .ToleranceWarningRequiredOrNot = TOLERANCE_WARNING_REQUIRED,
   .ReadBatteryParameters = &ReadBatteryStateOfCharge,
   },
  { .MinimumThresholdLimit = MIN_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE,
    .MaximumThresholdLimit = MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE,
   .ToleranceLimit = TOLERANCE_PERCENTAGE_LIMIT_BATTERY_CHARGE_RATE,
   .ToleranceWarningRequiredOrNot = TOLERANCE_WARNING_NOT_REQUIRED,
    .ReadBatteryParameters = &ReadBateryChargeRate,
   }
};

char messageToBePrintedForBatteryParameterValidation[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED][100] =
{
  "Battery parameter under test is Temperature",
  "Battery parameter under test is State Of Charge (SOC)",
  "Battery parameter under test is Charge rate"
};
