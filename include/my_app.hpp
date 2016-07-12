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

    /**
     * \brief virtual destructor
     */
    ~MyApp() override = default;

   private:
    Poco::TaskManager task_manager;

    Poco::PatternFormatter*     pattern_formatter_;     /** Pattern for log */
    Poco::FormattingChannel*    formatting_channel_;    /** Formatting Channel */
    Poco::FileChannel*          file_channel_;          /** File Channel */

    /**
     * \brief Execute main function
     * \param args arguments from stdin
     * \return process code error
     */
    int main(const ArgVec& args) override;

    /**
     * \brief Load config file
     * \param self ownership
     */
    void initialize(Application& self) override;

    /**
     * \brief Configures Log File
     */
    void configureLog();

};

#endif /** EMPTYTEMPLATECPP_MY_APP_HPP */