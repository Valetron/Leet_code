/*
 *  Link: https://leetcode.com/problems/plus-one/description/
*/

#include <tuple>
#include <string>

#include <gtest/gtest.h>

namespace
{
constexpr auto g_spaceSymbol {' '};
}

class Solution
{
public:
    int lengthOfLastWord(const std::string& str)
    {
        const auto strLen = str.length();
        if (1 == strLen && " " != str)
            return 1;

        const auto nonSpaceIndex = str.find_last_not_of(g_spaceSymbol, strLen);
        const auto spaceIndex = str.find_last_of(g_spaceSymbol, nonSpaceIndex);

        // NOTE: т к это индексы, для формирования слова нужно добавить по единице к каждому числу
        return (nonSpaceIndex - spaceIndex);
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::string, int>> {};
TEST_P(TestWithParameters, TestName)
{
    const auto& [str, expectRes] = GetParam();
    Solution solver {};
    const auto res = solver.lengthOfLastWord(str);
    EXPECT_EQ(expectRes, res);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple("a", 1),
    std::make_tuple("b ", 1),
    std::make_tuple(" c", 1),
    std::make_tuple(" d ", 1),
    std::make_tuple("Hello World", 5),
    std::make_tuple("   fly me   to   the moon  ", 4),
    std::make_tuple("luffy is still joyboy", 6)
));

