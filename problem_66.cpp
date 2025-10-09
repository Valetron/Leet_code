/*
 *  Link: https://leetcode.com/problems/plus-one/
*/

#include <tuple>
#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        auto res = digits;
        bool prepend {false};
        int addition = 0;
        const auto& rend = res.rend();

        for (auto iter = res.rbegin(); iter != rend; ++iter)
        {
            auto& elem = *iter;
            ++elem;

            if (elem < 10)
                break;

            elem = 0;
            if (iter + 1 == rend)
                prepend = true;
        }

        if (prepend)
        {
            std::vector<int> tmp(res.size() + 1);
            std::copy(res.begin(), res.end(), tmp.begin() + 1);
            tmp[0] = 1;
            res = tmp;
        }

        return res;
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {};
TEST_P(TestWithParameters, Problem_66)
{
    auto [inputData, expectRes] = GetParam();
    Solution solver {};
    const auto res = solver.plusOne(inputData);
    EXPECT_EQ(res, expectRes);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple(std::vector<int>{1, 2, 3}, std::vector<int>{1, 2, 4}),
    std::make_tuple(std::vector<int>{4, 3, 2, 1}, std::vector<int>{4, 3, 2, 2}),
    std::make_tuple(std::vector<int>{9}, std::vector<int>{1, 0}),
    std::make_tuple(std::vector<int>{9, 9, 9}, std::vector<int>{1, 0, 0, 0}),
    std::make_tuple(std::vector<int>{8, 9, 9, 9}, std::vector<int>{9, 0, 0, 0})
));

