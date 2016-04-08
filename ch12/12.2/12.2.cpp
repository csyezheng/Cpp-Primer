#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include "StrBlob.h"

using std::vector;
using std::string;
using std::make_shared;
using std::initializer_list;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }

StrBlob::StrBlob(initializer_list<string> il) :
	data(make_shared<vector<string>>(il)) { }

StrBlob::size_type StrBlob::size() const
{
	return data->size();
}

bool StrBlob::empty() const
{
	return data->empty();
}

void StrBlob::push_back(std::string str)
{
	data->push_back(str);
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::check(const size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

