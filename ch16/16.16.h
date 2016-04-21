#ifndef VEC_H
#define VEC_H

#include <allocators>
#include <utility>
#include <stdexcept>
#include <initializer_list>

template<typename T>
class Vec
{
public:
	Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	Vec(std::initializer_list<T>);
	Vec(const Vec&);
	Vec &operator= (const Vec&);
	Vec(Vec&&) noexcept;
	Vec &operator= (Vec&&) noexcept;
	~Vec();
	std::size_t size() const;
	std::size_t capacity() const;
	bool empty() const;
	void push_back(const T&);
	void push_back(T&&);
	void pop_back();
	T &front();
	const T &front() const;
	T &back();
	const T &back() const;
	T *begin() const;
	T *end() const;
private:
	std::allocator<T> alloc;
	T *elements;
	T *first_free;
	T *cap;
	void chk_n_alloc();
	void reallocate();
	std::pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
};


template<typename T>
inline Vec<T>::Vec(std::initializer_list<T> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	first_free = cap = data.second;
}

template<typename T>
inline Vec<T>::Vec(const Vec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	elements = data.first;
	first_free = cap = data.second;
}

template<typename T>
inline Vec<T> &Vec<T>::operator= (const Vec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.elements;
	first_free = cap = data.second;
	return *this;
}

template<typename T>
inline Vec<T>::Vec(Vec &&rhs) noexcept: elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

template<typename T>
inline Vec<T> &Vec<T>::operator= (Vec &&rhs) noexcept
{
	if (this != &rhs)
	{
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

template<typename T>
Vec<T>::~Vec()
{
	free();
}

template<typename T>
inline std::size_t Vec<T>::size() const
{
	return first_free - elements;
}

template <typename T>
inline std::size_t Vec<T>::capacity() const
{
	return cap - elements;
}

template<typename T>
inline bool Vec<T>::empty() const
{
	return size() ? false : true;
}

template<typename T>
inline void Vec<T>::push_back(const T &item)
{
	chk_n_alloc();
	alloc.contruct(first_free++, item);
}

template<typename T>
inline void Vec<T>::push_back(T &&item)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(item));
}

template<typename T>
inline void Vec<T>::pop_back()
{
	if (!elements)
		throw std::runtime_error("pop_back on empty Vec");
	alloc.destroy(--first_free);
}

template<typename T>
inline T &Vec<T>::front()
{
	if (!elements)
		throw std::runtime_error("front on empty Vec");
	return *elements;
}

template<typename T>
inline const T &Vec<T>::front() const
{
	if (!elements)
		throw std::runtime_error("front on empty Vec");
	return *elements;
}

template<typename T>
inline T &Vec<T>::back()
{
	if (!elements)
		throw std::runtime_error("back on empty Vec");
	return *(first_free - 1);
}

template<typename T>
inline const T &Vec<T>::back() const
{
	if (!elements)
		throw std::runtime_error("front on empty Vec");
	return *(first_free - 1);
}

template<typename T>
inline T *Vec<T>::begin() const
{
	return elements;
}

template<typename T>
inline T *Vec<T>::end() const
{
	return first_free;
}

template<typename T>
inline void Vec<T>::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
}

template<typename T>
inline void Vec<T>::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	for (auto p = elements; p != first_free; ++p)
		alloc.construct(dest++, *p);
	elements = newdata;
	first_free = cap = dest;
}

template<typename T>
inline std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto newdata = alloc.allocate(e - b);
	auto dest = newdata;
	for (auto p = elements; p != first_free; ++p)
		alloc.construct(dest++, *P);
	return{ newdata, dest };
}

template<typename T>
inline void Vec<T>::free()
{
	for (auto p = first_free; p != elements; )
		alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
}

#endif