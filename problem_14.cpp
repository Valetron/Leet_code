/*
 *  Link: https://leetcode.com/problems/longest-common-prefix/description/
*/

#include <set>
#include <tuple>
#include <string>
#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs)
    {
        if (1 == strs.size())
            return strs[0];

        const std::set<std::string> setStr(strs.cbegin(), strs.cend());

        const auto& firstWord = *setStr.cbegin();
        const auto& lastWord = *setStr.crbegin();
        const auto minLen = std::min(firstWord.length(), lastWord.length());

        std::string res {};
        for (auto i = 0; i < minLen; ++i)
        {
            if (firstWord[i] == lastWord[i])
                res += firstWord[i];
            else
                break;
        }

        return res;
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::vector<std::string>, std::string>> {};
TEST_P(TestWithParameters, TestName)
{
    const auto& [inputData, expectRes] = GetParam();
    Solution solver {};
    const auto res = solver.longestCommonPrefix(inputData);
    EXPECT_EQ(res, expectRes);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple(std::vector<std::string>({"flower", "flow", "flight"}), "fl"),
    std::make_tuple(std::vector<std::string>({"dog", "racecar", "car"}), ""),
    std::make_tuple(std::vector<std::string>({"a"}), "a")
));

