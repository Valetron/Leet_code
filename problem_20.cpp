/*
 *  Link: https://leetcode.com/problems/valid-parentheses/description/
*/

#include <map>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>

namespace
{
constexpr auto g_closeParentheses = {')', ']', '}'};
inline const auto g_checkClose = [](const auto ch) {
    return (std::find(g_closeParentheses.begin(), g_closeParentheses.end(), ch) != g_closeParentheses.end());
};
inline const auto g_checkPairClose = [](const char currCh, const char lastCh) {
    static std::map<char, char> closeOpenMap {
        {')', '('},
        {'}', '{'},
        {']', '['},
    };
    return (closeOpenMap[currCh] == lastCh);
};
}

class Solution
{
public:
    bool isValid(const std::string& str)
    {
        const auto strLen = str.length();

        if ((0 != strLen % 2) || g_checkClose(str.front()))
            return false;

        std::stack<char> parentheses {};
        for (auto iter = str.cbegin(); iter != str.cend(); ++iter)
        {
            const auto currCh = *iter;
            if (!parentheses.empty())
            {
                const auto lastCh = parentheses.top();
                if (currCh != lastCh && g_checkClose(currCh) && g_checkPairClose(currCh, lastCh))
                {
                    parentheses.pop();
                    continue;
                }
            }

            parentheses.push(currCh);
        }

        return parentheses.empty();
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::string, bool>> {};
TEST_P(TestWithParameters, TestName)
{
    const auto& [inputData, expectRes] = GetParam();
    Solution solver {};
    const auto res = solver.isValid(inputData);
    EXPECT_EQ(res, expectRes);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple("{", false),
    std::make_tuple(")", false),
    std::make_tuple("[](", false),
    std::make_tuple("()", true),
    std::make_tuple("()[]{}", true),
    std::make_tuple("(]", false),
    std::make_tuple("([])", true),
    std::make_tuple("([)]", false)
));

