/**
 * \file
 * \brief Unit Test for Template
 *
 */
#include <memory>
#include <fstream>

#include <Poco/Process.h>
#include <Poco/File.h>
#include <gtest/gtest.h>

void CreateConfigFile()
{
    std::ofstream outfile ("empty_templated.json");
    outfile <<  "{ \"description\" : \"Simple Empty App\", \"log\" : { \
        \"path\" : \"/tmp/\", \"max_file_size\" : \"1 M\", \"root_directory\" \
        : \"/tmp/\" } }" << std::endl;
    outfile.close();
}

TEST(Example, Simple)
{
    CreateConfigFile();

    Poco::File file("empty_templated");

    poco_assert(file.exists());
    poco_assert(file.isFile());
    poco_assert(file.canExecute());
    Poco::ProcessHandle* emptyd = new Poco::ProcessHandle(Poco::Process::launch(file.path(), {}));

    poco_assert(Poco::Process::isRunning(*emptyd));
    poco_assert(emptyd->id());

    sleep(5);

    Poco::Process::requestTermination(emptyd->id());
    emptyd->wait();

    poco_assert(!Poco::Process::isRunning(*emptyd));
    delete emptyd;

    EXPECT_EQ(1, 1);
}
