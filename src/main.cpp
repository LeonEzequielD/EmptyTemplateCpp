/**
 * \file
 * \brief Launch My Application
 */

#include <Poco/Util/ServerApplication.h>
#include <iostream>

#include "include/MyApp.hpp"

int main(int argc, char** argv)
{
    MyApp app;
    return app.run(argc, argv);
}
