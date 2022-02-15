#include "BatteryParametersConfiguration.h"
#include "ParametersReadFromSensor.h"
#include "BatteryParametersUnderTest.h"

struct BatteryParam_st BatteryParamInfo[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED] =
{
  {.MinimumThreshold = MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,
   .MaximumThreshold = MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE,
    .ReadBatteryParameters = &ReadBatteryTemperature, 
   },
  {.MinimumThreshold = MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE,
   .MaximumThreshold = MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE,
   .ReadBatteryParameters = &ReadBatteryStateOfCharge,
   },
  { .MinimumThreshold = MIN_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE,
    .MaximumThreshold = MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE,
    .ReadBatteryParameters = &ReadBateryChargeRate,
   }
};

char MessageToBePrinted[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED * MAX_POSSIBLE_LANGUAGES][100] =
{"Battery parameter under test is Temperature", "Der zu testende Batterieparameter ist Temperatur",
"Battery parameter under test is State Of Charge (SOC)", "Der zu testende Batterieparameter ist der Ladezustand (SOC)",
"Battery parameter under test is Charge rate", "Der zu testende Batterieparameter ist die Laderate"};


char BreachMessage[2 * MAX_POSSIBLE_LANGUAGES][100] =
{"Battery parameter under test is less than minimum threshold limit by ","Der zu testende Batterieparameter ist kleiner als der minimale Schwellenwert um",
 "Battery parameter under test is greater than maximum threshold limit by ","Der zu testende Batterieparameter ist größer als der maximale Schwellenwert um"};

enum languages LanguageChoosen = German;
enum temperatureUnit tempUnit = Farenheit;
