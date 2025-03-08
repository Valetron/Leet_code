/*
 *  Link: https://leetcode.com/problems/roman-to-integer/
*/

#include <string>
#include <unordered_map>

#include <gtest/gtest.h>

namespace
{
const std::unordered_map<char, int> romanArabicNums = { {'I', 1},
                                                        {'V', 5},
                                                        {'X', 10},
                                                        {'L', 50},
                                                        {'C', 100},
                                                        {'D', 500},
                                                        {'M', 1000} };
}

class Solution
{
public:
    int romanToInt(std::string_view romanStr)
    {
        int res {0};
        int prev {0};
        int curr {0};
        const auto size = romanStr.size();

        for (auto i = 0; i < size; ++i)
        {
            const auto sym = romanStr.at(i);
            curr = romanArabicNums.at(sym);
            if (prev < curr)
                res = res - prev + (curr - prev);
            else
                res += curr;

            prev = curr;
        }

        return res;
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::string, int>> {};
TEST_P(TestWithParameters, Problem_13)
{
    const auto& [romanNum, expect] = GetParam();
    Solution sol {};
    const auto res = sol.romanToInt(romanNum);
    EXPECT_EQ(res, expect);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple("III", 3),
    std::make_tuple("LVIII", 58),
    std::make_tuple("MCMXCIV", 1994),
    std::make_tuple("XLII", 42)
));

