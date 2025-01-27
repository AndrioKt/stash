#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>

class List
{
public:
	List();
	~List();
	int GetSize() { return Size; }
	void push_back(T data);//����� ���������� ������ � ����� ������ (������� ������� � ����� ������)

	T& operator[](const int index);
private:
	
	template <typename T>//������� ����� note ���������
	class Node 
	{//�������� ��������� ����� "����", ��� �� �� ��� �������� ������ � ������ List
	public:
		Node* pNext; //�������� ��������� �� ��������� �������
		T data;
		Node(T data=T(), Node *pNext=nullptr)//�� ��������� � ������������ ������� nullptr ��� ���������� ��������
		{//� data �� ��������� ��������� T(), ����� ������� ���� ���� ����� ������������ �����, �� ����� ��������� ����������� �� ���������
			this->data = data;
			this->pNext = pNext;
		}

	};
	int Size;
	Node<T> *head;//�������� ������ ������� ��������. ��� ������������� ���� ������ �, ��������� � ����� List ������� ��������� (� ��� �� ������ ��� �����������, � ��������� � ��� ���� ������ �)
};


int main()
{
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(22);

	cout << lst[2] << endl;
	return 0;
}


//********************************************************
//********************************************************

template <typename T>
List<T>::List()
{
	Size = 0;//������� ���������� �����
	head = nullptr;//�� ��������� ������ ������� ����� ����� �� ���������
}

template <typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) //��������� ������ �� ������
	{
		head = new Node<T>(data);//���� ������ ������� ������, �� ������� ���
	}
	else
	{
		
		// ����� ������� ������� ������� � ����������� ���������

		while (current ->pNext !=nullptr)
		{//� ����� ���������� ���� ������ ���� �� ������ �� ����� (�� nullptr)
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);//����� �� ����� �������� ��������� �������
	}
	Size++; //�������� ������� ���������� ���������
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;// �������� �� �� � ����� ���� �� ��������� (��� �������� ������ ���� ��������)
	while (current != nullptr)
	{
		if (counter == index)//����� ������� ����� ����� ���������� �������, ���������� ������ ����� ��������
		{
			return current->data;
		}
		//����� �� ����������� � ������� ����� ���������� ��������
		current = current->pNext;
		counter++;
	}
}
