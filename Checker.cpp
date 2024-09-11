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
        BatteryStatus status = checkAll();
        reportError(status);
        return status == BATTERY_OK;
    }

private:
    float temperature_;
    float soc_;
    float chargeRate_;

    BatteryStatus checkAll() const {
        if (temperature_ < 0 || temperature_ > 45) return TEMPERATURE_OUT_OF_RANGE;
        if (soc_ < 20 || soc_ > 80) return SOC_OUT_OF_RANGE;
        if (chargeRate_ > 0.8) return CHARGE_RATE_OUT_OF_RANGE;
        return BATTERY_OK;
    }

    void reportError(BatteryStatus status) const {
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
                break;  // No error
        }
    }
};

int main() {
    Battery battery1(25, 70, 0.7);
    assert(battery1.isOk() == true);

    Battery battery2(50, 85, 0);
    assert(battery2.isOk() == false);

    return 0;
}
