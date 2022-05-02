#include <iostream>
#include <climits>

using namespace std;

struct node {

	int data;
	node *prev, *next;

};

class List {

	public:

		node *head, *tail;
		int length;

		// Конструктор
		List() {

			head = tail = NULL;
			length = 0;

		}

		// Деструктор
		~List() {

			node *p;

			while (head) {
				
				p = head;
				head = head -> next;
				head -> prev = NULL;

				delete p;

			}	

		}

		// Добавление элемента в конец списка
		void push_back(int data) {

			node *p = new node;

			p -> data = data;
			p -> next = NULL;

			if (!head && !tail) {

				p -> prev = NULL;
				head = p;

			}
			else {

				tail -> next = p;
				p -> prev = tail;

			}

			tail = p;
			length++;

		}

		// Добавление элемента на после определенного элемента
		void insert_after(node *p, int data) {

			node *r = new node;

			r -> data = data;

			if (p == tail) {

				push_back(data);
			
			}
			else {

				p -> next -> prev = r;
				r -> next = p -> next;
				r -> prev = p;
				p -> next = r;

			}

			length++;

		}

		// Удаление элемента 
		void delete_(node *p) {

			if (p == head) {

				p -> next -> prev = NULL;
				head = p -> next;

			}
			else if (p == tail) {

				p -> prev -> next = NULL;
				tail = p -> prev;

			}
			else if (p == head && p == tail) {

				head = tail = NULL;

			}
			else {

				p -> prev -> next = p -> next;
				p -> next -> prev = p -> prev;
		
			}

			
			delete p;
			length--;

		}

		// Вывод списка
		void print() {

			node *r = head;

			while (r) {

				cout << r -> data << " ";

				r = r -> next;

			}

			cout << endl;

		}

		// Разворот списка
		void reverse() {

			if (head == tail) return;

			node *a = head -> next;
			node *tmp = NULL;

			while (a != tail) {

				tmp = a -> prev;
				a -> prev = a -> next;
				a -> next = tmp;

				a = a -> prev;
			}

			tmp = head;
			head = tail;
			head -> next = tail -> prev;
			head -> prev = NULL;
			
			tail = tmp;
			tail -> next = NULL;
			tail -> prev = tmp -> next;


		}

		// Поиск минимального элемента
		int min() {

			node *p = head;
			int min_ = INT_MAX;

			while (p) {

				if (p -> data < min_) {
					min_ = p -> data;
				}

				p = p -> next;

			}

			return min_;

		}

		// Поиск максимального элемента
		int max() {

			node *p = head;
			int max_ = INT_MIN;

			while (p) {

				if (p -> data > max_) {
					max_ = p -> data;
				}

				p = p -> next;

			}

			return max_;

		}

};

void task_1(List *&list) {

	list -> reverse();
	list -> print();

}

void task_2(List *&list) {

	int answer;
	node *p = list -> head;

	while (p != NULL) {

		if ((p -> data) % 2 == 0) {
			answer = p -> data;
		}

		p = p -> next;

	}

	cout << "Answer: " << answer << endl;

}

void task_3(List *&list) {

	int min_ = list -> min();
	node *p = list -> head;

	while (p) {

		if (p -> data == min_) {

			list -> delete_(p);
			break;

		}

		p = p -> next;


	}

	list -> print();

}

void task_4(List *&list) {

	int max_ = list -> max();
	node *p = list -> head;
	node *r = NULL;

	while (p) {

		if (p -> data == max_) {

			r = p;

		}

		p = p -> next;


	}

	list -> insert_after(r, 0);

	list -> print();


}

int main() {

	// Инициализация списка
	List *list = new List;

	// Выбор номера упражнения
	unsigned int task;
	cout << "Task: ";
	cin >> task;

	// заполнение списка
	unsigned int n;
	cout << "Number of elements: ";
	cin >> n;

	int data;

	for (int i = 0; i < n; i++) {

		cin >> data;

		list -> push_back(data);

	}

	switch (task) {

		case 1:
			task_1(list);
			break;
		case 2:
			task_2(list);
			break;
		case 3:
			task_3(list);
			break;
		case 4:
			task_4(list);
			break;		

	}

	return 0;
}