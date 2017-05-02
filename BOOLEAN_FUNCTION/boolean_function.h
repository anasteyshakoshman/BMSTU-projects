#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__

#include <string>
#include <vector>
#include <initializer_list>
#include <math.h>
#include <sstream>

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
		std::vector<bool> func;
		size_type i = 0;
		while (i < pow(2, dimension))
		{
			func.push_back(false);
			++i;
		}
		return boolean_function(func);
	};

	static boolean_function var(size_t n, size_t dimension)   //dimension - кол-во переменных, n - номер переменной, значения которой буду возвращены
	{
		if (dimension < n) throw std::logic_error("The number of nedeed element can not more than the quantity of alll elements");
		size_type tmp = dimension - n;
		std::vector<value_type> Xn;
		size_type i = 0;
		while (i < pow(2, dimension) / pow(2, tmp))
		{
			size_type j = 0;
			while (j < pow(2, tmp))
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
		std::vector<bool> func;
		size_type i = 0;
		while (i < pow(2, dimension))
		{
			func.push_back(true);
			++i;
		}
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
			Func.insert(Func.begin(), ost);
		}
		if (Func.size() > pow(2, n)) throw std::logic_error("The length of a given value in the binary system is more than the length of function of a given quantity of vars");
		while (Func.size() != pow(2, n))   Func.insert(Func.begin(), false);
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


	boolean_function& operator += (const boolean_function& rhs)
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


	bool operator ==(const boolean_function& rhs) const
	{
		size_t num;
		if (size() > rhs.size()) num = rhs.size();
		else num = size();
		size_type i = 0;
		while (i < num)
		{
			if (Func[i] != rhs.Func[i]) return false;
			++i;
		}
		return true;
	};


	bool operator >= (const boolean_function& rhs) const
	{
		if (Func.size() != rhs.Func.size()) throw std::length_error("Different quantity of elements");
		if (this == &rhs) return true;
		bool right = true, left = true;
		size_type i = 0;
		while (i < Func.size())
		{
			if (Func.at(i)< rhs.Func.at(i)) left = false;
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
		size_type n = dimension(), val = 0;
		for (auto it = vars.begin(); it != vars.end(); ++it)
		{
			val += (*it)*pow(2, n);
			n--;
		}
		return Func[val];
	};


	bool operator()(const std::initializer_list<bool>  vars) const
	{
		if (vars.size() != dimension()) throw std::length_error("The length of vars aren't equally");
		size_type Num = dimension() - 1, val = 0;
		for (auto it = vars.begin(); it != vars.end(); ++it) 
		{
			val += (*it)*pow(2, Num);
			Num--;
		}
		return Func[val];

	};


	


	/*boolean_function operator()(const std::vector<boolean_function>& fs) const
	{

	};

	boolean_function operator()(const std::initializer_list<boolean_function> vars) const
	{

	};*/

	bool is_monotone() const
	{
		size_type num = size();
		while ((num /= 2) > 0)
		{
			size_t i = 0;
			while (i < num)
			{
				size_type j = num;
				while (j--)
				{
					if (Func[i] > Func[i + num]) return false;
					++i;
				}
			}
			i += num;
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
		size_type i = 0;
		while (i < Func.size())
		{
			if (Func[i])
			{
				if (i != pow(2, i)) return false;
			}
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


 //пусть boolean_function представляет из себя функцию "01110000"
 //тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"


std::string get_polynom(const boolean_function& obj)
{
	std::string polynom;
	std::vector<bool> anf = obj.anf();
	if (anf[0] == 1) polynom += "1 + ";
	size_t i = 0, quan = 0;
	while (i < obj.size())
	{
		if (anf[i])
		{
			if(quan) polynom += " + ";
			size_t tmp = i, n = 0;
			quan = 0;
			while (tmp > 0)
			{
				if (tmp % 2 == 1)
				{
					polynom += "X";
					std::ostringstream ost;
					ost << n;
					std::string s_num = ost.str();
					polynom += s_num;
					quan++;
				}
				tmp /= 2;
				n++;
				if (tmp > 0 && anf[i] && tmp % 2 == 1 && quan != 0) polynom += " * ";
			}
		}
		++i;
	}
	return polynom;
}

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
