#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__

#include <string>
#include <vector>
#include <initializer_list>
#include <math.h>
#include <sstream>
#include <algorithm>


class boolean_function
{
public:

	using value_type = bool;
	using size_type = size_t;
	using reference = std::vector<value_type>::reference;
	using const_reference = std::vector<value_type>::const_reference;

	using iterator = std::vector<value_type>::iterator;
	using const_iterator = std::vector<value_type>::const_iterator;

private:

	std::vector<value_type> Func;

public:

	
	static boolean_function zero(size_t dimension)
	{
		if (!dimension) throw std::logic_error("Uncorrect quantity of elements");
		std::vector<bool> func(pow(2, dimension), false);
		return boolean_function(func);
	};

	static boolean_function var(size_t n, size_t dimension)   
	{
		if (dimension <= n) throw std::logic_error("The number of nedeed element can not more than the quantity of all elements");
		std::vector<value_type> Xn;
		size_type i = 0;
		while (i < pow(2, dimension) / pow(2, n))
		{
			size_type j = 0;
			while (j < pow(2, n))
			{
				Xn.push_back(i % 2);
				++j;
			}
			++i;
		}
		return boolean_function(Xn);
	};

	static boolean_function one(size_t dimension)
	{
		if (!dimension) throw std::logic_error("Uncorrect quantity of elements");
		std::vector<bool> func(pow(2, dimension), true);
		return boolean_function(func);
	};


	static boolean_function from_anf(std::vector<value_type> v)
	{
		std::vector<value_type> func(v);
		size_type i = func.size() / 2;
		while (i > 0)
		{
			std::vector<value_type> tmp;
			size_type j = 0;
			while (j < func.size())
			{
				size_type k = 0;
				while (k < i)
				{
					if (!((j / i) % 2))	tmp.push_back(func[j + k]);
					else tmp.push_back(func[j + k - i] ^ func[j + k]);
					++k;
				}
				j += i;
			}
			func = tmp;
			i /= 2;
		}
		return boolean_function(func);
	};



	boolean_function() {};

	boolean_function(size_type n)
	{
		if (!n) throw std::logic_error("Uncorrect quantity of elements");
		size_type i = 0;
		while (i < pow(2, n))
		{
			Func.push_back(false);
			++i;
		}
	};

	
	boolean_function(unsigned long long value, size_type n)
	{
		size_t ost = 0;
		while (value)
		{
			ost = value % 2;
			value = value / 2;
			Func.push_back(ost);
		}
		if (Func.size() > pow(2, n)) throw std::logic_error("The length of a given value in the binary system is more than the length of function of a given quantity of vars");
		while (Func.size() != pow(2, n))   Func.push_back(false);
	};

	friend std::ostream & operator <<(std::ostream & out, boolean_function & obj)
	{
		size_type i = 0;
		while (i < obj.Func.size())
		{
			out << obj.Func[i] << " ";
			++i;
		}
		return out;
	};


	boolean_function(const std::string & table)
	{
		float n_float = log2(table.size());
		size_type n_int = size_type(n_float);
		if (n_int != n_float) throw  std::logic_error("The boolean_fuction can not have this length");
		size_type i = 0;
		while (i < table.size())
		{

			if (table[i] == 48) Func.push_back(false);
			else if (table[i] == 49) Func.push_back(true);
			else throw std::logic_error("Uncorrect value in string ( just 0 or 1)");
			++i;
		}
	};


	boolean_function(const std::vector<value_type>& table)
	{
		float n_float = log2(table.size());
		size_type n_int = size_type(n_float);
		if (n_int != n_float) throw std::logic_error("The boolean_fuction can not have this length");
		Func = table;
	};

	boolean_function(const std::initializer_list<value_type> vars)
	{
		std::vector<bool> tmp;
		for (auto & i : vars) tmp.push_back(i);
		float n_float = log2(tmp.size());
		size_type n_int = size_type(n_float);
		if (n_int != n_float) throw std::logic_error("The boolean_fuction can not have this length");
		else Func = tmp;
	};

	boolean_function(const boolean_function& table)
	{
		Func = table.Func;
	};

	boolean_function& operator=(const boolean_function& rhs)
	{
		if (&rhs == this) return *this;
		if (!Func.empty()) Func.clear();
		Func = rhs.Func;
		return *this;
	};


