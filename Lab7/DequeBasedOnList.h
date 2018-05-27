#pragma once
#include "DequeBase.h"
#include "List.h"
template<typename T>
class DequeBasedOnList : public DequeBase<T> {
	List<T> *Deque;
	int count;
public:
	DequeBasedOnList(int count)
		: Deque(), count(count) { }

	DequeBasedOnList(const DequeBasedOnList &other)	{
		Queue = other.Queue;
		count = other.count;
	}

	DequeBasedOnList(DequeBasedOnList &&other) {
		Queue = other.Queue;
		count = other.count;
	}

	DequeBasedOnList<T> &operator=(const DequeBasedOnList &other) {
		if (this == &other)
		{
			return *this;
		}
		count = other.count;
		Queue = other.Queue;
	}

	DequeBasedOnList<T> &operator=(DequeBasedOnList &&other) {
		if (this == &other)
		{
			return *this;
		}
		count = other.count;
		Queue = other.Queue;
	}

	~DequeBasedOnList();

	void Push(T element) override {
		if (Queue->GetSize() < count) {
			Queue->Push(element, Queue->GetSize());
		}
	}

	T Pop() override {
		return Queue->Remove(1);
	}

	T Peek() override {
		return Queue->Peek(1);
	}

	bool CheckNotEmpty() override {
		return Queue->CheckNoEmptyList();
	}

	friend ostream & operator << (ostream & stream, const DequeBasedOnList<T> &a);
};

template<typename T>
DequeBasedOnList<T>::~DequeBasedOnList()
{
	delete Deque;
}

template<typename T>
ostream & operator << (ostream & stream, const DequeBasedOnList<T> &a) {
	DequeBasedOnList<T> b = a;
	for (int i = 0; i < b.count; i++) {
		stream <<b.Pop() << "\n";
	}

	return stream;
}

