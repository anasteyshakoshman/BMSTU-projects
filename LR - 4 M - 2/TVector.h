#pragma once
#include <iostream>
#include<stdexcept>
#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__

class TVector
{
public:
	using value_type = int;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;
public:
	TVector() : Ptr(nullptr), Count(0), InternalCapacity(0)
	{}

	TVector(size_type capacity) : Count(0), InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
	}

	TVector(size_type capacity, value_type init) : InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
		Count = capacity;
		for (int i = 0; i < Count; i++)
		{
			Ptr[i] = init;
		}
	}

	~TVector()
	{
		delete[] Ptr;
	}

	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type capacity() const throw()
	{
		return InternalCapacity;
	}

	iterator begin() const throw()
	{
		return Ptr;
	}

	iterator end() const throw()
	{
		return Ptr + Count;
	}




	void TVector::reserve(size_type size)
	{
		if (InternalCapacity >= size) return;
		InternalCapacity = size;
		value_type * NewPtr = new value_type[InternalCapacity];
		if (Ptr)
		{
			memcpy(NewPtr, Ptr, Count * sizeof(value_type));
			delete[] Ptr;
		}
		Ptr = NewPtr;
	}

	TVector::TVector(const TVector& rhs)
	{
		Count = rhs.Count;
		InternalCapacity = rhs.InternalCapacity;
		Ptr = new value_type[InternalCapacity];
		memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
	}

	TVector& TVector::operator=(const TVector& rhs)
	{
		if (&rhs == this) return *this;
		if (Ptr) delete[] Ptr;
		Count = rhs.Count;
		InternalCapacity = rhs.InternalCapacity;
		Ptr = new value_type[InternalCapacity];
		memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
		return *this;
	}

	void TVector::push_back(const value_type& value)
	{
		if (Count <= InternalCapacity) this->reserve(InternalCapacity * 2);
		Ptr[Count] = value;
		Count++;
	}

	reference TVector::at(size_type index)
	{
		if (index < 0) throw std::out_of_range(" Incorrect value of index");
		if (index >= Count) throw std::out_of_range("Index is more than size of vector");
		return Ptr[index];
	}

	value_type TVector::at(size_type index) const
	{
		if (index < 0) throw std::out_of_range(" Incorrect value of index");
		if (index >= Count) throw std::out_of_range("Index is more than size of vector");
		return Ptr[index];
	}

	reference TVector::operator[](size_type index)
	{
		return Ptr[index];
	}

	const_reference TVector::operator[](size_type index) const
	{
		return Ptr[index];
	}

	reference TVector::front()
	{
		if (!Count) throw std::length_error("This vector is empty");
		return Ptr[0];
	}

	const_reference TVector::front() const
	{
		if (!Count) throw std::length_error("This vector is empty");
		return Ptr[0];
	}

	reference TVector::back()
	{
		if (!Count) throw std::length_error("This vector is empty");
		return Ptr[Count - 1];
	}

	const_reference TVector::back() const
	{
		if (!Count) throw std::length_error("This vector is empty");
		return Ptr[Count - 1];
	}

	void TVector::clear()
	{
		if (Ptr)
		{
			delete[] Ptr;
			Count = 0;
			InternalCapacity = 0;
		}
	}

	void TVector::pop_back()
	{
		if (!Count) throw std::length_error("This vector is empty");
		Count--;
	}

	void TVector::swap(TVector& other) throw()
	{
		std::swap(Count, other.Count);
		std::swap(InternalCapacity, other.InternalCapacity);
		std::swap(Ptr, other.Ptr);
	}

	void TVector::resize(size_type count, value_type value = value_type())
	{
		if (count > SIZE_MAX) throw std::overflow_error("The size is more then Size_MAX");
		if (count = Count) return;
		value_type * NewPtr = new value_type[count];
		if (Count > count) memcpy(NewPtr, Ptr, count * sizeof(value_type));
		else
		{
			InternalCapacity = count;
			memcpy(NewPtr, Ptr, Count * sizeof(value_type));
			for (Count; Count < count; Count++) Ptr[Count] = value;
		}
		Count = count;
		if (Ptr) delete[] Ptr;
		Ptr = NewPtr;
	}

	iterator TVector::insert(iterator pos, const value_type& value)
	{
		if (pos > Ptr + Count)  throw std::out_of_range("This pos is more than size of vector!");
		if (Count == InternalCapacity) this->reserve(InternalCapacity * 2);
		for (Count; Count > pos - Ptr; Count--) Ptr[Count] = Ptr[Count - 1];
		Count++;
		Ptr[pos - Ptr] = value;
		return pos;
	}

	void TVector::insert(iterator pos, size_type count, const value_type& value)
	{
		if (count > SIZE_MAX) throw std::overflow_error("The size is more then Size_MAX");
		if (pos > Ptr + Count)  throw std::out_of_range("This pos is more than size of vector!");
		Count += count;
		while (InternalCapacity < Count)
		{
			this->reserve(InternalCapacity * 2);
		}
		for (Count - 1; Count - 1 > pos - Ptr; Count--)
		{
			Ptr[Count - 1] = Ptr[Count - 1 - count];
		}
		for (size_type i = pos - Ptr; i < pos - Ptr + count; i++)
		{
			Ptr[i] = value;
		}
	}


	iterator TVector::erase(iterator pos)
	{
		if (pos > Ptr + Count)  throw std::out_of_range("This pos is more than size of vector!");
		for (int i = pos - Ptr; i < Count - 1; i++)	Ptr[i] = Ptr[i + 1];
		Count--;
		return pos;
	}

	iterator TVector::erase(iterator first, iterator last)
	{
		if (first > last && (first > Ptr + Count || last > Ptr + Count))
		{
			throw std::out_of_range("This pos is more than size of vector!");
		}
		int l = last - Ptr;
		for (int i = first - Ptr; i < Count - l; i++)	Ptr[i] = Ptr[l + i];
		Count -= l;
		return first;
	}
};


#endif // __TVECTOR_INCLUDED__











