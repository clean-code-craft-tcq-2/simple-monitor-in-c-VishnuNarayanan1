#include "BatteryParametersConfiguration.h"
#include "ParametersReadFromSensor.h"
#include "BatteryParametersUnderTest.h"

struct BatteryParam_st BatteryParamInfo[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED] =
{
  {.MinimumThreshold = MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,
   .MaximumThreshold = MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,
   .ToleranceLimit = TOLERANCE_PERCENTAGE_LIMIT_BATTERY_TEMPERATURE,
    .ToleranceWarningRequiredOrNot = TOLERANCE_WARNING_REQUIRED,
    .ReadBatteryParameters = &ReadBatteryTemperature, 
   },
  {.MinimumThreshold = MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE,
   .MaximumThreshold = MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE,
   .ToleranceLimit = TOLERANCE_PERCENTAGE_LIMIT_BATTERY_STATE_OF_CHARGE,
   .ToleranceWarningRequiredOrNot = TOLERANCE_WARNING_REQUIRED,
   .ReadBatteryParameters = &ReadBatteryStateOfCharge,
   },
  { .MinimumThreshold = MIN_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE,
    .MaximumThreshold = MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE,
   .ToleranceLimit = TOLERANCE_PERCENTAGE_LIMIT_BATTERY_CHARGE_RATE,
   .ToleranceWarningRequiredOrNot = TOLERANCE_WARNING_NOT_REQUIRED,
    .ReadBatteryParameters = &ReadBateryChargeRate,
   }
};

char MessageToBePrinted[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED * MAX_POSSIBLE_LANGUAGES][100] =
{"Battery parameter under test is Temperature", "Der zu testende Batterieparameter ist Temperatur",
"Battery parameter under test is State Of Charge (SOC)", "Der zu testende Batterieparameter ist der Ladezustand (SOC)",
"Battery parameter under test is Charge rate", "Der zu testende Batterieparameter ist die Laderate"};

enum languages LanguageChoosen = English;
