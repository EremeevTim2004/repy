#include <iostream>
#include <climits>

using namespace std;

struct queue
{
	int data;

	queue* next;
};

// Добавление элемента в очередь
void push(queue *&h, queue *&t, int data)
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
int pop(queue *&h, queue *&t)
{
	queue *r = h;

	int i = h -> data;

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
	int x;

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		push(h, t, x);
	}
}

// Вывод очереди
void print(queue *h, queue *t)
{
	int data;

	while (h)
	{
		data = h -> data;
		cout << data << " ";

		h = h -> next;
	}

	cout << endl;
}

// Поиск максиимального элемента
int max(queue *h, queue *t)
{
	int max = INT_MIN;
	int data;

	while (h)
	{
		data = h -> data;

		if (data > max)
		{
			max = data;
		}

		h = h -> next;
	}

	return max;
}

// Поиск минимального элемента
int min(queue *h, queue *t)
{
	int min = INT_MAX;
	int data;

	while (h)
	{
		data = h -> data;

		if (data < min)
		{
			min = data;
		}

		h = h -> next;
	}

	return min;
}

// Решение задачи
void solve(queue *&h, queue *&t)
{
	int max_ = max(h, t);
	int min_ = min(h, t);

	int data;

	queue *head = NULL;
	queue *tail = NULL;

	while (h)
	{
		data = pop(h, t);

		if (data == max_)
		{
			push(head, tail, min_);
		}

		push(head, tail, data);
	}

	print(head, tail);
}

/*Создать очередь, содержащую целые числа.
* Перед каждым максимальным элементом вставить минимальный.*/
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