#include <iostream>
#include <cassert>
using namespace std;

// Define status codes for error handling
enum BatteryStatus {
    BATTERY_OK,
    TEMPERATURE_OUT_OF_RANGE,
    SOC_OUT_OF_RANGE,
    CHARGE_RATE_OUT_OF_RANGE
};

// Battery class definition
class Battery {
public:
    Battery(float temperature, float soc, float chargeRate)
        : temperature_(temperature), soc_(soc), chargeRate_(chargeRate) {}

    bool isOk() const {
        // Check all conditions in one place
        BatteryStatus status = (temperature_ < 0 || temperature_ > 45) ? 
                                TEMPERATURE_OUT_OF_RANGE :
                                (soc_ < 20 || soc_ > 80) ? 
                                SOC_OUT_OF_RANGE :
                                (chargeRate_ > 0.8) ? 
                                CHARGE_RATE_OUT_OF_RANGE :
                                BATTERY_OK;

        // Directly report error if status is not OK
        if (status != BATTERY_OK) {
            reportError(status);
            return false;
        }
        return true;
    }

private:
    float temperature_;
    float soc_;
    float chargeRate_;

    void reportError(BatteryStatus status) const {
        static const char* errorMessages[] = {
            "Temperature out of range!",
            "State of Charge out of range!",
            "Charge Rate out of range!"
        };
        cout << errorMessages[status - 1] << endl;
    }
};

int main() {
    Battery battery1(25, 70, 0.7);
    assert(battery1.isOk() == true);

    Battery battery2(50, 85, 0);
    assert(battery2.isOk() == false);

    return 0;
}
