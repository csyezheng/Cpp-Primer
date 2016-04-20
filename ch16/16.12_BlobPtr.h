#ifndef BLOBPTR_H
#define BLOBPTR_H

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include "16.12_Blob.h"

template<typename T>
class BlobPtr
{
public:
	BlobPtr() : curr(0) { }
	BlobPtr(Blob<T>&, size_t sz = 0);
	BlobPtr &operator++ ();
	BlobPtr &operator-- ();
	BlobPtr &operator++ (int);
	BlobPtr &operator-- (int);
	T &operator* ();
private:
	std::weak_ptr<std::vector<T>> wtr;
	std::size_t curr;
	std::shared_ptr<std::vector<T>> check(size_t i, const std::string &msg) const;
};


template<typename T>
BlobPtr<T>::BlobPtr(Blob<T> &a, size_t sz) : wptr(a), curr(sz) { }

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator++ ()
{
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator-- ()
{
	check(curr, "decrement past end of BlobPtr");
	--curr;
	return *this;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator++ (int)
{
	auto ret = *this;
	check(curr, "increment past end of BlobPtr");
	++curr;
	return ret;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator-- (int)
{
	auto ret = *this;
	check(curr, "decrement past end of BlobPtr");
	--curr;
	return *this;
}

template<typename T>
T &BlobPtr<T>::operator* ()
{
	auto ret = check(curr, "dereference past end of BlobPtr");
	return (*ret)[curr];
}

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbounded BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}


#endif