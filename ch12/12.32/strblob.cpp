#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include "StrBlob.h"

using namespace std;

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
	check(0, "front on empty StrBlob");
	return data->front();
}

const string StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
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
/*
ConstStrBlobPtr StrBlob::begin() const 
{
	return ConstStrBlobPtr(*this);                ///////////////////////
}
*/
ConstStrBlobPtr StrBlob::end() const 
{
	return ConstStrBlobPtr(*this, data->size());
}


void StrBlob::check(const size_type i, const string &msg) const
{
	if (i >= size())
		throw out_of_range(msg);
}

StrBlobPtr::StrBlobPtr() : curr(0) { }

StrBlobPtr::StrBlobPtr(StrBlob &sb, size_t sz = 0) :
	wptr(sb.data), curr(sz) { }

string &StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end of StrBlobPtr");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
	auto p = check(curr, "increase past end of StrBlobPtr");
	++curr;
	return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(const size_t i,
	const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlob");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

ConstStrBlobPtr::ConstStrBlobPtr() : curr(0) { }

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &sb, const size_t sz = 0) :
	wptr(sb.data), curr(sz) { }

const string ConstStrBlobPtr::deref() const
{
	auto ret = check(curr, "dereference past end of ConstStrBlobPtr");
	return (*ret)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

shared_ptr<vector<string>> 
ConstStrBlobPtr::check(const size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbounded ConstStrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}