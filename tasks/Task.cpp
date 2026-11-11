/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "Task.hpp"

using namespace power_sense_module;

Task::Task(std::string const& name)
    : TaskBase(name)
{
}

Task::~Task()
{
}

bool Task::configureHook()
{
    if (!TaskBase::configureHook())
        return false;
    m_current_reading = _current_reading.get();
    m_voltage_reading = _voltage_reading.get();
    m_current_scale = _current_scale.get();
    m_voltage_scale = _voltage_scale.get();
    return true;
}
bool Task::startHook()
{
    if (!TaskBase::startHook())
        return false;
    return true;
}
void Task::updateHook()
{
    TaskBase::updateHook();

    std::vector<raw_io::Analog> analog_samples;
    if (_analog_samples.read(analog_samples) != RTT::NewData) {
        return;
    }

    Voltage voltage;
    voltage.time = analog_samples[m_voltage_reading].time;
    voltage.value = analog_samples[m_voltage_reading].data * m_voltage_scale;
    Current current;
    voltage.time = analog_samples[m_current_reading].time;
    current.value = analog_samples[m_current_reading].data * m_current_scale;

    _voltage.write(voltage);
    _current.write(current);
}
void Task::errorHook()
{
    TaskBase::errorHook();
}
void Task::stopHook()
{
    TaskBase::stopHook();
}
void Task::cleanupHook()
{
    TaskBase::cleanupHook();
}
