#include <string>
#include <vector>
#include <memory>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include "StrBlob.h"

using namespace std;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }

StrBlob::StrBlob(initializer_list<string> il) :
	data(make_shared<vector<string>>(il)) { }

StrBlob::StrBlob(const StrBlob &rhs) :
	data(make_shared<vector<string>>(*rhs.data)) { }   ///////////////////////////

StrBlob &StrBlob::operator= (const StrBlob &rhs)
{
	data = make_shared<vector<string>>(*rhs.data);    ///////////////////////////
	return *this;
}

StrBlob::size_type StrBlob::size() const
{
	return data->size();
}

bool StrBlob::empty() const
{
	return data->empty();
}

void StrBlob::push_back(const std::string &s)
{
	data->push_back(s);
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

StrBlobPtr &StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr &StrBlob::end()
{
	return StrBlobPtr(*this, size());
}

void StrBlob::check(const size_type i, const string &msg) const
{
	if (i >= size())
		throw out_of_range(msg);
}

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) : wptr(a.data), curr(sz) { }

std::string &StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end of StrBlobPtr");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

shared_ptr<vector<string>> 
	StrBlobPtr::check(const size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbounded StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

int main()
{

}