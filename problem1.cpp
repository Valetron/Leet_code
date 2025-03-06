/*
 *   Link: https://leetcode.com/problems/two-sum/description/
*/

#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

class Solution
{
public:
    // NOTE: O(n)
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        const auto size = nums.size();
        if (2 == size)
            return {0, 1};

        std::unordered_multimap<int, int> umap {};

        for (int i = 0; i < size; ++i)
        {
            const auto elem = nums.at(i);
            const auto numToSearch = target - elem;
            const auto iter = umap.find(numToSearch);

            if (iter != umap.cend())
                return {i, iter->second};

            umap.emplace(std::make_pair(elem, i));
        }

        return {};
    }

private:
    // NOTE: O(n^2)
    std::vector<int> sol0(std::vector<int>& nums, int target)
    {
        const auto size = nums.size();
        if (2 == size)
            return {0, 1};

        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                if (target == nums.at(i) + nums.at(j))
                    return {i, j};
            }
        }

        return {};
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {};
TEST_P(TestWithParameters, Problem_1)
{
    auto [nums, target, expect] = GetParam();
    Solution solver {};
    auto res = solver.twoSum(nums, target);
    std::sort(res.begin(), res.end());
    EXPECT_EQ(res, expect);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple<std::vector<int>, int, std::vector<int>>({2, 7, 11, 15}, 9, {0, 1}),
    std::make_tuple<std::vector<int>, int, std::vector<int>>({3, 2, 4}, 6, {1, 2}),
    std::make_tuple<std::vector<int>, int, std::vector<int>>({3, 3}, 6, {0, 1}),
    std::make_tuple<std::vector<int>, int, std::vector<int>>({9, 8, 4, 11, 3}, 7, {2, 4}),
    std::make_tuple<std::vector<int>, int, std::vector<int>>({1, 2}, 3, {0, 1}),
    std::make_tuple<std::vector<int>, int, std::vector<int>>({3, 2, 3}, 6, {0, 2})
));
