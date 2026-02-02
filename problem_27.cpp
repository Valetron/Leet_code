/*
 *  Link: https://leetcode.com/problems/remove-element/description/
*/

#include <tuple>
#include <string>

#include <gtest/gtest.h>

class Solution
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
      size_t notEqualVal {0};

      std::vector<int> tmp {};

      const auto numsSize = nums.size();
      for (size_t i = 0; i < numsSize; ++i)
      {
          if (val != nums[i])
          {
              ++notEqualVal;
              tmp.push_back(nums[i]);
          }
      }

      nums = tmp;

      return notEqualVal;
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<std::vector<int>, int, int, std::vector<int>>> {};
TEST_P(TestWithParameters, TestName)
{
  auto [inputData, elemToRemove, expectRetNum, expectRes] = GetParam();
  Solution solver {};
  const auto res = solver.removeElement(inputData, elemToRemove);
  ASSERT_EQ(res, expectRetNum);
  EXPECT_EQ(inputData, expectRes);
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
  std::make_tuple(std::vector<int>{3, 2, 2, 3}, 3, 2, std::vector<int>{2, 2}),
  std::make_tuple(std::vector<int>{0, 1, 2, 2, 3, 0, 4, 2}, 2, 5, std::vector<int>{0, 1, 3, 0, 4})
));

