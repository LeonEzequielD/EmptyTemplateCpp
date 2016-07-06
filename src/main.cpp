/**
 * \file
 * \brief Launch My Application
 */

#include <Poco/Util/ServerApplication.h>
#include <iostream>

/********************************************************************/

class MyAppSubsystem : public Poco::Util::Subsystem
{
   public:
    /**
     * \brief virtual destructor
     */
    ~MyAppSubsystem() override = default;

   protected:
    void initialize(Poco::Util::Application &app) override
    {
        std::ignore = app;

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
    /**
     * \brief Execute main function
     * \param args arguments from stdin
     * \return process code error
     */
    int main(const ArgVec& args) override
    {
        std::ignore = args;

        std::cout << std::endl << __FUNCTION__ << std::endl;

        waitForTerminationRequest();

        return Poco::Util::Application::EXIT_OK;
    }

    /**
     * \brief Load config file
     * \param self ownership
     */
    void initialize(Application& self) override
    {
        self.addSubsystem(new MyAppSubsystem());

        std::cout << std::endl << __FUNCTION__ << std::endl;

        Application::initialize(self);
    }

};

/********************************************************************/

POCO_SERVER_MAIN(MyApp)
