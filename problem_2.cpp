/*
 *  Link: https://leetcode.com/problems/add-two-numbers/description/
*/

#include <cstdlib>

#include <gtest/gtest.h>

namespace
{
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool compareListNodes(const ListNode* lhs, const ListNode* rhs)
{
    if (nullptr == lhs && nullptr == rhs)
        return true;

    auto currLhs = lhs;
    auto currRhs = rhs;

    auto isEqual {true};

    while (currLhs != nullptr && currRhs != nullptr)
    {
        if ((currLhs != nullptr && nullptr == currRhs) || (nullptr == currLhs && currRhs != nullptr))
        {
            isEqual = false;
            break;
        }

        if (currLhs->val != currRhs->val)
        {
            isEqual = false;
            break;
        }

        currLhs = currLhs->next;
        currRhs = currRhs->next;
    }

    return isEqual;
}

ListNode* createListNode(std::initializer_list<int> list)
{
    if (std::empty(list))
        return new ListNode();

    auto listNode = new ListNode(*list.begin());
    auto res = listNode;

    for (auto iter = list.begin() + 1; iter != list.end(); ++iter)
    {
        res->next = new ListNode(*iter);
        res = res->next;
    }

    return listNode;
}

void printListRecursive(ListNode const* list)
{
    if (nullptr == list)
    {
        std::cout << "\n";
        return;
    }

    std::cout << list->val << " ";
    printListRecursive(list->next);
}
}

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (nullptr == l1 && nullptr == l2)
            return nullptr;

        auto currL1 = l1;
        auto currL2 = l2;
        auto res = new ListNode();
        auto currRes = res;
        auto rem {0};
        div_t dv {};

        while (currL1 != nullptr || currL2 != nullptr)
        {
            if (currL1)
            {
                currRes->val += currL1->val;
                currL1 = currL1->next;
            }

            if (currL2)
            {
                currRes->val += currL2->val;
                currL2 = currL2->next;
            }

            currRes->val += rem;

            if (currRes->val > 9)
            {
                dv = std::div(currRes->val, 10);
                rem = dv.quot;
                currRes->val = dv.rem;
            }
            else
            {
                rem = 0;
            }

            if (nullptr == currL1 && nullptr == currL2)
                break;

            currRes->next = new ListNode();
            currRes = currRes->next;
        }

        if (rem > 0)
        {
            if (rem > 9)
            {
                dv = std::div(rem, 10);
                currRes->val = dv.quot;
                currRes->next = new ListNode(dv.rem);
            }
            else
            {
                currRes->next = new ListNode(rem);
            }
        }
        return res;
    }
};

struct TestWithParameters : public testing::TestWithParam<std::tuple<ListNode*, ListNode*, ListNode*>> {};
TEST_P(TestWithParameters, Problem_2)
{
    auto [list1, list2, expectList] = GetParam();

    Solution solver {};
    const auto res = solver.addTwoNumbers(list1,  list2);
    printListRecursive(res);

    EXPECT_TRUE(compareListNodes(res, expectList));
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple(createListNode({1, 2, 3}), createListNode({4, 5, 6}), createListNode({5, 7, 9})),
    std::make_tuple(createListNode({2, 4, 3}), createListNode({5, 6, 4}), createListNode({7, 0, 8})),
    std::make_tuple(createListNode({0}), createListNode({0}), createListNode({0})),
    std::make_tuple(createListNode({9,9,9,9,9,9,9}), createListNode({9,9,9,9}), createListNode({8,9,9,9,0,0,0,1}))
));
