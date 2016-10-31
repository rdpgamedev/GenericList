#include "GenericList.h"

template <typename ItemType>
GenericList<ItemType>::GenericList()
{
  _head = std::shared_ptr<node>();
  _tail = std::shared_ptr<node>();
}

template <typename ItemType>
GenericList<ItemType>::~GenericList()
{
  std::shared_ptr<node> current_node = _head;
  while (pop()) {}
  _head.reset();
  _tail.reset();
}

//Pushes new node onto end of list
template <typename ItemType>
void GenericList<ItemType>::push(ItemType item)
{
  std::shared_ptr<node> pushed_node(new node);
  pushed_node->item = item;
  pushed_node->next = std::shared_ptr<node>();
  if (!_head) 
  {
    _head = pushed_node;
  }
  if (_tail)
  {
    _tail->next = pushed_node;
  }
  _tail = pushed_node;
  ++_count;
}


//Returns head item from list and pops head node of the list
//If list is empty, returns NULL
template <typename ItemType>
ItemType GenericList<ItemType>::pop()
{
  //check if list contains something
  if (_head) {
    ItemType popped = _head->item;
    std::shared_ptr<node> temporary_node = _head;
    _head = _head->next;
    temporary_node.reset();
    --_count;
    return popped;
  }
  else //list is empty
  {
    return NULL;
  }
}

template <typename ItemType>
unsigned _int64 GenericList<ItemType>::count()
{
  return _count;
}
