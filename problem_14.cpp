/*
 *  Link: https://leetcode.com/problems/longest-common-prefix/description/
*/

#include <tuple>
#include <string>
#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs)
    {
        std::string res {};

        const auto strsSize = strs.size();

        if (1 == strsSize)
            return strs[0];

        const auto& firstWord = strs[0];
        std::string tmpStr {};
        for (auto ch = firstWord.cbegin(); ch != firstWord.cend(); ++ch)
        {
            tmpStr = (res + *ch);

            for (size_t i = 1; i < strsSize; ++i)
            {
#if __cplusplus >= 202002L
                if (!strs[i].starts_with(tmpStr))
#else
                if (strs[i].compare(tmpStr) < 0)
#endif
                {
                    return res;
                }
            }
            res = std::move(tmpStr);
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

