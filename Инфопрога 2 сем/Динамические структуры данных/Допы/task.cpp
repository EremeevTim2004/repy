#include <iostream>
#include <string>

using namespace std;

struct stack {

	char data;
	stack *next;

};

// Добавление элемента в стек
void push_back(stack *&h, char data) {

	stack *r = new stack;

	r -> data = data;
	r -> next = h;

	h = r; 

}

// Извлечение элемента из стека
char pop(stack *&h) {

	char data = h -> data;

	stack *r = h;
	h = h -> next;
	delete r;

	return data;

}

// Вывод стека
void print(stack *h) {

	while (h) {

		cout << h -> data << " ";

		h = h -> next;

	}

}

// Расчет размера стека
unsigned int size(stack *s) {

	unsigned int result = 0;

	while (s) {

		result++;
		s = s -> next;

	}

	return result;

}

// Проверка того, что символ является оператором
bool isoperator(char chr) {
	return (chr == '+' || chr == '-' || chr == '*' || chr == '/');
}

// Приоритет операции в выражении
unsigned int prior(char chr) {

	if (chr == '(') return 1;
	else if (chr == '+' || chr == '-') return 2;
	else if (chr == '*' || chr == '/') return 3;
	else return 10;

}

// Проверка того, что стек содержит операции, приоритет которых ниже,
// чем у указанного оператора
bool is_lower_priority(stack *s, char chr) {

	unsigned int ref_priority = prior(chr);
	unsigned int priority;

	while (s) {

		priority = prior(s -> data);

		if (priority > ref_priority) return false;

		s = s -> next;

	}

	return true;

}

int main() {


	string expression;
	cout << "Expression: ";
	cin >> expression;

	stack *s = NULL;
	string result = "";
	unsigned int priority;
	unsigned int head_priority;

	for (int i = 0; i < expression.length(); i++) {

		priority = prior(expression[i]);

		// Операнд записываем в результирующую строку
		if (isdigit(expression[i]) || isalpha(expression[i])) {

			result += expression[i];

		}
		// Открывающую скобку записываем в стек
		else if (expression[i] == '(') {

			push_back(s, expression[i]);

		}
		else if (isoperator(expression[i])) {

			// Если стек пустой, то знак операции записываем в стек
			if (size(s) == 0) {

				push_back(s, expression[i]);

			}
			else {

				head_priority = prior(s -> data);

				// Если приоритет операции > приоритета элемента вершины стека,
				// то записываем операцию в стек
				if (priority > head_priority) {

					push_back(s, expression[i]);

				}
				// иначе перемещаем элементы из стека в строку результата и потом пишем в стек
				else {

					while (head_priority >= priority && s) {

						result += pop(s);
						
						if (s) {

							head_priority = prior(s -> data);

						}
						
					}

					push_back(s, expression[i]);

				}

			}

		}
		else if (expression[i] == ')') {

			while (s -> data != '(' && s) {

				result += pop(s);

			}

			if (s && s -> data == '(') {

				pop(s);	
			
			}

		}

	}

	while (s) {

		result += pop(s);

	}

	cout << "Result: " << result << endl;

	return 0;
}