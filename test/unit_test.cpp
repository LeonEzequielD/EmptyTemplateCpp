/**
 * \file
 * \brief Unit Test for Template
 *
 */
#include <memory>
#include <fstream>

#include <gtest/gtest.h>

TEST(Example, Simple)
{
    EXPECT_EQ(1, 1);

    char *ptr = (char *) malloc (100);

    if (ptr) {
        printf("frweg");
    }

}