	boolean_function& operator +=(const boolean_function& rhs)
	{
		if (Func.size() != rhs.Func.size()) throw std::length_error("Different quantity of elements");
		size_type i = 0;
		while (i < Func.size())
		{
			if (Func.at(i) == rhs.Func.at(i)) Func.at(i) = false;
			else Func.at(i) = true;
			++i;
		}
		return *this;
	};


	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (Func.size() != rhs.Func.size()) throw std::length_error("Different quantity of elements");
		size_type i = 0;
		while (i < Func.size())
		{
			Func.at(i) = Func.at(i) * rhs.Func.at(i);
			++i;
		}
		return *this;
	};


	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (Func.size() != rhs.Func.size()) throw std::length_error("Different quantity of elements");
		size_type i = 0;
		while (i < Func.size())
		{
			if (Func.at(i) < rhs.Func.at(i)) Func.at(i) = rhs.Func.at(i);
			++i;
		}
		return *this;
	};

	boolean_function operator ~()
	{
		size_type i = 0;
		while (i < Func.size())
		{
			Func.at(i) = !Func.at(i);
			++i;
		}
		return *this;
	};


	bool operator ==(const boolean_function & rhs) const
	{
		std::vector<value_type> tmp1 = anf();
		std::vector<value_type> tmp2 = rhs.anf();
		if (tmp1.size() > tmp2.size())
		{
			tmp2.resize(tmp1.size(), false);
		}
		else
		{
			tmp1.resize(tmp2.size(), false);
		}
		if (tmp1 == tmp2) return true;
		else return false;
	};


	bool operator >= (const boolean_function& rhs) const
	{
		if (Func.size() != rhs.Func.size()) throw std::length_error("Different quantity of elements");
		if (!Func.size()) throw std::logic_error("These boolean functions are empty");
		if (this == &rhs) return true;
		bool right = true, left = true;
		size_type i = 0;
		while (i < Func.size())
		{
			if (Func.at(i) < rhs.Func.at(i)) left = false;
			if (Func.at(i) > rhs.Func.at(i)) right = false;
			++i;
		}
		if (!right && !left) throw std::logic_error("These functions are not comparable");
		return left;
	};

	reference operator[](size_type ind)
	{
		return Func.at(ind);
	};

	const_reference operator[](size_type ind) const
	{
		if (ind > size() - 1) throw std::out_of_range("Uncorrect value of index");
		if (!size()) throw std::length_error("This boolean_function is empty");
		return Func.at(ind);
	};

	reference at(size_type ind)
	{
		if (ind > size() - 1) throw std::out_of_range("Uncorrect value of index");
		if (!size()) throw std::length_error("This boolean_function is empty");
		return Func.at(ind);
	};
	const_reference at(size_type ind) const
	{
		return Func.at(ind);
	};

	iterator begin()
	{
		return Func.begin();
	};

	iterator end()
	{
		return Func.end();
	};

	const_iterator cbegin() const
	{
		return Func.cbegin();
	};
	const_iterator cend() const
	{
		return Func.cend();
	};

	size_type size() const throw()
	{
		return Func.size();
	};

	size_type dimension() const throw()
	{
		return log2(size());
	};


	bool operator()(const std::vector<bool>& vars) const
	{
		if (vars.size() != dimension()) throw std::length_error("The length of vars aren't equally");
		size_type n = dimension(), result = 0;
		auto i = vars.begin();
		while (i != vars.end())
		{
			result += (*i) * pow( 2 , n );
			++i;  --n;
		}
		return Func[result];
	};


	bool operator()(const std::initializer_list<bool>  vars) const
	{
		if (vars.size() != dimension()) throw std::length_error("The length of vars aren't equally");
		size_type n = dimension() - 1, result = 0;
		auto i = vars.begin();
		while (i != vars.end())
		{
			result += (*i) * pow( 2 , n );
			++i;  --n;
		}
		return Func[result];
	};


	boolean_function operator()(const std::vector<boolean_function>& fs) const
	{
		std::vector<boolean_function> bf;
		std::vector<value_type> vec;
		size_t tmp = 0, i = 0;
		while (i < fs.size())
		{
			if (fs[i].size() > tmp)
			{
				tmp = fs[i].size();
			}
			bf.push_back(fs[i]);
			++i;
		}
		int ** array = new int*[tmp];
		i = 0;
		while (i < tmp)
		{
			array[i] = new int[fs.size()];
			++i;
		}
		i = 0;
		while (i < bf.size())
		{
			size_t m = 0;
			while (m < fs.size())
			{
				size_t k = 0, j = 0;
				while (j < tmp)
				{
					if (k >= bf[i].size()) k = 0;
					array[j][m] = bf[i][k];
					++k; ++j;
				}
				++i;  ++m;
			}
		}
		i = 0;
		while (i < tmp)
		{
			size_t l = 0, st = 0;
			int j = fs.size() - 1;
			while (j > -1)
			{
				l += pow(2, st) * array[i][j];
				++st; --j;
			}
			vec.push_back(Func[l]);
			++i;
		}
		i = 0;
		while (i < tmp)
		{
			delete[] array[i];
			++i;
		}
		delete[] array;
		return boolean_function(vec);
	};

	boolean_function operator()(const std::initializer_list<boolean_function> vars) const
	{
		std::vector<boolean_function> fs = vars;
		return (*this)(fs);
	};

	std::vector<value_type> change(size_t func_size, size_t i) const
	{
		std::vector<value_type> tmp;
		while (i)
		{
			tmp.push_back(i % 2);
			func_size -= 1;
			i /= 2;
		}
		while (func_size)
		{
			tmp.push_back(0);
			func_size -= 1;
		}
		std::reverse(tmp.begin(), tmp.end());
		return tmp;
	};

	bool is_monotone() const
	{
		std::vector<value_type> tmp1, tmp2;
		size_t i = 0, size = Func.size();
		while (i < size)
		{
			tmp1 = change(size, i);
			size_t j = 1;
			while (j < size)
			{
				tmp2 = change(size, j);
				bool log = true;
				size_t k = 0;
				while (k < size)
				{
					if (tmp1[k] > tmp2[k]) log = false;
					++k;
				}
				if (Func[i] > Func[j] && log == true) return false;
				++j;
			}
			++i;
		}
		return true;
	};


	bool is_symmetric() const  //самодвойствена ли
	{
		size_type i = 0, j = size() - 1;
		while (i != size() / 2)
		{
			if (Func.at(i) == Func.at(j)) return false;
			++i; --j;
		}
		return true;
	};


	bool is_linear() const
	{
		std::vector<value_type> tmp = anf();
		size_type i = 1 + dimension();
		while (i < tmp.size())
		{
			if (tmp[i] == true) return false;
			++i;
		}
		return true;
	};


	bool is_T1() const
	{
		return Func[size() - 1];
	};


	bool is_T0() const
	{
		return !Func[0];
	};


	bool is_balanced() const
	{
		size_type i = 0, zero = 0, one = 0;
		while (i < Func.size())
		{
			if (Func[i]) ++one;
			else ++zero;
			++i;
		}
		return zero == one;
	};


	size_t weight() const
	{
		size_type i = 0, one = 0;
		while (i < Func.size())
		{
			if (Func[i]) ++one;
			++i;
		}
		return one;
	};

	bool is_functionally_complete_system() const
	{
		if (!is_T0() && !is_T1() && !is_linear() && !is_monotone() && !is_symmetric()) return true;
		else return false;
	};


	std::vector<value_type> anf() const
	{
		std::vector<value_type> func(Func);
		size_type i = 1;
		while (i < func.size())
		{
			std::vector<value_type> tmp;
			size_type j = 0;
			while (j < func.size())
			{
				size_type k = 0;
				while ( k < i)
				{
					if (!((j / i) % 2))  tmp.push_back(func[k + j]);
					else   tmp.push_back(func[k - i + j] ^ func[k + j]);
					++k;
				}
				j += i;
			}
			func = tmp;
			i *= 2;
		}
		return func;
	}


};


