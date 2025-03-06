/*
 *  Link: https://leetcode.com/problems/palindrome-number/description/
*/

#include <cstdlib>

#include <gtest/gtest.h>

class Solution
{
public:
    // NOTE: O(log(n))
    bool isPalindrome(int x)
    {
        bool palindrome {false};

        if ((0 > x) || ((x != 0) && (0 == x % 10)))
            return palindrome;

        uint64_t reversed {0};
        int tmp {x};

        while (tmp != 0)
        {
            const auto divMod = std::div(tmp, 10);
            reversed = (reversed * 10) + divMod.rem;
            tmp = divMod.quot;
        }

        if (reversed == x)
            palindrome = true;

        return palindrome;
    }

private:
    bool isPalindrome_string(int x)
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
    std::make_tuple(10, false),
    std::make_tuple(300, false),
    std::make_tuple(1, true),
    std::make_tuple(0, true),
    std::make_tuple(123454321, true)
));
