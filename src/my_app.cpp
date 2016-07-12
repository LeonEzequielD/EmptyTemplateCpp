/**
 * \file
 * \brief Main Server Application Class
 */

#include "include/my_app.hpp"

int MyApp::main(const ArgVec &args)
{
    std::ignore = args;

    waitForTerminationRequest();

    task_manager.cancelAll();
    task_manager.joinAll();

    return Poco::Util::Application::EXIT_OK;
}

void MyApp::initialize(Application &self)
{
    loadConfiguration();
    configureLog();

    self.addSubsystem(new MyAppSubsystem(&task_manager));

    Application::initialize(self);
}

void MyApp::configureLog()
{
    logger().setLevel("debug");
    Poco::Logger::root().setLevel("debug");

    file_channel_ = new Poco::FileChannel();
    const auto &app_name = config().getString("application.name");

    Poco::Path log_path = config().getString("log.path");
    log_path.append(app_name + "-app.log");

    file_channel_->setProperty("path", log_path.toString());
    file_channel_->setProperty("rotation",
                             config().getString("log.max_file_size"));
    file_channel_->setProperty("archive", "timestamp");

    pattern_formatter_ = new Poco::PatternFormatter();
    pattern_formatter_->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s: %t");
    formatting_channel_ =
        new Poco::FormattingChannel(pattern_formatter_, file_channel_);
    Poco::Logger::root().setChannel(formatting_channel_);
    logger().setChannel(formatting_channel_);
}

