#include <stdbool.h>

#define UNIT_TEST_ENVIRONMENT
#define MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE           (0)
#define MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE           (45)
#define MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE       (20)
#define MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE       (80)
#define MIN_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE           (0.2)
#define MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE           (0.8)
#define MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED            (3)
#define BREACH_LEVEL_NEED_NOT_BE_PRINTED                  (0xffffff)

typedef struct ValueLimits 
{
  float MinLimit;
  float MaxLimit;
  float Value; 
};

typedef ValueLimits (*FnPtrReadBatteryParam)(void);

struct InputValues_st
{
  FnPtrReadBatteryParam readInputValues;
};

enum languages
{
  English,
  German,
  MAX_POSSIBLE_LANGUAGES
};

enum temperatureUnit
{
  Celcius,
  Farenheit,
};


extern struct InputValues_st ReadBatteryParameters[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED];
extern char MessageToBePrinted[MAX_BATTERY_PARAMETERS_TO_BE_VALIDATED * MAX_POSSIBLE_LANGUAGES][100];
extern char BreachMessage[2 * MAX_POSSIBLE_LANGUAGES][100];
extern enum languages LanguageChoosen;
extern enum temperatureUnit tempUnit;
