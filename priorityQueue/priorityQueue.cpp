#ifndef PRIORITYQUEUE_CPP_INCLUDED
#define PRIORITYQUEUE_CPP_INCLUDED

#include "priorityQueue.h"

template <class Type>
void priorityQueue<Type>::enQueue(const Type &x)
{
	if(currentSize == maxSize) doubleSpace();
	int hole = ++currentSize;
	while(hole != 1){
		if(array[hole / 2] > x){
			array[hole] = array[hole / 2];
			hole /= 2;
		}
		else break;
	}
	array[hole] = x;
}


template <class Type>
void priorityQueue<Type>::percolateDown(int hole)
{
	if(hole < 1 || hole > currentSize) return;
	Type tmp = array[hole];
	int child;
	while(hole * 2 <= currentSize)
	{
		child = hole * 2;
		if(child != currentSize && array[child + 1] < array[child])
			child++;

		if (array[child] < tmp)
		{
			array[hole] = array[child];
			hole = child;
		}
		else break;
	}
	array[hole] = tmp;

}


template <class Type>
Type priorityQueue<Type>::deQueue()
{
	Type tmp = array[1];
	array[1] = array[currentSize--];
	percolateDown(1);
	return tmp;
}

template <class Type>
void priorityQueue<Type>::buildHeap()
{
	for (int i = currentSize / 2; i > 0; --i)
	{
		percolateDown(i);
	}
}

template <class Type>
priorityQueue<Type>::priorityQueue(const Type *data, int size)
{
	maxSize = size + 10;
	
	currentSize = size;
	array = new Type[maxSize];

	for (int i = 0; i < size; ++i)
	{
		array[i + 1] = data[i];
	}
	buildHeap();
}


#endif // PRIORITYQUEUE_H_INCLUDED