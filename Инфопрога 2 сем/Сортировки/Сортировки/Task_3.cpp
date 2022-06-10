#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>
#include<vector>

using namespace std;

#define INPUT_FILE "Data.txt"
#define OUTPUT_FILE "SortedData_3.txt"

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

void print_person(people x) {
  cout << x.surname << " " << x.occ << " " << x.exp << " " << x.salary << endl;
}

void inFile(vector<people> &x)
{
  ifstream in(INPUT_FILE);
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
    std::cout << "Loaded Person: " << std::endl;
    print_person(temp);
    x.push_back(temp);
  }
}

bool operator < (people a, people b)
{
 if (a.occ < b.occ) return true;
 if (a.occ == b.occ&&a.exp < b.exp) return true;
 if (a.occ == b.occ&&a.exp == b.exp&&a.salary == b.salary) return true;
 
 return false;
}

void WriteResult(vector<people> &px)
{
  ofstream out(OUTPUT_FILE);

  for (people x : px)
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
}

void bubblesort(vector<people>&A)
{
  int i,j;
  int size=A.size();

  for(i=size-1;i>0;--i)
  {
    for (j=1;j<=i;j++)
    {
      if (A[j]<A[j-1]) swap(A[j],A[j-1]);
    }
  }
}

int main()
{
    vector<people> x;
    inFile (x) ;
    int size = x.size(); 
    std::cout << size << std::endl;
    bubblesort (x);
    WriteResult(x);
    
    return 0;
}