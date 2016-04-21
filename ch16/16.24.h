#ifndef BLOB_H
#define BLOB_H

#include <string>
#include <stdexcept>
#include <initializer_list>

template<typename T>
class Blob
{
public:
	using size_type = std::vector<T>::size_type;
	Blob();
	Blob(std::initializer_list<T>);
	template<typename It>
	Blob(It, It);
	size_type size() const;
	bool empty() const;
	void push_back(const T&);
	void push_back(T &&);
	void pop_back();
	T &front();
	const T front() const;
	T &back();
	const T back() const;
	T *begin() const;
	T *end() const;
	T &operator[] (size_type);
	const &operator[] (size_type) const;
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};

template<typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) { }

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
	data(std::make_shared<std::vector<T>>(il)) { }

template<typename T>
template<typename It>
Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) { }

template<typename T>
typename Blob<T>::size_type Blob<T>::size() const
{
	return data->size();
}

template<typename T>
bool Blob<T>::empty() const
{
	return size() ? false : true;
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

template<typename>
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

template<typeanme T>
T &Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
const T &Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
T *Blob<T>::begin() const
{
	return data->begin();
}

template<typename T>
T *Blob<T>::end() const
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
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= size())
		throw std::out_of_range(msg);
}


#endif