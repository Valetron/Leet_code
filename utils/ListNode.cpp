#include "ListNode.hpp"

#include <iostream>
#include <iterator>

namespace utils
{

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

} // namespace utils
