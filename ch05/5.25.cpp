#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
	while (true)
	{
		try
		{
			int num1, num2, result;
			cin >> num1 >> num2;
			if (num2 == 0)
				throw runtime_error("the divid number can't be zero");
			result = num1 / num2;
			cout << num1 << "/" << num2 << " is " << result << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << endl;
			cout << "Do you want to try again? y or n" << endl;
			string choose, again("y");
			cin >> choose;
			if (choose != again)
				break;
		}
	} 
	return 0;
}