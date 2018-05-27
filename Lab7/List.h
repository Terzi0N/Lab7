#pragma once
#include "Node.h"
template<typename T>
class List {
	Node<T> *head;
	int size = 0;
public:
	List(); //�������������
	List(const List &other);  //�����������
	List(List &&other); //�����������
	List &operator=(const List &other); //������������
	List &operator=(List &&other); //������������ � �����������
	~List(); //����������
	int GetSize();
	Node<T> *Find(int number);
	void Push(T element, int number);  //���������� ��������
	T Remove(int number);  //�������� ��������
	T Peek(int number);  //�������� ��������
	bool CheckNotEmptyList();  //�������� ������� ���������
	friend ostream & operator <<(ostream & stream, const List<T> &a); //�����
};

template<typename T>
List<T>::List()
	: head(NULL)
{
	head = new Node<T>;
	Node<T> *node = new Node<T>;
	head->next = node;
	head->previous = node;
	node->next = head;
	node->previous = head;
}

template<typename T>
List<T>::~List() //����������
{
	Node<T> *node = head;
	while (node->next != head)
	{
		node = node->next;
		delete node->previous;
	}
	delete head;
}

template<typename T>
List<T>::List(const List &other) //����������� �����������
{
	Node<T> oldOldNode = other.head;
	head = other.head;
	Node<T> newOldNode = head;
	size = other.size;
	while (oldNode->next != other.head)
	{
		Node<T> *newNewNode;
		newOldNode->next = newNewNode;
		newNewNode->previous = newOldist;
		newOldNode = newOldNode->next;
		newOldNode->data = oldOldNode->data;
	}
	newOldNode->next = head;
	head->previous = newOldNode;
}

template<typename T>
List<T>::List(List &&other) //�����������
{
	head = other.head;
	size = other.size;
	other.head = nullptr;
}

template<typename T>
List<T> &List<T>::operator=(const List &other) //������������
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	head = new Node<T>;
	Node<T> *node = head;
	while (node->next != head)
	{
		Node<T> *newNode = new Node<T>;
		Node<T> *oldNode = node->next;
		node->next = newNode;
		newNode->previous = node;
		newNode->data = oldNode->data;
	}
}

template<typename T>
List<T> &List<T>::operator=(List &&other) //������������ � ������������
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	head = other.head;
	other.head = nullptr;
}

template<typename T>
int List<T>::GetSize()
{
	return this->size;
}

template<typename T>
Node<T> *List<T>::Find(int number)
{
	Node<T> *node = head->next;
	for (int i = 0; i < number; i++)
	{
		node = node->next;
	}
	return node;
}

template<typename T>
void List<T>::Push(T element, int number)  //������� ��������
{
	Node<T> *previousNode = this->Find(number);
	Node<T> *nextNode = previousNode->next;
	Node<T> *newNode = new Node<T>;
	newNode->data = element;
	previousNode->next = newNode;
	newNode->previous = previousNode;
	newNode->next = nextNode;
	nextNode->previous = newNode;
	size++;
}

template<typename T>
T List<T>::Remove(int number)  //�������� ��������
{
	if (size > 0)
	{
		Node<T> *oldNode = this->Find(number);
		Node<T> *nextNode = oldNode->next;
		Node<T> *previousNode = oldNode->previous;
		T element = oldNode->data;
		nextNode->previous = previousNode;
		previousNode->next = nextNode;
		delete oldNode;
		size--;
		return element;
	}
	return 0;
}

template<typename T>
T List<T>::Peek(int number)  //�������� ��������
{
	Node<T> *node = this->Find(number);
	return node->data;
}

template<typename T>
bool List<T>::CheckNotEmptyList()  //�������� ������� ���������
{
	return (size > 0);
}

template<typename T>
ostream & operator << (ostream & stream, const List<T> &a) //�����
{
	List<T> b = a;
	for (int i = 0; i < b.size; i++) {
		stream << b.Remove() << "\n";
	}
	return stream;
}







