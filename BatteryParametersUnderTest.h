int CheckBatteryParameterLimits(char message[],float measuredTemperatureValueUnderTest,float minLimit, float maxLimit, 
                                void (*Fn_Ptr_PrintMessageWithBreachLevel)(char[],float));
