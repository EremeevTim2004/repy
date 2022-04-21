#include <iostream>

using namespace std;

struct stack
{
	int data;

	stack* next; 
};

// Добавление элемента в стек
void push(stack *&h, int data)
{
	stack *r = new stack;

	r -> data = data;
	r -> next = h;

	h = r;
}

// Извлечение элемента из стека
int pop(stack *&h)
{
	int i = h -> data;
	stack *r = h;

	h = h -> next;

	delete r;

	return i;
}

// Переворот стека
void reverse(stack *&h)
{
	stack *head = NULL;

	while(h)
	{
		push(head, pop(h));
	}

	h = head;
}

// Заполнение стека
void fill(stack *&h, int n)
{
	int x;

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		push(h,x);
	}
}

// Вывод стека
void print(stack *&h)
{
	while (h)
	{
		cout << h -> data << " ";

		h = h -> next; 
	}

	cout << endl;
}

// Является ли чисто простым
bool isPrime(int n)
{
	unsigned int counter = 1;

	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0) 
		{
			counter++;
		}
	}

	return counter == 2;
}

// Решение задачи
stack* solve(stack *&h)
{
	stack *result = NULL;

	int data;

	while (h)
	{
		data = h -> data;

		if (isPrime(data))
		{
			h = h -> next;

			continue;
		}

		push(result, data);

		h = h -> next;
	}

	return result;
}

/*Создать стек, содержащий целые числа.
* Удалить из стэка все простые числа.*/
int main()
{
	stack *h = NULL;

	unsigned int n;

	cout << "Number of elements: ";
	cin >> n;

	fill(h, n); 

	stack *result = solve(h);

	print(result);

	return 0;
}	