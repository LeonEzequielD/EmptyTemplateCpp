/**
 * \file
 * \brief Declare My Application
 */

#ifndef EMPTYTEMPLATECPP_MYAPP_HPP
#define EMPTYTEMPLATECPP_MYAPP_HPP

#include <Poco/Util/ServerApplication.h>

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

        waitForTerminationRequest();

        return Poco::Util::Application::EXIT_OK;
    }

    /**
     * \brief Load config file
     * \param self ownership
     */
    void initialize(Application& /*self*/) override {

    }

};

#endif /** EMPTYTEMPLATECPP_MYAPP_HPP */
