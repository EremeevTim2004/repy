#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void multiply(unsigned int F[2][2], unsigned int M[2][2]) {
   
   unsigned int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
   unsigned int b = F[0][0] * M[0][1] + F[0][1] * M[1][1];
   unsigned int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
   unsigned int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
   
   F[0][0] = a;
   F[0][1] = b;
   F[1][0] = c;
   F[1][1] = d;

}

void power(unsigned int F[2][2], unsigned int n) {

   if (n == 0 || n == 1)
      return;

   unsigned int M[2][2] = {{1,1},{1,0}};
   
   power(F, n / 2);
   multiply(F, F);
   
   if (n % 2 != 0)
      multiply(F, M);

}

// Рекуретное соотношение
unsigned int fib_rec(unsigned int n) {

	if (n <= 2) return 1;

	return fib_rec(n - 1) + fib_rec(n - 2);

}

// Золотое сечение 
unsigned int fib_gold(unsigned int n) {
    
	double PHI = 1.6180339;
 
	unsigned int f[6] = { 0, 1, 1, 2, 3, 5 };
    
    if (n < 6)
        return f[n];
 
    int t = 5, fn = 5;
 
    while (t < n) {
         fn = round(fn * PHI);
         t++;
    }
 
    return fn;  
}

// Матрицы
unsigned int fib_matrix(unsigned int n) {
   
   unsigned int F[2][2] = {{1,1},{1,0}};
   
   power(F, n - 1);
   
   return F[0][0];

}

int main() {

	unsigned int n;
	cout << "n: ";
	cin >> n;

	cout << "Через рекурсию: " << fib_rec(n) << endl;
	cout << "Через золотое сечение: " << fib_gold(n) << endl;
	cout << "Через матрицы: " << fib_matrix(n) << endl;


	return 0;
}