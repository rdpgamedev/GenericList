#pragma once
#include <memory>

template <typename ItemType>
class GenericList
{
public:
  GenericList();
  ~GenericList();
  void push(ItemType item);
  ItemType pop();
  unsigned _int64 count();

private:
  struct node {
    ItemType item;
    std::shared_ptr<node> next;
  };
  std::shared_ptr<node> _head;
  std::shared_ptr<node> _tail;
  unsigned _int64 _count;
};
#include "GenericList.cpp"
