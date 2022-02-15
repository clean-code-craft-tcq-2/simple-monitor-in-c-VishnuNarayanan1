ValueLimits ReadBatteryTemperature(void);
ValueLimits ReadBatteryStateOfCharge(void);
ValueLimits ReadBateryChargeRate(void);
float ConvertCelciusToFarenheit(float farenheit);

extern float TemperatureFromSensorMock;
extern float SOCFromSensorMock;
extern float ChargeRateFromSensorMock;
