/**
 * \file
 * \brief Main Server Application Class Declaration
 */

#ifndef EMPTYTEMPLATECPP_MY_APP_HPP
#define EMPTYTEMPLATECPP_MY_APP_HPP


#include <Poco/Util/ServerApplication.h>
#include <Poco/TaskManager.h>
#include <Poco/PatternFormatter.h>
#include <Poco/FileChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/Path.h>

#include "include/my_app_subsystem.hpp"


class MyApp : public Poco::Util::ServerApplication {
   public:

    ~MyApp() override = default;

   private:
    Poco::TaskManager task_manager;

    Poco::AutoPtr<Poco::PatternFormatter>     pattern_formatter_;     /** Pattern for log */
    Poco::AutoPtr<Poco::FormattingChannel>    formatting_channel_;    /** Formatting Channel */
    Poco::AutoPtr<Poco::FileChannel>          file_channel_;          /** File Channel */

    int main(const ArgVec& args) override;

    void initialize(Application& self) override;

    void configureLog();

};

#endif /** EMPTYTEMPLATECPP_MY_APP_HPP */
