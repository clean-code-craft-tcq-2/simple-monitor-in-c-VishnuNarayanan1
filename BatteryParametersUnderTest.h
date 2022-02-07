int CheckBatteryTemperature(float measuredTemperatureValueUnderTest, void (*Fn_Ptr_PrintMessage)(const char[]),void (*Fn_Ptr_PrintMessageWithBreachLevel)(const char[],float));
int CheckBatteryStateOfCharge(float measuredStateOfChargeUnderTest, void (*Fn_Ptr_PrintMessage)(const char[]),void (*Fn_Ptr_PrintMessageWithBreachLevel)(const char[],float));
int CheckBatteryChargeRate(float measuredChargeRateUnderTest, void (*Fn_Ptr_PrintMessage)(const char[]),void (*Fn_Ptr_PrintMessageWithBreachLevel)(const char[],float));
