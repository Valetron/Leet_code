#include <tuple>
#include <string>

#include <gtest/gtest.h>

TEST(Template, Test)
{
    SUCCEED();
}

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::string, std::string>> {};
TEST_P(TestWithParameters, TestName)
{
    const auto& [first, second] = GetParam();
    EXPECT_STRNE(first.c_str(), second.c_str());
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple("Hello", "World")
));

