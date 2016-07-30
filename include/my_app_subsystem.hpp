/**
 * \file
 * \brief Example of Server Application Subsystem Class Declaration
 */

#ifndef EMPTYTEMPLATECPP_MY_APP_SUBSYSTEM_HPP
#define EMPTYTEMPLATECPP_MY_APP_SUBSYSTEM_HPP

#include <Poco/Util/ServerApplication.h>
#include <Poco/TaskManager.h>

#include "include/my_app_task.hpp"

class MyAppSubsystem : public Poco::Util::Subsystem
{
   public:

    MyAppSubsystem(Poco::TaskManager* task_manager);

    ~MyAppSubsystem() override = default;

   protected:
    Poco::TaskManager* task_manager_;

    void initialize(Poco::Util::Application &app) override;

    void uninitialize() override;

    const char* name() const override;
};

#endif /** EMPTYTEMPLATECPP_MY_APP_SUBSYSTEM_HPP */
