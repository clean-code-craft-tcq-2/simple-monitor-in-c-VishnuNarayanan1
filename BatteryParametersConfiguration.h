#define UNIT_TEST_ENVIRONMENT
#define MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE         (0)
#define MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE         (45)
#define MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE     (20)
#define MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE     (80)
#define MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE         (0.8)
#define MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED          (3)

typedef float (*Fn_Ptr_ReadBatteryParameters)(void);
typedef int (*Fn_Ptr_ValidateBatteryParametersRead)(float, void (*Fn_Ptr_PrintMessage)(const char[]),void (*Fn_Ptr_PrintMessageWithBreachLevel)(const char[],float));

struct batteryParam_st 
{
  Fn_Ptr_ReadBatteryParameters ReadBatteryParameters;
  Fn_Ptr_ValidateBatteryParametersRead ValidateBatteryParametersRead;
};

extern batteryParam_st batteryInputAndValidationDetails[];
