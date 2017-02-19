#pragma once

# include <vector>
# include <algorithm>

template <typename T>
class			Heap
{
private :
  typedef typename std::vector<T*>::const_iterator const_iterator;
  std::vector<T*>	_heap;
public :
  Heap();
  ~Heap();
  void		insert(T*);
  T*		getLeftChild(T*);
  T*		getRightChild(T*);
  T*		getParent(T*);
  T*		operator[](unsigned int);
  T*		getMin();
  size_t	size();
  bool		isEmpty();
  bool		find(T*);
private :
  void		swap(T*, T*);
};

template <typename T>
Heap<T>::Heap()
{
  // To get all the property from a heap, we need to initialize the first index
  _heap.push_back(NULL);
}

template <typename T>
Heap<T>::~Heap()
{
}

template <typename T>
void		Heap<T>::insert(T* toInsert)
{
  T*		parent = NULL;
  
  _heap.push_back(toInsert);
  while ((parent = getParent(toInsert)) != NULL
	 && *parent > *toInsert)
    {
      swap(parent, toInsert);
    }
}

template <typename T>
T*		Heap<T>::getMin()
{
  T* tmp = _heap[1];
  std::vector<T*> transfer;

  while (_heap.size() > 2)
    {
      transfer.push_back(_heap.back());
      _heap.pop_back();
    }
  _heap.pop_back();
  while (transfer.size() > 0)
    {
      insert(transfer.back());
      transfer.pop_back();
    }
  return tmp;
}

template <typename T>
void		Heap<T>::swap(T* first, T* second)
{
  int firstIndex = std::find(_heap.begin() + 1, _heap.end(), first) - _heap.begin();
  int secondIndex = std::find(_heap.begin() + 1, _heap.end(), second) - _heap.begin();

  T* tmp = first;
  _heap[firstIndex] = second;
  _heap[secondIndex] = tmp;
}

template <typename T>
T*	Heap<T>::getLeftChild(T* parent)
{
  const_iterator it = std::find(_heap.begin() + 1, _heap.end(), parent);
  if (it == _heap.end())
    return NULL;
  int parentIndex = it - _heap.begin();
  if (parentIndex * 2 < _heap.size())
    return _heap[parentIndex * 2];
  else
    return NULL;
}

template <typename T>
T*	Heap<T>::getRightChild(T* parent)
{
  const_iterator it = std::find(_heap.begin() + 1, _heap.end(), parent);
  if (it == _heap.end())
    return NULL;
  int parentIndex = it - _heap.begin();
  if (parentIndex * 2 + 1 < _heap.size())
    return _heap[parentIndex * 2 + 1];
  else
    return NULL;
}

template <typename T>
T*	Heap<T>::getParent(T* child)
{
  const_iterator it = std::find(_heap.begin() + 1, _heap.end(), child);
  if (it == _heap.end())
    return NULL;
  int childIndex = it - _heap.begin();
  if (childIndex / 2 < _heap.size()
      && childIndex > 1) {
    return _heap[childIndex / 2];
  } else {
    return NULL;
  }
}

template <typename T>
T*	Heap<T>::operator[](unsigned int n)
{
  return _heap[n + 1];
}

template <typename T>
size_t		Heap<T>::size()
{
  return _heap.size() - 1;
}

template <typename T>
bool		Heap<T>::isEmpty()
{
  return size() == 0;
}

template <typename T>
bool		Heap<T>::find(T* elem)
{
  const_iterator it = std::find(_heap.begin() + 1, _heap.end(), elem);
  return (it != _heap.end());
}
