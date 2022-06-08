#include <iostream>

using namespace std;

template <typename T>
struct NodeStack {
	T item;
	NodeStack<T>* next;
};

template <typename T>
class Stack {
	
private:
	NodeStack<T>* top;

public:
	Stack() { // ����������� �� ���������
		top = nullptr;
	}

	Stack(const Stack& object) { // ����������� �����������
		NodeStack<T>* p; // ��������� �� �����
		NodeStack<T>* p2;
		NodeStack<T>* p3;

		top = nullptr;
		p = object.top;
		p3 = nullptr;

		while (p != nullptr) {
			p2 = new NodeStack<T>; // ������������ ������� ����
			p2->item = p->item;
			p2->next = nullptr;

			if (top == nullptr) { // �������� �������
				top = p2;
				p3 = p2;
			}
			else {
				p3->next = p2;
				p3 = p3->next;
			}

			p = p->next; // ������� �� ��������� �������
		}
	}

	Stack<T>& operator =(const Stack<T>& object) { // �������� ������������
		if (top != nullptr)
			Clear();
		NodeStack<T>* p;
		NodeStack<T>* p2;
		NodeStack<T>* p3;
		top = nullptr;
		p3 = nullptr;
		p = object.top;
		while (p != nullptr) {
			p2 = new NodeStack<T>;
			p2->item = p->item;
			p2->next = nullptr;

			if (top == nullptr) {
				top = p2;
				p3 = p2;
			}
			else {
				p3->next = p2;
				p3 = p3->next;
			}
			p = p->next;
		}
		return *this;
	}

	void Push(T item) { // ���������� ��������
		NodeStack<T>* p;
		p = new NodeStack<T>;
		p->item = item;
		p->next = top;
		top = p;
	}

	T Pop() { // ��������� ��������
		if (top == nullptr)
			return 0;
		NodeStack<T>* p;
		T item;
		item = top->item;
		p = top;
		top = top->next;
		delete p;
		return item;
	}

	int Count() { // ���������� ���������
		if (top == nullptr)
			return 0;
		else {
			NodeStack<T>* p = top;
			int count = 0;
			while (p != nullptr) {
				count++;
				p = p->next;
			}
			return count;
		}
	}
	void Print() { // ����� � �������
		if (top == nullptr)
			cout << "���� ����" << endl;
		else {
			NodeStack<T>* p;
			p = top;
			while (p != nullptr) {
				cout << p->item << " ";
				p = p->next;
			}
			cout << endl;
		}
	}

	void Clear() { // �������
		NodeStack<T>* p;
		NodeStack<T>* p2;
		p = top;
		while (p != nullptr) {
			p2 = p;
			p = p->next;
			delete p2;
		}
		top = nullptr;
	}

	~Stack() { // ����������
		Clear();
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Stack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	cout << "����: ";
	stack.Print();
	cout << "���������� ���������: " << stack.Count() << endl;
	Stack<int> copy = stack;
	cout << "����������� �����������: ";
	copy.Print();
	stack.Clear();
	stack = copy;
	cout << "�������� =: ";
	stack.Print();
	int item = stack.Pop();
	cout << "��������� �������:" << item << endl;
};
