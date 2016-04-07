#ifndef STRBLOB_H
#define STRBLOB_H

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

class StrBlob
{
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const;
	bool empty() const;
	void push_back(std::string str);
	void pop_back();
	std::string &front();
	const std::string front() const;
	std::string &back();
	const std::string back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(const size_type i, const std::string &msg) const;
};


#endif