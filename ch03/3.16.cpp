#include <iostream>
#include <string>
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<int> v1;
	for (auto &elem : v1)
		cout << elem << " ";
	cout << endl;

	vector<int> v2(10);
	for (auto &elem : v2)
		cout << elem << " ";
	cout << endl;

	vector<int> v3(10, 42);
	for (auto &elem : v3)
		cout << elem << " ";
	cout << endl;

	vector<int> v4{ 10 };
	for (auto &elem : v4)
		cout << elem << " ";
	cout << endl;

	vector<int> v5{ 10, 42 };
	for (auto &elem : v5)
		cout << elem << " ";
	cout << endl;

	vector<string> v6{ 10 };
	for (auto &elem : v6)
		cout << elem << " ";
	cout << endl;

	vector<string> v7{ 10, "hi" };
	for (auto &elem : v7)
		cout << elem << endl;
	cout << endl;

	return 0;
}