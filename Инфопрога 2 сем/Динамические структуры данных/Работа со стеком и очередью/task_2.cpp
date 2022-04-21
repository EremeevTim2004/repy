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

// Проверка на четность
bool isEven(int n)
{
	return n % 2 == 0;
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

// Решение задачи
stack* solve(stack *&h)
{
	// reverse(h);
	stack *result = NULL;
	stack *head_ref = h;

	int data;

	while (h != nullptr)
	{
		data = h -> data;

		if (!isEven(data))
		{
			push(result, data);
		}
		
		h  = h -> next;
	}

	h = head_ref;

	while (h != nullptr)
	{
		data = h -> data;

		if (isEven(data))
		{
			push(result, data);	
		}

		h = h -> next;

	} 

	return result;
}

/*Создайтб стэк, содержащий целые числа.
* В новый стэк вывести сначала чётные, а потом не чётные числа*/
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