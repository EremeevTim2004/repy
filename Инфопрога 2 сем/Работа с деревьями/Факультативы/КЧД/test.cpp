#include<iostream>
#include<vector>
#include"RBTree.h"

using namespace std;

int main() 
{
	vector<int> nums{ 10,40,30,60,90,70,20,50,80,100};

	RBTree<int> tree;

	for (auto num : nums)
    {
		tree.insert(num);
    }

	tree.preOrder();

	std::cout << std::endl;

	tree.inOrder();

	std::cout << std::endl;

	tree.postOrder();

	std::cout << std::endl;

	std::cout << "Найти узел с ключом 30: \ n";

	std::cout << std::endl << tree.search(30) -> key << std::endl;

	std::cout << "Удалить узел с ключом 100 \ n";

	tree.remove(100);

	tree.preOrder();

	std::cout << std::endl;

	std::cout << "\n Красные и черные детали дерева: \n";

	tree.print();

	cin.get();

	return 0;
}
