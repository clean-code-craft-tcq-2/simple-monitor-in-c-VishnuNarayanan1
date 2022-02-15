#include <stdio.h>
#include "ParametersReadFromSensor.h"
#include "BatteryParametersConfiguration.h"

float TemperatureFromSensorMock;
float SOCFromSensorMock;
float ChargeRateFromSensorMock;

ValueLimits_st ReadBatteryTemperature(void)
{
  struct ValueLimits_st tempLimits;
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

ValueLimits_st ReadBatteryStateOfCharge(void)
{
  struct ValueLimits_st stateOfChargeLimits;
  stateOfChargeLimits.MinLimit = MIN_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE;
  stateOfChargeLimits.MaxLimit = MAX_THRESHOLD_LIMIT_BATTERY_STATE_OF_CHARGE;
  stateOfChargeLimits.Value = SOCFromSensorMock;
  return stateOfChargeLimits;
}

ValueLimits_st ReadBateryChargeRate(void)
{
  struct ValueLimits_st chargeRateLimits;
  chargeRateLimits.MinLimit = MIN_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE;
  chargeRateLimits.MaxLimit = MAX_THRESHOLD_LIMIT_BATTERY_CHARGE_RATE ;
  chargeRateLimits.Value = ChargeRateFromSensorMock;
  return chargeRateLimits;
}
  
float ConvertCelciusToFarenheit(float farenheit)
{
    return ((farenheit - 32) * 5 / 9);
}
