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
    // Check all conditions in a single decision point
    BatteryStatus status = BATTERY_OK;
    if (checkInRange(temperature, 0, 45, TEMPERATURE_OUT_OF_RANGE) != BATTERY_OK ||
        checkInRange(soc, 20, 80, SOC_OUT_OF_RANGE) != BATTERY_OK ||
        checkInRange(chargeRate, 0, 0.8, CHARGE_RATE_OUT_OF_RANGE) != BATTERY_OK) {
        // Determine which error occurred
        if (checkInRange(temperature, 0, 45, TEMPERATURE_OUT_OF_RANGE) != BATTERY_OK) {
            cout << "Temperature out of range!\n";
        } else if (checkInRange(soc, 20, 80, SOC_OUT_OF_RANGE) != BATTERY_OK) {
            cout << "State of Charge out of range!\n";
        } else if (checkInRange(chargeRate, 0, 0.8, CHARGE_RATE_OUT_OF_RANGE) != BATTERY_OK) {
            cout << "Charge Rate out of range!\n";
        }
        return false;
    }
    return true;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
}
