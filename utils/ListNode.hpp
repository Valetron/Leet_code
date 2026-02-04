#ifndef UTILS_LIST_NODE_HPP
#define UTILS_LIST_NODE_HPP

#include <initializer_list>

namespace utils
{

struct ListNode
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createListNode(std::initializer_list<int> list);
void printListRecursive(ListNode const* list);
bool compareListNodes(const ListNode* lhs, const ListNode* rhs);

} // namespace utils
#endif // UTILS_LIST_NODE_HPP
