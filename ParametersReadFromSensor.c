#include <stdio.h>

float TemperatureFromSensorMock;
float SOCFromSensorMock;
float ChargeRateFromSensorMock;

float ReadBatteryTemperature(void)
{
  return TemperatureFromSensorMock;
}

float ReadBatteryStateOfCharge(void)
{
  return SOCFromSensorMock;
}

float ReadBateryChargeRate(void)
{
  return ChargeRateFromSensorMock;
}
