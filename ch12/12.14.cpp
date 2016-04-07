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
	std::cout << "disconnect the " << c.connected << std::endl;
}

void end_connection(connection *p)
{
	disconnect(*p);
}

void f(destination &d)
{
	connection c = connect(&d);
	std::shared_ptr<connection> p(&c, end_connection);
}

int main()
{
	destination dest("192.168.1.1");
	f(dest);
	return 0;
}