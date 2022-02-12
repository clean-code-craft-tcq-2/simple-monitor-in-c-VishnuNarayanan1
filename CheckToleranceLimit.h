int CheckIfToleranceToBeChecked(int batteryParam,char message[],float measuredBatteryParam,float minLimit, float maxLimit, float toleranceLimit, void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float));
int CheckBatteryToleranceLimits(char message[],float measuredBatteryParam,float minLimit, float maxLimit, float toleranceLimit, void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float));
float ReturnToleranceLimit(float tolerancePercentage,  float batteryParameterValue);
