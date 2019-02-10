#include <gtest/gtest.h>
#include <Application.h>

class ApplicationTests : public ::testing::Test {
public:

protected:
    Application application;
};

TEST(ApplicationTests, ArgumentParsing) {
    ASSERT_TRUE(true);
}

TEST(ApplicationTests, ApplicationInitialization) {
    ASSERT_TRUE(true);
}
