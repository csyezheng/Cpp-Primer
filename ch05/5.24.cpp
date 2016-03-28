#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{

	int num1, num2, result;
	cin >> num1 >> num2;
	if (num2 == 0)
		throw runtime_error("the divid number can't be zero");
	result = num1 / num2;
	cout << num1 << "/" << num2 << " is " << result << endl;

	return 0;
}