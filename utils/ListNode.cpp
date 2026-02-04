#include "ListNode.hpp"

#include <iostream>
#include <iterator>

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
