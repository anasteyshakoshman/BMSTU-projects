#pragma once
#include <initializer_list>
#include <iostream>
#include <iostream>

#ifndef __TARRAY_INCLUDED__
#define __TARRAY_INCLUDED__
#include <iterator>

template <class T, std::size_t N>

struct TArray
{

public:
	using value_type = T;
	using size_type = size_t;
	using difference_type = std::ptrdiff_t;
	using reference = value_type &;
	using const_reference = const value_type &;
	using pointer = value_type *;
	using const_pointer = const T *;
	using iterator = value_type *;
	using const_iterator = const iterator;

private:
	T Data[N];

public:
	TArray()
	{}

	~TArray()
	{}

	TArray(std::initializer_list<value_type> init)
	{	
		int i = 0;
		for (auto & val : init)
		{
			Data[i] = val;
			++i;
		}	
	}

	value_type at(size_type index) const
	{
		if (index < 0) throw std::out_of_range(" Incorrect value of index");
		if (index >= size()) throw std::out_of_range("Index is more than size of massiv");
		return Ptr[index];
	}

	reference at(size_type index)
	{
		if (index < 0) throw std::out_of_range(" Incorrect value of index");
		if (index >= size()) throw std::out_of_range("Index is more than size of massiv");
		return Ptr[index];
	}


	reference operator[](size_type index)
	{
		return Data[index];
	}

	const_reference operator[](size_type index) const
	{
		return Data[index];
	}
		
	reference front()
	{
		if (!size()) throw std::length_error("This massiv is empty");
		return Data[0];
	}

	const_reference front() const
	{
		if (!size()) throw std::length_error("This massiv is empty");
		return Data[0];
	}

	reference back()
	{
		if (!size()) throw std::length_error("This massiv is empty");
		return Data[size() - 1];
	}

	const_reference back() const
	{
		if (!size()) throw std::length_error("This massiv is empty");
		return Data[size() - 1];
	}

	iterator begin()
	{
		return Data;
	}

	const_iterator cbegin() const
	{
		return Data;
	}

	iterator end()
	{
		return Data + size();
	}

	const_iterator cend() const
	{
		return Data + size();
	}

	bool empty()
	{
		if (!size()) return true;
		else return false;
	}

	size_type size()
	{
		return N;
	}

	size_type max_size()
	{
		return std::distance(cbegin(), cend());
	}

	void swap(TArray<T, N> & other)
	{
		std::swap(Data, other.Data);
	}

	void fill(const value_type value)
	{
		for (int i = 0; i < N; ++i)
		{
			Data[i] = value;
		}
	}

	friend std::ostream &operator <<(std::ostream & out, TArray<T, N> const & rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			out << rhs.Data[i] << " ";
		}
		out << "\n";
		return out;
	}

	friend bool operator==(const TArray<T, N> & lhs, const TArray<T, N> & rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			if (lhs.Data[i] != rhs.Data[i]) return false;
		}
		return true;
	}

	friend bool operator!=(const TArray<T, N> & lhs, const TArray<T, N> & rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			if (lhs.Data[i] == rhs.Data[i]) return false;
		}
		return true;
	}


	friend bool operator<(const TArray<T, N> & lhs, const TArray<T, N> & rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			if (lhs.Data[i] >= rhs.Data[i]) return false;
		}
		return true;
	}

	friend bool operator>(const TArray<T, N> & lhs, const TArray<T, N> & rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			if (lhs.Data[i] <= rhs.Data[i]) return false;
		}
		return true;
	}

	friend bool operator<=(const TArray<T, N> & lhs, const TArray<T, N> & rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			if (lhs.Data[i] > rhs.Data[i]) return false;
		}
		return true;
	}

	friend bool operator>=(const TArray<T, N> & lhs, const TArray<T, N> & rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			if (lhs.Data[i] < rhs.Data[i]) return false;
		}
		return true;
	}
};








#endif // __TARRAY_INCLUDED__

