#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
 
//Считает (a * b) % c с учетом того, что a * b может вызвать переполнение 
int mulmod(int a, int b, int mod) {
    
    int x = 0,y = a % mod;
    
    while (b > 0){

        if (b % 2 == 1){    
            x = (x + y) % mod;
        }

        y = (y * 2) % mod;
        b /= 2;
    
    }

    return x % mod;

}

// Возведение в степень
int modulo(int base, int exponent, int mod) {
    
    int x = 1;
    int y = base;
    
    while (exponent > 0) {

        if (exponent % 2 == 1) {
            x = (x * y) % mod;
        }

        y = (y * y) % mod;
        exponent = exponent / 2;
    
    }
   
    return x % mod;

}
 
// Тест на простоту Миллера-Рабина,
bool Miller(int p,int iteration) {
    
    if (p < 2) {

        return false;
    
    }
    
    if (p != 2 && p % 2==0) {

        return false;
    
    }
    
    int  s = p - 1;
    
    while (s % 2 == 0){
        s /= 2;
    }

    for (int i = 0; i < iteration; i++) {

        int a = rand() % (p - 1) + 1, temp = s;
        int mod = modulo(a, temp, p);
        
        while (temp != p - 1 && mod != 1 && mod != p - 1) {

            mod = mulmod(mod, mod, p);
            temp *= 2;
        
        }
        
        if (mod != p - 1 && temp % 2 == 0) {

            return false;
        
        }
    
    }
    
    return true;

}

int main() {

    int iteration = 5;
    
    int num;
    cout << "Enter integer to test primality: ";
    cin >> num;
    
    if (Miller(num, iteration)){
        cout << num << " is prime"<<endl;
    }
    else{
        cout<<num<<" is not prime"<<endl;
    }

    return 0;

}
