#ifndef BLOB_H
#define BLOB_H

#include <string>
#include <memory>
#include <vector>
#include <initializer_list>
#include <stdexcept>


template<typename T>
class Blob
{
public:
	using size_type = typename std::vector<T>::size_type;       // must use typename
	Blob();
	Blob(std::initializer_list<T>);
	size_type size() const
	{
		return data->size();                          // how to wirte size_type when define outside 
	}
	bool empty() const;
	void push_back(const T&);
	void push_back(T&&);
	void pop_back();
	T &front();
	const T front() const;
	T &back();
	const T back() const;
	T *begin();
	T *end();
	const T *begin() const;
	const T *end() const;
	T &operator[](size_type i);
	const T &operator[](size_type i) const;
private:
	std::shared_ptr<std::vector<T>> data;
	void check(const size_type i, const std::string &msg) const;
};

template<typename T>
Blob<T>::Blob() : std::make_shared<std::vector<T>>() { }

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
	data(std::make_shared<std::vector<T>>(il)) { }

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
void Blob<T>::push_back(T &&value)
{
	data->push_back(std::move(value));
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
const T Blob<T>::front() const
{
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
T &Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
const T Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
T *Blob<T>::begin()
{
	return data->begin();
}

template<typename T>
const T *Blob<T>::begin() const
{
	return data->begin();
}

template<typename T>
T *Blob<T>::end() 
{
	return data->end();
}

template<typename T>
const T *Blob<T>::end() const
{
	return data->end();
}

template<typename T>
T &Blob<T>::operator[] (size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
const T &Blob<T>::operator[] (size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
void Blob<T>::check(const size_type i, const std::string &msg) const
{
	if (i >= size())
		throw std::out_of_range(msg);
}

#endif