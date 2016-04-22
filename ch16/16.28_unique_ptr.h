#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <functional>
#include "16.22\DebugDelete.h"

template <typename T, typename D = DebugDelete>
class Unique_ptr
{
public:
	Unique_ptr() = default;
	Unique_ptr(T*);
	Unique_ptr(T *p, std::function<void<T*>> d);
	Unique_ptr(const Unique&) = delete;
	Unique_ptr &operator= (const Unique&) = delete;
	Unique_ptr(Unique_ptr &&rhs) noexcept
	Unique_ptr &operator= (Unique_ptr&&) noexcept;
	~Unique_ptr();
	T &operator* () const;
	T *operator->() const;
	bool operator bool() const;
	T &get() const;
	void swap(Unique_ptr&);
	void reset();
	void reset(T*);
	T *release();
private:
	T *ptr;
	std::function<void<T*>> deleter = D();
};


template<typename T, typename D>
Unique_ptr<T, D>::Unique_ptr(T *p) : ptr(p) { }

template<typename T, typename D>
Unique_ptr<T, D>::Unique_ptr(T *p, std::function<void<T*>> d) : ptr(p), deleter(d) { }

template<typename T, typename D>
Unique_ptr<T, D>::Unique_ptr(Unique_ptr &&rhs) noexcept : 
	ptr(rhs.ptr), deleter(std:move(rhs.deleter)) { }

template<typename T, typename D>
Unique_ptr<T, D> &Unique_ptr<T, D>::operator= (Unique_ptr &&rhs) noexcept
{
	if (this != &rhs)
	{
		ptr = rhs.ptr
		deleter = std::move(rhs.deleter);
	}
}

template<typename T, typename D>
Unique_ptr<T, D>::~Unique_ptr()
{
	deleter(ptr);
}

template<typename T, typename D>
T &Unique_ptr<T, D>::operator* () const
{
	return *ptr;
}

template<typename T, typename D>
T *Unique_ptr<T, D>::operator-> () const
{
	return &this->operator*();
}

template<typename T, typename D>
bool Unique_ptr<T, D>::operator bool() const
{
	return ptr ? true : false;
}

template<typename T, typename D>
T *Unique_ptr<T, D>::get() const
{
	return ptr;
}

template<typename T, typename D>
void Unique_ptr<T, D>::swap(Unique_ptr &rhs)
{
	using std::swap;
	swap(ptr, rhs.ptr);
	swap(deleter, rhs.deleter);
}

template<typename T, typename D>
void Unique_ptr<T, D>::reset() noexcept                   
{
	deleter(ptr);
	ptr = nullptr;                          //reset must use noexcept
}

template<typename T, typename D>
void Unique_ptr<T, D>::reset(T *p) noexcept
{
	deleter(ptr);
	ptr(p);
}

template<typename T, typename D>
T *Unique_ptr<T, D>::release()
{
	auto ret = new T(*ptr);
	deleter(ptr);
	return ret;
}



#endif