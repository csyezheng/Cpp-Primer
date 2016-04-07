#include <iostream>
#include <string>
#include <memory>

struct destination
{
	destination(const std::string &str) : dest(str) { }
	std::string dest;
};

struct connection
{
	connection(const std::string &str) : connected(str) { }
	std::string connected;
};

connection connect(destination *d)
{
	connection c(d->dest);
	std::cout << "connect to " << d->dest << std::endl;
	return c;
}

void disconnect(connection c)
{
	std::cout << "disconnect " << c.connected << std::endl;
}

void f(destination &d)
{
	connection c = connect(&d);
	std::shared_ptr<connection> p(&c,
		[](connection *p) { disconnect(*p); });
}

int main()
{
	destination d("192.168.1.1");
	f(d);
	return 0;
}
