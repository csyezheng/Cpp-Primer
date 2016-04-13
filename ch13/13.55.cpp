#include <string>
#include <vector>
#include <memory>
#include <iterator>
#include "13.55.h"

using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::initializer_list;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }

StrBlob::StrBlob(initializer_list<string> il) :
	data(make_shared<vector<string>>(il)) { }

size_t StrBlob::size() const
{
	return data->size();
}

bool StrBlob::empty() const
{
	return size() ? false : true;
}

void StrBlob::push_back(const string &s)
{
	data->push_back(s);
}

void StrBlob::push_back(string &&s) noexcept
{
	data->push_back(s);
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string StrBlob::front() const
{
	check(0, "fornt on empty StrBlob");
	return data->back();
}

string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const string StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

vector<string>::iterator StrBlob::begin() const
{
	return data->begin();
}

vector<string>::iterator StrBlob::end() const
{
	return data->end();
}

void StrBlob::check(const size_type i, const string &msg) const
{
	if (i >= size())
		throw std::out_of_range(msg);
}

int main()
{

}