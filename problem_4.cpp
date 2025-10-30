/*
 *  Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
*/

#include <tuple>
#include <vector>

#include <gtest/gtest.h>

#warning "make log(n)"

class Solution
{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        const auto nums1Size = nums1.size();
        const auto nums2Size = nums2.size();
        const auto totalSize = nums1Size + nums2Size;

        if (0 == totalSize)
            return 0.0;

        std::vector<int> tmpVec {};
        if (0 != nums1Size)
            std::copy(nums1.begin(), nums1.end(), std::back_inserter(tmpVec));

        if (0 != nums2Size)
            std::copy(nums2.begin(), nums2.end(), std::back_inserter(tmpVec));

        std::sort(tmpVec.begin(), tmpVec.end());

        const auto halfIdx = tmpVec.size() / 2;

        if (0 != tmpVec.size() % 2)
        {
            return tmpVec[halfIdx];
        }

        const double num1 = tmpVec[halfIdx - 1];
        const double num2 = tmpVec[halfIdx];

        return ((num1 + num2) / 2);
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>, double>> {};
TEST_P(TestWithParameters, Problem_4)
{
    auto [list1, list2, expectRes] = GetParam();
    Solution solver {};
    const auto res = solver.findMedianSortedArrays(list1, list2);
    EXPECT_EQ(res, expectRes);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple(std::vector<int>{1, 3}, std::vector<int>{2}, 2.0),
    std::make_tuple(std::vector<int>{1, 2}, std::vector<int>{3, 4}, 2.5)
));

