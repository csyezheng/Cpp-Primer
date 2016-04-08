#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <stdexcept>

using namespace std;

std::pair<map<string, set<size_t>>, vector<string>>
buildDataBase(ifstream &input)
{
	map<string, set<size_t>> wm;
	string line;
	vector<string> file;
	while (getline(input, line))
	{
		file.push_back(line);
		size_t n = file.size() - 1;
		istringstream iss(line);
		string word;
		while (iss >> word)
		{
			wm[word].insert(n);
		}
	}
	return{ wm, file };
}

void query(const map<string, set<size_t>> &wm, const vector<string> file,
	const string &sought)
{
	auto p = wm.find(sought);
	if (p == wm.cend())
		cout << "can't find this word in the file" << endl;
	else
	{
		cout << sought << " occurs " << wm.at(sought).size() << 
			(((wm.at(sought).size()) > 1) ? "times" : "time") << endl;
		for (const auto &lino : wm.at(sought))
			cout << "\t(line " << lino + 1 << ") " << file[lino] << endl;
	}
}

int main()
{
	ifstream input("text.txt");
	if (!input)
		throw runtime_error("can't open the file");
	auto data = buildDataBase(input);
	query(data.first, data.second, "the");

	return 0;
}