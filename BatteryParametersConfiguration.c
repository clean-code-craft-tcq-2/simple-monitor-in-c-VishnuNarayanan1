#include "BatteryParametersConfiguration.h"
#include "ParametersReadFromSensor.h"
#include "BatteryParametersUnderTest.h"

struct batteryParam_st batteryInputAndValidationDetails[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED] =
{
  {.ReadBatteryParameters = &ReadBatteryTemperature, 
   .ValidateBatteryParametersRead = &CheckBatteryTemperature
   },
  {.ReadBatteryParameters = &ReadBatteryStateOfCharge,
   .ValidateBatteryParametersRead = &CheckBatteryStateOfCharge
   },
  {.ReadBatteryParameters = &ReadBateryChargeRate,
   .ValidateBatteryParametersRead = &CheckBatteryChargeRate
   }
};
