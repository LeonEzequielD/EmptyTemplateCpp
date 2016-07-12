/**
 * \file
 * \brief Example of Server Application Subsystem Class Implementation
 */

#include "include/my_app_subsystem.hpp"

MyAppSubsystem::MyAppSubsystem(Poco::TaskManager *task_manager)
    : task_manager_(task_manager)
{

}

void MyAppSubsystem::initialize(Poco::Util::Application &app)
{
    std::ignore = app;
    task_manager_->start(new MyAppTask());
}

void MyAppSubsystem::uninitialize()
{
}

const char *MyAppSubsystem::name() const
{
    return "MyAppSubsystem";
}

