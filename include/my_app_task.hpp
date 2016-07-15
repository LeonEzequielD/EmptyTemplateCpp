/**
 * \file
 * \brief Example of Server Application Task Class Declaration
 */

#ifndef EMPTYTEMPLATECPP_MY_APP_TASK_HPP
#define EMPTYTEMPLATECPP_MY_APP_TASK_HPP

#include <Poco/Task.h>

class MyAppTask: public Poco::Task
{
   public:
	MyAppTask();

	void runTask() override;
};

#endif /** EMPTYTEMPLATECPP_MY_APP_TASK_HPP */
