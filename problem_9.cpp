/*
 *  Link: https://leetcode.com/problems/add-two-numbers/description/
*/

#include <gtest/gtest.h>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        bool res {true};

        if (0 > x)
            return !res;

        const auto str = std::to_string(x);
        const auto size = str.size();

        for (auto i = 0; i < static_cast<int>(size / 2); ++i)
        {
            if (str.at(i) != str.at(size - 1 - i))
            {
                res = false;
                break;
            }
        }

        return res;
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<int, bool>> {};
TEST_P(TestWithParameters, Problem_9)
{
    auto [num, expectRes] = GetParam();

    Solution sol {};
    const auto res = sol.isPalindrome(num);
    EXPECT_EQ(res, expectRes);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple(121, true),
    std::make_tuple(-121, false),
    std::make_tuple(10, false)
));
