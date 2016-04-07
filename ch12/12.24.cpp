#include <iostream>
#include <memory>

int main()
{
	char ch;
	constexpr int sz = 10;
	std::unique_ptr<char[]> up(new char[sz]);    // type must be array <char[]>
	for (std::size_t i = 0; std::cin >> ch; ++i)
		up[i] = ch;                             //if allocate char array longer than sz
												//will cause bug
	for (std::size_t i = 0; i != sz; ++i)    
		std::cout << up[i] << std::endl;   
	return 0;
}