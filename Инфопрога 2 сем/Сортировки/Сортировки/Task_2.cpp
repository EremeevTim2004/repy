#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>
#include<vector>

using namespace std;

ifstream in("Date.txt"); 
ofstream out("SortedDate_2.txt"); 

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

bool operator < (people a, people b) // для второй задачи
{
  if (a.salary < b.salary) return true;
  if (a.salary == b.salary&&a.date_of_birth.y < b.date_of_birth.y) return true;
    
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

void Merge(vector<people> &A, int first, int last)
{
  int middle, start, final, j;

  vector<people> mas;
  
  mas.resize(100);
  
  middle=(first+last)/2;
  
  start=first; 
  
  final=middle+1;

  for(j=first; j<=last; j++)
  {
    if ((start<=middle) && ((final>last) || (A[start]<A[final])))
    {
      mas[j]=A[start];
      start++;
    }
    else
    {
      mas[j]=A[final];
      final++;
    }
  }

  for (j=first; j<=last; j++)
  {
    A[j]=mas[j];
  }
};

void MergeSort(vector<people> &A, int first, int last)
{
  if (first<last)
  {
  MergeSort(A, first, (first+last)/2);
  MergeSort(A, (first+last)/2+1, last);
  Merge(A, first, last);
  }
};

int main()
{
    vector<people> x;  
    x = inFile () ;
    int size = x.size();
    MergeSort (x,0,size-1);
    for(int i = 0; i <  size; i++) print (x[i]);

    return 0;
}