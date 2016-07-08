/**
 * \file
 * \brief Launch My Application
 */

#include <Poco/Util/ServerApplication.h>
#include <Poco/Task.h>
#include <Poco/TaskManager.h>
#include <Poco/FileChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/PatternFormatter.h>
#include <Poco/Path.h>
#include <iostream>


/********************************************************************/

class SampleTask: public Poco::Task
{
   public:
	SampleTask(): Poco::Task("SampleTask")
	{
	}

	void runTask()
	{
		while (!sleep(5000))
		{
            std::cout << std::endl << typeid(*this).name() << "::" << __FUNCTION__ << std::endl;

            Poco::Util::Application::instance().logger().information("busy doing nothing... ");
		}
	}
};

/********************************************************************/

class MyAppSubsystem : public Poco::Util::Subsystem
{
   public:

    MyAppSubsystem(Poco::TaskManager* task_manager)
        : task_manager_(task_manager)
    {
    }

    ~MyAppSubsystem() override = default;

   protected:
    Poco::TaskManager* task_manager_;

    void initialize(Poco::Util::Application &app) override
    {
        std::ignore = app;
        task_manager_->start(new SampleTask());
        std::cout << std::endl << "MyAppSubsystem::" << __FUNCTION__ << std::endl;
    }

    void reinitialize(Poco::Util::Application &app) override
    {
        std::ignore = app;

        std::cout << std::endl << "MyAppSubsystem::" << __FUNCTION__ << std::endl;
    }

    void uninitialize() override
    {
        std::cout << std::endl << "MyAppSubsystem::" << __FUNCTION__ << std::endl;
    }

    const char* name() const override
    {
        return "MyAppSubsystem";
    }

};

/********************************************************************/

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
    int main(const ArgVec& args) override
    {
        std::ignore = args;
        std::cout << std::endl << typeid(*this).name() << "::" << __FUNCTION__ << std::endl;

        waitForTerminationRequest();

    	task_manager.cancelAll();
		task_manager.joinAll();

        std::cout << std::endl << typeid(*this).name() << "::" << __FUNCTION__ << std::endl;

        return Poco::Util::Application::EXIT_OK;
    }

    /**
     * \brief Load config file
     * \param self ownership
     */
    void initialize(Application& self) override
    {
        std::cout << std::endl << typeid(*this).name() << "::" << __FUNCTION__ << std::endl;
        loadConfiguration();
        configureLog();

        self.addSubsystem(new MyAppSubsystem(&task_manager));

        Application::initialize(self);
    }

    void uninitialize() override
    {
        /**
        delete pattern_formatter_;
        delete formatting_channel_;
        delete file_channel_;
        */
    }

    void configureLog()
    {
        logger().setLevel("debug");
        Poco::Logger::root().setLevel("debug");

        file_channel_ = new Poco::FileChannel();
        const auto& app_name = config().getString("application.name");

        Poco::Path log_path = config().getString("log.path");
        log_path.append(app_name + "-app.log");

        file_channel_->setProperty("path", log_path.toString());
        file_channel_->setProperty("rotation", config().getString("log.max_file_size"));
        file_channel_->setProperty("archive", "timestamp");

        pattern_formatter_ = new Poco::PatternFormatter();
        pattern_formatter_->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s: %t");
        formatting_channel_ = new Poco::FormattingChannel(pattern_formatter_, file_channel_);
        Poco::Logger::root().setChannel(formatting_channel_);
        logger().setChannel(formatting_channel_);
    }

};

/********************************************************************/

POCO_SERVER_MAIN(MyApp)
