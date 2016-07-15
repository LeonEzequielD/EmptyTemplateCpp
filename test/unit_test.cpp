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

pid_t forka()
{
    auto cpid = fork();
    if (cpid == 0) {
        execl("./empty_templated", "empty_templated", 0, 0);
        return 0;
    }

    return cpid;
}

TEST(Example, Simple)
{
    std::ofstream outfile("empty_templated.json");
    outfile << "{ \"description\" : \"Simple Empty App\", \"log\" : { \
        \"path\" : \"/tmp/\", \"max_file_size\" : \"1 M\", \"root_directory\" \
        : \"/tmp/\" } }" << std::endl;
    outfile.close();

    auto cpid = forka();

    sleep(5);

    kill(cpid, SIGTERM);
    wait(NULL);

    EXPECT_EQ(1, 1);
}
