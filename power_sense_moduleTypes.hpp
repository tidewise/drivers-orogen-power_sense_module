#ifndef power_sense_module_TYPES_HPP
#define power_sense_module_TYPES_HPP

#include <base/Float.hpp>
#include <base/Time.hpp>

namespace power_sense_module {
    struct Voltage {
        base::Time time;
        double value = base::unknown<double>();
    };
    struct Current {
        base::Time time;
        double value = base::unknown<double>();
    };
}

#endif
