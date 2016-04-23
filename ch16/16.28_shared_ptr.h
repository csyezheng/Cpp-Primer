#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <functional>
#include "16.22\DebugDelete.h"

template<typename T>
class Shared_ptr
{
public:
	Shared_ptr();
	Shared_ptr(T*);
	Shared_ptr(T*, std::function<void(T*)> f);
	Shared_ptr(const Shared_ptr&);
		Shared_ptr &operator= (const Shared_ptr&);
	Shared_ptr(Shared_ptr&&) noexcept:
	Shared_ptr &operator= (Shared_ptr&&) noexcept;
	~Shared_ptr();
	T &operator*() const;
	T *operator-> () const;
	bool operator bool() const;
	T *get() const noexcept;
	std::size_t use_count() const;
	bool unique() const;
	void swap(Shared_ptr&);
	void reset();
	void reset(T*);
	void reset(T*, std::function<void<T*>>);
private:
	T *ptr;
	std::size_t *refcnt;
	std::function<void(T*)> deleter;
	void free();
};

template<typename T>
Shared_ptr<T>::Shared_ptr() : 
	ptr(nullptr), refcnt(new std::size_t(1)), deleter(DebugDelete) { }

template<typename T>
Shared_ptr<T>::Shared_ptr(T *p) :
	ptr(p), refcnt(new std::size_t(1)), deleter(DebugDelete) { }

template<typename T>
Shared_ptr<T>::Shared_ptr(T *p, std::function<void(T*)> d) :
	ptr(p), refcnt(new std::size_t(1)), deleter(d) { }

template<typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr &rhs): 
	ptr(rhs.ptr), refcnt(rhs.refcnt), deleter(rhs.deleter)
{
	++*refcnt;
}

template<typename T>
Shared_ptr<T> &Shared_ptr<T>::operator= (const Shared_ptr &rhs)
{
	++*rhs.refcnt;
	if (--*refcnt == 0)
		free();
	refcnt = rhs.refcnt;
	ptr = rhs.ptr;
	deleter = rhs.deleter;
	return *this;
}

template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr &&rhs) noexcept:
ptr = std::move(rhs.ptr), refcnt = std::move(rhs.refcnt), deleter = std::move(rhs.deleter)
{
	rhs.ptr = rhs.refcnt = nullptr;
}

template<typename T>
Shared_ptr<T> &Shared_ptr<T>::operator= (Shared_ptr &&rhs) noexcept
{
	if (this != &rhs)
	{
		if (--*refcnt == 0)
			free();
		refcnt = rhs.refcnt;
		ptr = rhs.ptr;
		deleter = std::move(rhs.deleter);
		rhs.refcnt = rhs.ptr = nullptr;
	}
	return *this;
}

template<T>
Shared_ptr<T>::~Shared_ptr()
{
	if (--*refcnt == 0)
		free();
}

template<typename T>
T &Shared_ptr<T>::operator* () const
{
	return *ptr;
}

template<typename T>
T *Shared_ptr<T>::operator-> () const
{
	return &this->operator*();
}

template<typename T>
bool Shared_ptr<T>::operator bool() const
{
	return ptr ? true : false;
}

template<typename T>
T *Shared_ptr<T>::get() const
{
	return ptr;
}

template<typename T>
std::size_t Shared_ptr<T>::use_count() const
{
	return *refcnt;
}

template<typename T>
bool Shared_ptr<T>::unique() const
{
	return (*refcnt = 1) ? true : false;
}

template<typename T>
Shared_ptr<T> Shared_ptr<T>::swap(Shared_ptr &rhs)
{
	using std::swap;
	swap(refcnt, rhs.refcnt);
	swap(ptr, rhs.ptr);
	swap(deleter, rhs.deleter);
	return *this;
}

template<typename T>
void Shared_ptr<T>::reset()
{
	if (--*refcnt == 0)
		free();
}

template<typename T>
void Shared_ptr<T>::reset(T *p)
{
	if (ptr != p)
	{
		if (--*refcnt == 0)
			free();
		ptr = p;
		refcnt = new std::size_t(1);
	}
}

template<typename T>
void Shared_ptr<T>::reset(T *p, std::function<void(T*)> d)
{
	reset(p);                                              // this method is useful
	deleter = d;
}

template<typename T>
void Shared_ptr<T>::free()
{
	delete ptr;
	delete refcnt;
}


#endif