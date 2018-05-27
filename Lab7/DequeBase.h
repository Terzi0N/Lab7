#pragma once
#include "iostream"
#include "conio.h"
using namespace std;
template<typename T>
class DequeBase
{
public:
	virtual void PushFront(T element) = 0; //���������� � ������
	virtual void PushBack(T element) = 0; //���������� � �����
	virtual T PopFront() = 0; //�������� ������� ��������
	virtual T PopBack() = 0; //�������� ���������� ��������
	virtual T PeekFront() = 0; //��������� ������� ��������
	virtual T PeekFront() = 0; //��������� ���������� ��������
	virtual bool CheckNotEmpty() = 0; //�������� ������� ���������
};
