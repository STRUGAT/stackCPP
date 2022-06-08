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
	Stack() { // конструктор по умолчанию
		top = nullptr;
	}

	Stack(const Stack& object) { // констурктор копирования
		NodeStack<T>* p; // двигается по спику
		NodeStack<T>* p2;
		NodeStack<T>* p3;

		top = nullptr;
		p = object.top;
		p3 = nullptr;

		while (p != nullptr) {
			p2 = new NodeStack<T>; // формирование второго узла
			p2->item = p->item;
			p2->next = nullptr;

			if (top == nullptr) { // создание очереди
				top = p2;
				p3 = p2;
			}
			else {
				p3->next = p2;
				p3 = p3->next;
			}

			p = p->next; // переход на следующий элемент
		}
	}

	Stack<T>& operator =(const Stack<T>& object) { // оператор присваивания
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

	void Push(T item) { // добавление элемента
		NodeStack<T>* p;
		p = new NodeStack<T>;
		p->item = item;
		p->next = top;
		top = p;
	}

	T Pop() { // получение элемента
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

	int Count() { // количество элементов
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
	void Print() { // вывод в консоль
		if (top == nullptr)
			cout << "стек пуст" << endl;
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

	void Clear() { // очистка
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

	~Stack() { // дестурктор
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
	cout << "стек: ";
	stack.Print();
	cout << "количество элементов: " << stack.Count() << endl;
	Stack<int> copy = stack;
	cout << "конструктор копирования: ";
	copy.Print();
	stack.Clear();
	stack = copy;
	cout << "оператор =: ";
	stack.Print();
	int item = stack.Pop();
	cout << "последний элемент:" << item << endl;
};
