/*
 *  Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

#include <set>
#include <tuple>
#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        const auto uniqueNums = std::set<int>(nums.cbegin(), nums.cend());
        nums = std::vector<int>(uniqueNums.cbegin(), uniqueNums.cend());
        return uniqueNums.size();
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {};
TEST_P(TestWithParameters, TestName)
{
    auto [inputData, expectUniqueNums, expectRes] = GetParam();
    Solution solver {};
    const auto uniqueNums = solver.removeDuplicates(inputData);
    ASSERT_EQ(uniqueNums, expectUniqueNums);
    EXPECT_EQ(inputData, expectRes);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple(std::vector<int>{1, 1, 2}, 2, std::vector<int>{1, 2}),
    std::make_tuple(std::vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, 5, std::vector<int>{0, 1, 2, 3, 4})
));

