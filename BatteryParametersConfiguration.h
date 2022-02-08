#define UNIT_TEST_ENVIRONMENT
#define MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE         (0)
#define MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE         (45)
#define MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE     (20)
#define MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE     (80)
#define MIN_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE         (0.2)
#define MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE         (0.8)
#define MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED          (3)
#define BREACH_LEVEL_NEED_NOT_BE_PRINTED                (0xffffff)

typedef float (*Fn_Ptr_ReadBatteryParameters)(void);

struct batteryParam_st 
{
  float MinimumThresholdLimit;
  float MaximumThresholdLimit;
  Fn_Ptr_ReadBatteryParameters ReadBatteryParameters;  
};

extern struct batteryParam_st batteryInputAndValidationDetails[];
extern char messageToBePrintedForBatteryParameterValidation[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED][100];
