#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>
#include<vector>

using namespace std;

ifstream in("Date.txt"); 
ofstream out("SortedDate_1.txt"); 

struct Date
{
  int d;
  int m;
  int y;
};

struct people
{
  string surname;
  string occ;
  
  Date date_of_birth;

  int exp;
  int salary;
};

Date Str_to_Date(string str )
{
  Date x;
  string temp;

  temp = str.substr(0, 2);
  x.d = atoi(temp.c_str() );

  temp = str.substr(3, 2);
  x.m = atoi(temp.c_str());

  temp = str.substr(6, 4);
  x.y = atoi(temp.c_str() );
  
  return x;
}

vector<people> inFile()
{
  vector<people> x;
  people temp;

  while(in.peek() != EOF)
  {
    in >> temp.surname;
    in>>temp.occ;
    string tmp;
    in >> tmp;
    temp.date_of_birth = Str_to_Date(tmp);
    in >> temp.exp;
    in >> temp.salary;
    x.push_back(temp);
  }

  return x;
}

bool operator < (people a, people b) 
{
  if (a.salary < b .salary) return true;
  
  return false;
}

bool operator > (people a, people b)
{
  if (a.salary > b .salary) return true;
  
  return false;
}


void print(people x)
{
  out << setw(10) << left << x.surname;
  out << setw(10) << left << x.occ;

  if (x.date_of_birth.d < 10) out << left << "0" << x.date_of_birth.d << ".";
  else out << left << x.date_of_birth.d << ".";

  if (x.date_of_birth.m < 10) out << "0" << x.date_of_birth.m << ".";
  else out << x.date_of_birth.m << ".";

  out << left << setw(6) << x.date_of_birth.y;//       6        
  out << left << setw(6) << x.exp;//    
  out << left << setw(10) << x.salary << endl;//        
}

void quick_sort(vector<people> &mas, int first, int last)
{
  people mid = mas[last - first],count;
  int f=first, l=last;
  mid=mas[(f+l) / 2];
  do
  {
    while (mas[f] < mid) f++;
    while (mas[l] > mid) l--;

    if (f<=l)
    {
        count=mas[f];
        mas[f]=mas[l];
        mas[l]=count;
        f++;
        l--;
    }
  } 
  while (f<l);
  if (first<l) quick_sort(mas, first, l);
  if (f<last) quick_sort(mas, f, last);
}

int main()
{
    vector<people> x;
    x = inFile () ;
    int size = x.size();
    cout << size;
    quick_sort (x,0,size-1);
    for(int i = 0; i < size; i++) print (x[i ]);

    return 0;
}