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

// Function to check if a value is within a range
BatteryStatus checkInRange(float value, float min, float max) {
    return (value < min || value > max) ? TEMPERATURE_OUT_OF_RANGE : BATTERY_OK;
}

// Function to check temperature limits
BatteryStatus checkTemperature(float temperature) {
    return checkInRange(temperature, 0, 45);
}

// Function to check SOC limits
BatteryStatus checkSoc(float soc) {
    return checkInRange(soc, 20, 80);
}

// Function to check charge rate limits
BatteryStatus checkChargeRate(float chargeRate) {
    return checkInRange(chargeRate, 0, 0.8);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    if (checkTemperature(temperature) != BATTERY_OK) {
        cout << "Temperature out of range!\n";
        return false;
    }

    if (checkSoc(soc) != BATTERY_OK) {
        cout << "State of Charge out of range!\n";
        return false;
    }

    if (checkChargeRate(chargeRate) != BATTERY_OK) {
        cout << "Charge Rate out of range!\n";
        return false;
    }

    return true;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
}
