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

    /**
     * \brief Constructor
     * \param task_manager reference to main App task manager
     */
    MyAppSubsystem(Poco::TaskManager* task_manager);

    /**
     * \brief default destructor
     */
    ~MyAppSubsystem() override = default;

   protected:

    /** Reference to main App task manager */
    Poco::TaskManager* task_manager_;

    /**
     * \brief Initializer for this Subsystem, called after the constructor
     * \param app Reference to the main app
     */
    void initialize(Poco::Util::Application &app) override;

    /**
     * \brief uninitializer for this Subsystem, called before destructor
     */
    void uninitialize() override;

    /** Subsystem Name */
    const char* name() const override;
};

#endif /** EMPTYTEMPLATECPP_MY_APP_SUBSYSTEM_HPP */
