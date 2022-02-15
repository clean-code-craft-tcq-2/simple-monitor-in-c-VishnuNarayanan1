#include <stdio.h>
#include "BatteryParametersConfiguration.h"
#include "ParametersReadFromSensor.h"

float TemperatureFromSensorMock;
float SOCFromSensorMock;
float ChargeRateFromSensorMock;

ValueLimits ReadBatteryTemperature(void)
{
  struct ValueLimits tempLimits;
  if(tempUnit == Farenheit)
  {
    tempLimits.MinLimit = ConvertCelciusToFarenheit(MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE);
    tempLimits.MaxLimit = ConvertCelciusToFarenheit(MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE);
    tempLimits.Value = ConvertCelciusToFarenheit(TemperatureFromSensorMock);
  }
  else
  {
    tempLimits.MinLimit = MIN_THRESHOLD_LIMIT_BATTERY_TEMPERATURE;
    tempLimits.MaxLimit = MAX_THRESHOLD_LIMIT_BATTERY_TEMPERATURE;
    tempLimits.Value = TemperatureFromSensorMock;
  }
  return tempLimits;
}

ValueLimits ReadBatteryStateOfCharge(void)
{
  struct ValueLimits stateOfChargeLimits;
  stateOfChargeLimits.MinLimit = MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE;
  stateOfChargeLimits.MaxLimit = MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE;
  stateOfChargeLimits.Value = SOCFromSensorMock;
  return stateOfChargeLimits;
}

ValueLimits ReadBateryChargeRate(void)
{
  struct ValueLimits chargeRateLimits;
  chargeRateLimits.MinLimit = MIN_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE;
  chargeRateLimits.MaxLimit = MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE ;
  chargeRateLimits.Value = ChargeRateFromSensorMock;
  return chargeRateLimits;
}
  
float ConvertCelciusToFarenheit(float farenheit)
{
    return ((farenheit - 32) * 5 / 9);
}