std::string get_polynom(const boolean_function & obj)
{
	std::vector<bool> anf = obj.anf();
	std::string polynom;
	size_t plus = 0;    
	if (anf[0])
	{
		polynom += "1 ";
		++plus;
	}
	size_t i = 0;
	while (i < anf.size())
	{
		if (anf[i])
		{
			if (plus) polynom += " + ";
			size_t tmp = i, n = 1;
			plus = 0;
			while (tmp > 0)
			{
				if (tmp % 2 == 1)
				{
					polynom += "X";
					std::stringstream num;
					num << n;
					polynom += num.str() + " ";
					++plus;
				}
				tmp /= 2;
				++n;
			}
		}
		++i;
	}
	return polynom;
};
	

boolean_function operator + (const boolean_function& a, const boolean_function& b)
{
	boolean_function Result = a;
	Result += b;
	return Result;

};

boolean_function operator * (const boolean_function& a, const boolean_function& b)
{
	boolean_function Result = a;
	Result *= b;
	return Result;
};

boolean_function operator | (const boolean_function& a, const boolean_function& b)
{
	boolean_function Result = a;
	Result |= b;
	return Result;
};

bool operator != (const boolean_function& a, const boolean_function& b)
{
	return !(a == b);
};


#endif // __BOOLEAN_FUNCTION_INCLUDED__
