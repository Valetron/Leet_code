#ifndef UTILS_LIST_NODE_HPP
#define UTILS_LIST_NODE_HPP

#include <initializer_list>

struct ListNode
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

static ListNode* createListNode(std::initializer_list<int> list);
static void printListRecursive(ListNode const* list);

#endif // UTILS_LIST_NODE_HPP
