/**
 * \file
 * \brief Example of Server Application Task Class Implementation
 */

#include "include/my_app_task.hpp"

#include <Poco/Util/ServerApplication.h>

MyAppTask::MyAppTask() : Poco::Task("MyAppTask")
{
}

void MyAppTask::runTask()
{
    while (!sleep(5000)) {
        Poco::Util::Application::instance().logger().information("busy doing nothing... ");
  }
}

