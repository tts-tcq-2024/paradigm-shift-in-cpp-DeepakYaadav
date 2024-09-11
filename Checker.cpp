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
    return (value < min || value > max) ? outOfRangeStatus : BATTERY_OK;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    // Combine all checks into a single condition
    BatteryStatus status = BATTERY_OK;
    status = checkInRange(temperature, 0, 45, TEMPERATURE_OUT_OF_RANGE);
    status = (status == BATTERY_OK) ? checkInRange(soc, 20, 80, SOC_OUT_OF_RANGE) : status;
    status = (status == BATTERY_OK) ? checkInRange(chargeRate, 0, 0.8, CHARGE_RATE_OUT_OF_RANGE) : status;

    if (status != BATTERY_OK) {
        switch (status) {
            case TEMPERATURE_OUT_OF_RANGE:
                cout << "Temperature out of range!\n";
                break;
            case SOC_OUT_OF_RANGE:
                cout << "State of Charge out of range!\n";
                break;
            case CHARGE_RATE_OUT_OF_RANGE:
                cout << "Charge Rate out of range!\n";
                break;
            default:
                break;
        }
        return false;
    }

    return true;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
}
