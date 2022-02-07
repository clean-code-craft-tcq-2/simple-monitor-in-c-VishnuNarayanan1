int CheckBatteryTemperature(float measuredTemperatureValueUnderTest, void (*Fn_Ptr_PrintMessage)(char[]),void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float));
int CheckBatteryStateOfCharge(float measuredStateOfChargeUnderTest, void (*Fn_Ptr_PrintMessage)(char[]),void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float));
int CheckBatteryChargeRate(float measuredChargeRateUnderTest, void (*Fn_Ptr_PrintMessage)(char[]),void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float));
