#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <cstddef>
#include "ConstStrBlobPtr.h"

using std::string;
using std::vector;
using std::shared_ptr;
using std::initializer_list;
using std::runtime_error;
using std::out_of_range;
using std::size_t;
using std::make_shared;

/* implementation for class StrBlob*/

/* constructor function*/
StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }

StrBlob::StrBlob(initializer_list<string> il) :
	data(make_shared<vector<string>>(il)) { }

/* member function */
StrBlob::size_type StrBlob::size() const
{
	return data->size();
}

bool StrBlob::empty() const
{
	return data->empty();
}

void StrBlob::push_back(const string &str)
{
	data->push_back(str);
}

void StrBlob::pop_back()
{
	data->pop_back();
}

string &StrBlob::front()
{
	return data->front();
}

const string StrBlob::front() const
{
	return data->front();
}

string &StrBlob::back()
{
	return data->back();
}

const string StrBlob::back() const
{
	return data->back();
}

const ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}

const ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, size());
}

void StrBlob::check(const size_type i, const string &msg) const
{
	if (i >= size())
		throw out_of_range(msg);
}

/* implementation for class ConstStrBlobPtr */
/* constructor function */
ConstStrBlobPtr::ConstStrBlobPtr() : curr(0) { }

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &sb, size_t sz) :
	wptr(sb.data), curr(sz) { }

/* member function */
const string &ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end of ConstStrBlobPtr");
	return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
	check(curr, "increase past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

shared_ptr<vector<string>> 
ConstStrBlobPtr::check(const size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobStr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}
