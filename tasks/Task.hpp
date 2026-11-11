/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef POWER_SENSE_MODULE_TASK_TASK_HPP
#define POWER_SENSE_MODULE_TASK_TASK_HPP

#include "power_sense_module/TaskBase.hpp"
#include <base/Float.hpp>

namespace power_sense_module {
    class Task : public TaskBase {
        friend class TaskBase;

    private:
        double m_current_scale = base::unknown<double>();
        double m_voltage_scale = base::unknown<double>();
        uint8_t m_current_reading = 0;
        uint8_t m_voltage_reading = 0;

    public:
        Task(std::string const& name = "power_sense_module::Task");
        ~Task();
        bool configureHook();
        bool startHook();
        void updateHook();
        void errorHook();
        void stopHook();
        void cleanupHook();
    };
}

#endif
