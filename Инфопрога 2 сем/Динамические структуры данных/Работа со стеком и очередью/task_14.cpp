#include <iostream>

using namespace std;

struct queue
{
	char data;

	queue* next;
};

// Добавление элемента в очередь
void push(queue *&h, queue *&t, char data)
{
	queue *r = new queue;

	r -> data = data;
	r -> next = NULL;

	if (!h && !t)
	{
		h = t = r;
	}
	
	else
	{
		t -> next = r;
		
		t = r;
	}
}

// Извлечение элемента из очереди
char pop(queue *&h, queue *&t)
{
	queue *r = h;

	char i = h -> data;

	h = h -> next;

	if (!h)
	{
		t = NULL;
	}

	delete r;

	return i;
}

// Заполнение очереди
void fill(queue *&h, queue *&t, unsigned int n)
{
	char x;

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		push(h, t, x);
	}
}

// Вывод очереди
void print(queue *h, queue *t)
{
	char data;

	while (h)
	{
		data = h -> data;
		cout << data << " ";

		h = h -> next;
	}

	cout << endl;
}

// Решение задачи
void solve(queue *&h, queue *&t)
{
	queue* head = NULL;
	queue* tail = NULL;

	char data;

	while (h)
	{
		data = h -> data;

		if (!(isdigit(data) || isalpha(data)))
		{
			h = h -> next;

			continue;
		}
		push(head, tail, data);

		h = h -> next;
	}

	print(head, tail); 

}

/*Создать очередь, содержащую любые символы.
* Удалить из очереди все элементы, не являющиеся буквой или цифрой.*/
int main() {

	queue *h = NULL;
	queue *t = NULL;

	unsigned int n;
	cout << "Number of elements: ";
	cin >> n;

	fill(h, t, n); 
	solve(h, t);

	return 0;
}