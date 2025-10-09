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

        bool incrFlag {false};
        bool prepend {false};
        int addition = 0;
        for (auto iter = res.rbegin(); iter != res.rend(); ++iter)
        {
            auto& elem = *iter;
            if (!incrFlag)
            {
                incrFlag = true;
            }
            ++elem;

            if (elem < 9)
                break;

            elem = 0;
            if (iter + 1 == res.rend())
                prepend = true;
        }

        if (prepend)
        {
            std::vector<int> tmp(res.size() + 1);
            std::copy(res.begin(), res.end(), tmp.begin() + 1);
            tmp[0] = 1;
            res = tmp;
        }

        // auto iter = res.rbegin();
        // auto& elem = *iter;
        // ++elem;

        // if (elem < 9)
        // {
        //     return res;
        // }

        // int resInc {0};
        // // int addition = 1;
        // for (; iter != res.rend(); ++iter)
        // {
        //     auto& currElem = *iter;
        //     currElem = 0;
        //     ++currElem;

        //     if (10 != currElem)
        //         break;

        // }

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
    std::make_tuple(std::vector<int>{9, 9, 9}, std::vector<int>{1, 0, 0, 0})
));

