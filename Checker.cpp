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

// Function to check if value is in range
BatteryStatus checkInRange(float value, float min, float max, BatteryStatus outOfRangeStatus) {
    if (value < min || value > max) {
        return outOfRangeStatus;
    }
    return BATTERY_OK;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    BatteryStatus status;

    // Check temperature
    status = checkInRange(temperature, 0, 45, TEMPERATURE_OUT_OF_RANGE);
    if (status != BATTERY_OK) {
        cout << "Temperature out of range!\n";
        return false;
    }

    // Check SOC
    status = checkInRange(soc, 20, 80, SOC_OUT_OF_RANGE);
    if (status != BATTERY_OK) {
        cout << "State of Charge out of range!\n";
        return false;
    }

    // Check charge rate
    status = checkInRange(chargeRate, 0, 0.8, CHARGE_RATE_OUT_OF_RANGE);
    if (status != BATTERY_OK) {
        cout << "Charge Rate out of range!\n";
        return false;
    }

    return true;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
}
