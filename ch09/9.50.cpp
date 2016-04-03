#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<string> sivec = { "0", "1", "2", "3", "4", "5" };
	int sum = 0;
	for (const auto &val : sivec)
		sum += stoi(val);
	cout << sum << endl;

	vector<string> sfvec = { "3.1", "3.2", "0,3", "0.2", "3.0" };
	double total = 0.0;
	for (const auto &elem : sfvec)
		total += stod(elem);
	cout << total << endl;
	
	return 0;
}