#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

std::string make_plural(int i, const std::string &s1, const std::string &s2)
{
	return i > 1 ? s1 + s2 : s1;
}

void elimDups(std::vector<std::string> &vec)
{
	std::sort(vec.begin(), vec.end());
	auto end_unique = std::unique(vec.begin(), vec.end());
	vec.erase(end_unique, vec.end());
}

bool check_size(const std::string &str, std::string::size_type sz)
{
	return str.size() > sz;
}

void biggies(std::vector<std::string> vec, std::string::size_type sz)
{
	elimDups(vec);
	std::stable_sort(vec.begin(), vec.end(), [](const std::string &s1,
		const std::string &s2) { return s1.size() < s2.size(); });
	auto wc = std::find_if(vec.begin(), vec.end(),
		std::bind(check_size, _1, sz));
	auto cnt = vec.end() - wc;
	std::cout << cnt << " " << make_plural(cnt, "word", "s")
		<< " of length " << sz << " or longer " << std::endl;
	std::for_each(wc, vec.end(),
		[](const std::string &str) { std::cout << str << std::endl; });
}

int main()
{
	std::vector<std::string> svec = { "hte", "sfaol", "ssfag", "sfk",
	"the", "and", "change", "this", "string" };
	biggies(svec, 5);
	return 0;
}