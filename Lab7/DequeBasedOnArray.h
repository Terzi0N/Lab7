#pragma once
#include "DequeBase.h"
template<typename T>
class DequeBasedOnArray : public DequeBase<T> {
	T *arr;
	int count;
	int end = 0, size = 0;
public:
	DequeBasedOnArray(int count); //инициализация
	DequeBasedOnArray(const DequeBasedOnArray &other);  //копирование
	DequeBasedOnArray(DequeBasedOnArray &&other); //перемещение
	DequeBasedOnArray &operator=(const DequeBasedOnArray &other); //присваивание
	DequeBasedOnArray &operator=(DequeBasedOnArray &&other); //присваивание с перемещением
	~DequeBasedOnArray(); //деструктор
	int GetSize();

	void PushFront(T element) override {
		for (int i = end; i > 0; i--) {
			arr[i] = arr[i - 1];
			arr[0] = element;
			end++;
			size++;
		}
	}
	
	void PushBack(T element) override {
		arr[end++] = element;
		end++;
		size++;
	}

	T PopFront(T element) override {
		if (size > 0) {
			for (int i = 0; i < size; ++i) {
				arr[i] = arr[i + 1];
			}
			size--;
		}
	}

	T PopBack(T element) override {
		if (size > 0) {
			arr[end] = 0;
			size--;
		}
	}

	T PeekFront() override {
		return arr[0];
	}

	T PeekBack() override {
		return arr[end];
	}

	bool CheckNotEmpty() override {
		return (size > 0);
	}

	friend ostream & operator <<(ostream & stream, const DequeBasedOnArray<T> &a);
};

template<typename T>
DequeBasedOnArray<T>::DequeBasedOnArray(int count)
	: count(count)
{
	arr = new T[count];
}

template<typename T>
DequeBasedOnArray<T>::~DequeBasedOnArray() {
	delete[] arr;
}

template<typename T>
DequeBasedOnArray<T>::DequeBasedOnArray(const DequeBasedOnArray &other) {
	arr = new T[other.count];
	count = other.count;
	end = other.end;
	size = other.size;
	for (int i = 0; i < count; ++i)
	{
		arr[i] = other.arr[i];
	}
}


template<typename T>
DequeBasedOnArray<T> &DequeBasedOnArray<T>::operator=(const DequeBasedOnArray &other) {
	if (this == &other) {
		return *this;
	}
	delete[] arr;
	arr = new T[other.count];
	count = other.count;
	for (int i = 0; i < count; ++i) {
		arr[i] = other.arr[i];
	}
}


template<typename T>
DequeBasedOnArray<T> &DequeBasedOnArray<T>::operator=(DequeBasedOnArray &&other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] arr;
	arr = other.arr;
	count = other.count;
	other.arr = nullptr;
}

template<typename T>
DequeBasedOnArray<T>::DequeBasedOnArray(DequeBasedOnArray &&other) {
	arr = other.arr;
	count = other.count;
	other.arr = nullptr;
}

template<typename T>
int DequeBasedOnArray<T>::GetSize()
{
	return this->size;
}


template<typename T>
ostream & operator<< (ostream & stream, const DequeBasedOnArray<T> &a) {
	DequeTemplate<T> b = a;
	for (int i = 0; i < b.count; i++) {
		stream << b.arr[i] << " ";
	}
	return stream;
}
