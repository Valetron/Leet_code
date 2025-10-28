/*
 *  Link: https://leetcode.com/problems/string-to-integer-atoi/description/
*/

#include <tuple>
#include <string>
#include <limits>

#include <gtest/gtest.h>

namespace
{
const auto g_hex_0 {0x30};
const auto g_hex_9 {0x39};
const auto g_stepNum {48};
constexpr auto g_maxInt = std::numeric_limits<int>::max();
constexpr auto g_minInt = std::numeric_limits<int>::min();

int my_clamp(int64_t num)
{
    if (num > g_maxInt)
        return g_maxInt;
    else if (num < g_minInt)
        return g_minInt;
    else
        return num;
}
}

class Solution
{
public:
    int myAtoi(const std::string& str)
    {
        const auto firstNotSpace = str.find_first_not_of(' ');
        if (str.empty() || std::string::npos == firstNotSpace)
            return 0;

        auto it = str.cbegin();
        int currCh {*it};
        int64_t res {0};
        bool isNegative {false};
        int resTmp {0};

        while (currCh == ' ')
        {
            ++it;
            currCh = *it;
        }

        if ('-' == currCh)
        {
            isNegative = true;
            ++it;
        }
        else if ('+' == currCh)
        {
            ++it;
        }

        for (; it != str.cend(); ++it)
        {
            currCh = *it;
            if (currCh > g_hex_9 || currCh < g_hex_0)
                break;

            res *= 10;

            resTmp = my_clamp(res);
            if (g_maxInt == resTmp || g_minInt == resTmp)
                break;

            res += (currCh - g_stepNum);
        }

        return (isNegative ? my_clamp(-res) : my_clamp(res));
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::string, int>> {};
TEST_P(TestWithParameters, TestName)
{
    const auto& [inputData, expectRes] = GetParam();
    Solution solver {};
    const auto res = solver.myAtoi(inputData);
    EXPECT_EQ(res, expectRes);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple("42", 42),
    std::make_tuple(" -042", -42),
    std::make_tuple("1337c0d3", 1337),
    std::make_tuple("0-1", 0),
    std::make_tuple("words and 987", 0),
    std::make_tuple("0", 0),
    std::make_tuple("-91283472332", -2147483648),
    std::make_tuple("", 0),
    std::make_tuple("+1", 1),
    std::make_tuple(" ", 0),
    std::make_tuple("20000000000000000000", 2147483647)
));

