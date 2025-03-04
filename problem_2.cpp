/*
 *  Link: https://leetcode.com/problems/add-two-numbers/description/
*/

#include <gtest/gtest.h>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

void printList(ListNode const* list)
{
    if (nullptr == list)
        return;

    auto curr = list;
    while (curr != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";
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

void addFirstToSecond(ListNode const* list1, ListNode* list2)
{
    if (nullptr == list1)
    {
        return;
    }

    // list2->val
    // printListRecursive(list->next);
}

// class Solution
// {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//     {
//         if (nullptr == l1 && nullptr == l2)
//             return nullptr;

//         if (l1->next)

//         auto res = new ListNode();

//         return res;
//     }
// };

struct TestWithParameters : public testing::TestWithParam<std::tuple<ListNode*, ListNode*, ListNode*>> {};
TEST_P(TestWithParameters, Problem_2)
{
    auto [list1, list2, expectList] = GetParam();
    printListRecursive(expectList);
    SUCCEED();
}
INSTANTIATE_TEST_SUITE_P(TestGroupName, TestWithParameters, testing::Values(
    std::make_tuple(createListNode({1, 2, 3}), createListNode({4, 5, 6}), createListNode({5, 7, 9})),
    std::make_tuple(createListNode({2, 4, 3}), createListNode({5, 6, 4}), createListNode({7, 0, 8})),
    std::make_tuple(createListNode({0}), createListNode({0}), createListNode({0})),
    std::make_tuple(createListNode({9,9,9,9,9,9,9}), createListNode({9,9,9,9}), createListNode({8,9,9,9,0,0,0,1}))
));
