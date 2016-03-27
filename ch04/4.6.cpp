#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::out_of_range;

bool isOdd(int val)
{
	if (val % 2 == 1)
		return true;
	else
		return false;
}

int main()
{
	int number;
	cin >> number;
	if (number <= 0)
			throw out_of_range("The number is invalid");
	if (isOdd(number))
		cout << "the number you inputed is odd" << endl;
	else
		cout << "the number you inputed is even" << endl;

	return 0;
}