#pragma once
#include "iostream"
#include "conio.h"
using namespace std;
template<typename T>
class DequeBase
{
public:
	virtual void PushFront(T element) = 0; //добавление в начало
	virtual void PushBack(T element) = 0; //добавление в конец
	virtual T PopFront() = 0; //удаление первого элемента
	virtual T PopBack() = 0; //удаление последнего элемента
	virtual T PeekFront() = 0; //просмотор первого элемента
	virtual T PeekFront() = 0; //просмотор последнего элемента
	virtual bool CheckNotEmpty() = 0; //Проверка наличия элементов
};
