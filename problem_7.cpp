/*
 *  Link: https://leetcode.com/problems/reverse-integer/
*/

#include <limits>
#include <cstdlib>

#include <gtest/gtest.h>

class Solution
{
public:
    int reverse(int x)
    {
        if (x < 10 && x > -10)
            return x;

        int32_t reversed {0};
        constexpr int minIntDiv10 = (std::numeric_limits<decltype(x)>::min() / 10);
        constexpr int maxIntDiv10 = (std::numeric_limits<decltype(x)>::max() / 10);

        while (x != 0)
        {
            if (reversed < minIntDiv10 || reversed > maxIntDiv10)
                return 0;

            const auto divMod = std::div(x, 10);

            reversed = (reversed * 10) + divMod.rem;
            x = divMod.quot;
        }

        return reversed;
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<int, int>> {};
TEST_P(TestWithParameters, Problem_7)
{
    auto [num, expectRes] = GetParam();

    Solution sol {};
    const auto res = sol.reverse(num);
    EXPECT_EQ(res, expectRes);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple(123, 321),
    std::make_tuple(-123, -321),
    std::make_tuple(120, 21),
    std::make_tuple(1534236469, 0),
    std::make_tuple(0, 0)
));
