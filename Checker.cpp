#include <assert.h>
#include <iostream>
using namespace std;

// Define status codes for error handling
enum BatteryStatus {
    BATTERY_OK,
    TEMPERATURE_OUT_OF_RANGE,
    SOC_OUT_OF_RANGE,
    CHARGE_RATE_OUT_OF_RANGE
};

// Function to check temperature limits
BatteryStatus checkTemperature(float temperature) {
    if (temperature < 0 || temperature > 45) {
        return TEMPERATURE_OUT_OF_RANGE;
    }
    return BATTERY_OK;
}

// Function to check SOC limits
BatteryStatus checkSoc(float soc) {
    if (soc < 20 || soc > 80) {
        return SOC_OUT_OF_RANGE;
    }
    return BATTERY_OK;
}

// Function to check charge rate limits
BatteryStatus checkChargeRate(float chargeRate) {
    if (chargeRate > 0.8) {
        return CHARGE_RATE_OUT_OF_RANGE;
    }
    return BATTERY_OK;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    BatteryStatus status;

    // Check temperature
    status = checkTemperature(temperature);
    if (status != BATTERY_OK) {
        cout << "Temperature out of range!\n";
        return false;
    }

    // Check SOC
    status = checkSoc(soc);
    if (status != BATTERY_OK) {
        cout << "State of Charge out of range!\n";
        return false;
    }

    // Check charge rate
    status = checkChargeRate(chargeRate);
    if (status != BATTERY_OK) {
        cout << "Charge Rate out of range!\n";
        return false;
    }

    return true;
}

int main() {
    assert(batteryIsOk(30, 60, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
}
