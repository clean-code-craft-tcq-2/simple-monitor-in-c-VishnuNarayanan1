#include <stdbool.h>

#define UNIT_TEST_ENVIRONMENT
#define MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE           (0)
#define MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE           (45)
#define TOLERANCE_PERCENTAGE_LIMIT_BATTERY_TEMPERATURE    (5)
#define MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE       (20)
#define MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE       (80)
#define TOLERANCE_PERCENTAGE_LIMIT_BATTERY_STATE_OF_CHARGE (5)
#define MIN_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE           (0.2)
#define MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE           (0.8)
#define MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED            (3)
#define TOLERANCE_PERCENTAGE_LIMIT_BATTERY_CHARGE_RATE    (0xffffff)
#define BREACH_LEVEL_NEED_NOT_BE_PRINTED                  (0xffffff)
#define TOLERANCE_WARNING_REQUIRED                        (true)
#define TOLERANCE_WARNING_NOT_REQUIRED                    (false)

typedef float (*FnPtrReadBatteryParam)(void);

struct BatteryParam_st 
{
  float MinimumThreshold;
  float MaximumThreshold;
  float ToleranceLimit;
  bool ToleranceWarningRequiredOrNot;
  FnPtrReadBatteryParam ReadBatteryParameters;  
};

extern struct BatteryParam_st BatteryParamInfo[];
extern char MessageToBePrinted[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED][100];
