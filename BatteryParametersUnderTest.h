int CheckBatteryTemperature(float measuredTemperatureValueUnderTest,void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float), void (*Fn_Ptr_PrintMessage)(char[]));
int CheckBatteryStateOfCharge(float measuredStateOfChargeUnderTest,void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float), void (*Fn_Ptr_PrintMessage)(char[]));
int CheckBatteryChargeRate(float measuredChargeRateUnderTest,void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float), void (*Fn_Ptr_PrintMessage)(char[]));
