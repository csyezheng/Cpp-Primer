#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <iterator>
#include <initializer_list>
#include "16.28_shared_ptr.h"

template<typename T>
class Blob
{
public:
	using size_type = std::vector<T>::size_type;
	Blob();
	Blob(std::initializer_list<T>);
	size_type size() const;
	bool empty() const;
	void push_back(const T&);
	void push_back(T&&);
	void pop_back();
	T &front();
	const T front() const;
	T &back();
	const T back() const;
	std::vector<T>::itreator begin();
	std::vector<T>::const_iterator begin() const;
	std::vector<T>::iterator end();
	std::vector<T>::const_iterator end() const;
	T &operator[] (size_type);
	const T &operator[] (size_type) const;
private:
	Shared_ptr<std::vector<T>> data;
	void check(size_type, const std::string &msg) const;
};


template<typename T>
Blob<T>::Blob() : data(std::make_shared<vector<T>>(il)) { }

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
	data(std::make_shared<vector<T>>(il)) { }

template<typename T>
Blob<T>::size_type Blob<T>::size() const
{
	return data->size();
}

template<typename T>
bool Blob<T>::empty() const
{
	return data->empty();
}

template<typename T>
void Blob<T>::push_back(const T &item)
{
	data->push_back(item);
}

template<typename T>
void Blob<T>::push_back(T &&item)
{
	data->push_back(std::move(item));
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
T &Blob<T>::front()
{
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
const T &Blob<T>::front() const
{
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
T &Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back()
}

template<typename T>
const T &Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
std::vector<T>::iterator Blob<T>::begin()
{
	return data->begin();
}

template<typename T>
std::vector<T>::iterator Blob<T>::end()
{
	return data->end();
}

template<typename T>
const std::vector<T>::const_iterator Blob<T>::begin() const
{
	return data->begin();
}

template<typename T>
const std::vector<T>::const_iterator Blob<T>::end() const
{
	return data->end();
}

template<typename T>
T &Blob<T>::operator[] (size_type i)
{
	return (*data)[i];
}

template<typename T>
const T &Blob<T>::operator[] (size_type i) const
{
	return (*data)[i];
}

template<typenameT>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= size())
		throw std::out_of_range(msg);
}

#endif