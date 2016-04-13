#ifndef STRBLOB_H
#define STRBLOB_H

#include <string>
#include <vector>
#include <memory>
#include <iterator>
#include <initializer_list>

class StrBlob
{
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const;
	bool empty() const;
	void push_back(const std::string &s);
	void push_back(std::string &&s) noexcept;
	void pop_back();
	std::string &front();
	const std::string front() const;
	std::string &back();
	const std::string back() const;
	std::vector<std::string>::iterator begin() const;
	std::vector<std::string>::iterator end() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(const size_type i, const std::string &s) const;
};



#endif