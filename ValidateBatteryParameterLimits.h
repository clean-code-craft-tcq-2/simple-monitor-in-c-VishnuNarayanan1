int ValidateIfBatteryParameterValueIsLessThanMinOperatingLimit(float minOperatingLimitOfBatteryParameter,  float batteryParameterValue, void (*Fn_Ptr)(const char[],float));
int ValidateIfBatteryParameterValueIsGreaterThanMaxOperatingLimit(float maxOperatingLimitOfBatteryParameter,  float batteryParameterValue, void (*Fn_Ptr)(const char[],float));
