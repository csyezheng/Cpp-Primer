#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <cstddef>
#include <stdexcept>
#include "StrBlob.h"

using std::string;
using std::vector;
using std::make_shared;
using std::initializer_list;
using std::size_t;
using std::runtime_error;
using std::shared_ptr;

/* for StrBlob */
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

void StrBlob::check(const size_type i, const string &msg) const
{
	if (i >= size())
		throw runtime_error(msg);
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, size());
}


/* for StrBlobPtr */
StrBlobPtr::StrBlobPtr() : curr(0) { }

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) :
	wptr(a.data), curr(sz) { }

string &StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

bool StrBlobPtr::operator!=(const StrBlobPtr &rhs) const
{
	return curr != rhs.curr;
}

shared_ptr<vector<string>> StrBlobPtr::check(const size_t i,
	const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error(msg);
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}