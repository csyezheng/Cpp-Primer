#include <string>
#include <stdexcept>
#include <vector>
#include <memory>
#include <initializer_list>
#include "StrBlob.h"

using std::string;
using std::out_of_range;
using std::make_shared;
using std::shared_ptr;
using std::initializer_list;
using std::vector;
using std::runtime_error;

/* =========================define for StrBlob======================================*/

StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }

StrBlob::StrBlob(initializer_list<string> il) :
	data(make_shared<vector<string>>(il)) { }

StrBlob::StrBlob(const StrBlob &rhs) :
	data(make_shared<std::vector<std::string>>(*rhs.data)) { }   //use make_shared 

StrBlob &StrBlob::operator= (const StrBlob &rhs)
{
	data = make_shared<std::vector<std::string>>(*rhs.data);
	return *this;                                                 //always forget...
}

StrBlob::StrBlob(StrBlob &&rhs) noexcept: data(std::move(rhs.data)) { }

StrBlob &StrBlob::operator= (StrBlob &&rhs) noexcept
{
	if (this != &rhs)                                            // notice to check
	{
		data = std::move(rhs.data);
		rhs.data = nullptr;
	}
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

void StrBlob::push_back(const string &s)
{
	data->push_back(s);
}

void StrBlob::push_back(string &&str)
{
	data->push_back(std::move(str));
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

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, size());
}

ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, size());
}

string &StrBlob::operator[](std::size_t n)
{
	check(n, "operator[] past end of StrBlob");
	return (*data)[n];
}

const string &StrBlob::operator[](std::size_t n) const
{
	check(n, "operator[] past end of StrBlob");
	return (*data)[n];
}

void StrBlob::check(const size_type i, const string &msg) const
{
	if (i >= size())
		throw out_of_range(msg);
}

bool operator== (const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!= (const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

bool operator< (const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data < *rhs.data;
}

bool operator> (const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data > *rhs.data;
}

bool operator<= (const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs > rhs);
}

bool operator>= (const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs < rhs);
}

/*=============================== define for StrBlobPtr ===============================*/

StrBlobPtr::StrBlobPtr(StrBlob &sb, size_t sz) : wptr(sb.data), curr(sz) { }

std::string &StrBlobPtr::deref() const
{
	auto ret = check(curr, "dereference past end of StrBlobPtr");
	return (*ret)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

string &StrBlobPtr::operator[](std::size_t n)
{
	auto ret = check(n, "operator[] past end of StrBlobPtr");
	return (*ret)[n];
}

const string &StrBlobPtr::operator[](std::size_t n) const
{
	auto ret = check(n, "operator[] past end of StrBlobPtr");
	return (*ret)[n];
}

StrBlobPtr &StrBlobPtr::operator++()
{
	++curr;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past end of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	auto ret = *this;
	++*this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	auto ret = *this;
	--*this;
	return ret;
}

StrBlobPtr &StrBlobPtr::operator+= (std::size_t n)
{
	curr += n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

StrBlobPtr &StrBlobPtr::operator-= (std::size_t n)
{
	curr -= n;
	check(curr, "decrement past end of StrBlobPtr");
	return *this;
}

string &StrBlobPtr::operator* () const
{
	auto ret = check(curr, "dereference past end of StrBlobPtr");
	return (*ret)[curr];
}

string *StrBlobPtr::operator->() const
{
	return &this->operator*();
}

shared_ptr<vector<string>> StrBlobPtr::check(const size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbounded StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

bool operator== (const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.deref() == rhs.deref() && lhs.curr == rhs.curr;
}

bool operator!= (const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator< (const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator> (const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr > rhs.curr;
}

bool operator<= (const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs < rhs);
}

StrBlobPtr operator+ (const StrBlobPtr &sbp, std::size_t i)
{
	auto ret = sbp;
	ret += i;
	return ret;
}

StrBlobPtr operator- (const StrBlobPtr &sbp, std::size_t i)
{
	auto ret = sbp;
	ret -= i;
	return ret;
}

/* =================================define for ConstStrBlobPtr==========================*/

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &sb, size_t sz) :
	wptr(sb.data), curr(sz) { }

const std::string ConstStrBlobPtr::deref() const
{
	auto ret = check(curr, "dereference past end of ConstStrBlobPtr");
	return (*ret)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
	check(curr, "increament past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

const string &ConstStrBlobPtr::operator[](std::size_t n) const
{
	auto ret = check(n, "operator[] past end of ConstStrBlobPtr");
	return (*ret)[n];
}

const string &ConstStrBlobPtr::operator* () const
{
	auto ret = check(curr, "dereference past end of StrBlobPtr");
	return (*ret)[curr];
}

const string *ConstStrBlobPtr::operator->() const
{
	return &this->operator*();
}

shared_ptr<vector<string>> 
ConstStrBlobPtr::check(const size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbounded ConstStrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

bool operator== (const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.deref() == rhs.deref() && lhs.curr == lhs.curr;
}

bool operator!= (const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator< (const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator> (const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr > rhs.curr;
}

bool operator<= (const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !(lhs > rhs);
}

bool operator>= (const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !(lhs < rhs);
}

