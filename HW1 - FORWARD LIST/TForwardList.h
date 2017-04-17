#pragma once
#include <iostream>
#include <initializer_list>
#include "TException.h"

template <class Type>

class TForwardList
{
private:
	using value_type = Type;
	using size_type = size_t;
	using reference = value_type &;
	using const_reference = const value_type &;

public:

	struct Node
	{
		value_type Data;
		Node * Next;
		Node() : Data(0), Next(nullptr)
		{};
	};
	friend class TForwardList;

private:

	Node * Head;
	size_type Num;


public:

	explicit TForwardList(size_type num, const value_type &val = value_type())
	{
		if (num > max_size()) throw TUnknownValue("Number of elements is more than size_max");
		Node * tmp = nullptr;
		Head = nullptr;
		Num = num;
		for (size_type i = 0; i < Num; ++i)
		{
			if (!i)
			{
				Head = new Node();
				if (!Head) throw TMemoryLeaks("Memory leaks");
				Head->Data = val;
				Head->Next = nullptr;
			}
			else
			{
				tmp = new Node();
				if (!tmp) throw TMemoryLeaks("Memory leaks");
				tmp->Data = val;
				tmp->Next = Head;
				Head = tmp;
			}
		}
	};  

	


	friend std::ostream & operator <<(std::ostream & out, TForwardList & obj)
	{
		Node * tmp = obj.Head;
		while (tmp)
		{
			out << tmp->Data << " ";
			tmp = tmp->Next;
		}
		return out;
	};

	TForwardList(const TForwardList  <value_type> & obj)
	{
		Head = nullptr;
		Num = obj.Num;
		Node * tmp1 = nullptr;
		Node * tmp2 = nullptr;
		do
		{
			if (!Head)
			{
				Head = new Node;
				if (!Head) throw TMemoryLeaks("Memory leaks!");
				Head->Data = obj.Head->Data;
				tmp1 = Head;
				tmp2 = obj.Head->Next;
			}
			else
			{
				tmp1->Next = new Node;
				if (!tmp1->Next) throw TMemoryLeaks("Memory leaks!");
				tmp1 = tmp1->Next;
				tmp1->Data = tmp2->Data;
				tmp2 = tmp2->Next;
			}
		} while (tmp2);
	};

	TForwardList & operator =(const TForwardList<value_type> & obj)
	{
		if (&obj == this) return *this;
		while (Head)
		{
			Node * tmp = Head->Next;
			delete Head;
			Head = tmp;
		}
		Head = nullptr;
		Num = obj.Num;
		Node * tmp1 = nullptr;
		Node * tmp2 = nullptr;
		do
		{
			if (!Head)
			{
				Head = new Node();
				Head->Data = obj.Head->Data;
				tmp1 = Head;
				tmp2 = obj.Head->Next;
			}
			else
			{
				tmp1->Next = new Node();
				tmp1 = tmp1->Next;
				tmp1->Data = tmp2->Data;
				tmp2 = tmp2->Next;
			}
		} while (tmp2);
	};

	~TForwardList()
	{
		while (Head)
		{
			Node * tmp = Head->Next;
			delete Head;
			Head = tmp;
		}
		Num = 0;
	};

	size_type size() const
	{
		return Num;
	};

	size_type max_size() const
	{
		return SIZE_MAX;
	};

	bool empty() const
	{
		return !Num;
	};

	void pop_back()
	{
		if (!Head)  throw TEmptyList("This list is empty");
		Node * 	last = Head;
		while (last->Next) last = last->Next;
		if (Num != 1)
		{
			Node * beforeLast = Head;
			while (beforeLast->Next != last) beforeLast = beforeLast->Next;
			beforeLast->Next = nullptr;
		}
		else Head = nullptr;
		delete last;
		Num--;
	};

	void pop_front()
	{
		if (!Head) throw TEmptyList("This list is empty");
		Node * tmp = Head->Next;
		delete Head;
		if (tmp) Head = tmp;
		else Head = nullptr;
		Num--;
	};

	void push_back(const value_type &val)
	{
		if (!Head)
		{
			Head = new Node;
			Head->Data = val;
			Head->Next = nullptr;
		}
		else
		{
			Node * 	tmp = Head;
			while (tmp->Next) tmp = tmp->Next;
			Node * newNode = new Node();
			newNode->Data = val;
			tmp->Next = newNode;
			newNode->Next = nullptr;
		}
		Num++;
	};

	void push_front(const value_type &val)
	{
		if (!Head)
		{
			Head = new Node();
			Head->Data = val;
			Head->Next = nullptr;
		}
		else
		{
			Node * tmp = new Node();
			tmp->Data = val;
			tmp->Next = Head;
			Head = tmp;
		}
		Num++;
	};

	void remove(const value_type &val)
	{
		Node * tmp = Head;
		Node * tmp2 = nullptr;
		while (tmp)
		{
			tmp2 = tmp->Next;
			if (tmp->Data == val)
			{
				if (tmp == Head)
				{
					delete Head;
					Head = tmp2;
				}
				else
				{
					Node * before = Head;
					while (before->Next != tmp) before = before->Next;
					before->Next = tmp->Next;
					delete tmp;
				}
				Num--;
			}
			tmp = tmp2;
		}
	};

	void resize(size_type num, const value_type val = value_type())
	{
		if (num < 0) throw TUnknownValue("Uncorrect value of number");
		if (num == Num) return;
		if (!num)
		{
			while (Head)
			{
				Node * tmp = Head->Next;
				delete Head;
				Head = tmp;
			}
			Num = 0;
		}
		if (Num > num)
		{
			Node * last = Head;
			for (size_type i = 1; i < num; ++i) last = last->Next;
			Node * del = last->Next;
			while (del->Next)
			{
				Node * delNext = del->Next;
				delete del;
				del = delNext;
			}
			last->Next = nullptr;
		}
		if (Num < num)
		{
			if (!Head)
			{
				Head = new Node;
				Head->Data = val;
				Head->Next = nullptr;
			}
			Node * tmp = Head;
			while (tmp->Next) tmp = tmp->Next;
			size_type i = 0;
			if (tmp == Head) i = 1;
			for (i; i < num - Num; ++i)
			{
				tmp->Next = new Node;
				tmp->Next->Data = val;
				tmp = tmp->Next;
			}
		}
		Num = num;
	};

	void clear()
	{
		while (Head)
		{
			Node * tmp = Head->Next;
			delete Head;
			Head = tmp;
		}
		Num = 0;
	};

	void swap(TForwardList<value_type> &ob)
	{
		std::swap(Num, ob.Num);
		std::swap(Head, ob.Head);
	}

	void assign(size_type num, const value_type & val)
	{
		if (!num) return;
		if ((Num + num) > max_size()) throw std::length_error("This number more than SIZE_MAX");
		if (!Head)
		{
			Head = new Node();
			Head->Data = val;
			Head->Next = nullptr;
			num--;
		}
		Node * tmp = Head;
		while (tmp->Next) tmp = tmp->Next;
		for (size_type i = 0; i < num; ++i)
		{
			tmp->Next = new Node();
			tmp->Next->Data = val;
			tmp = tmp->Next;
		}
		Num += num;
	};

	void sort()
	{
		if (!Head) throw TEmptyList("This list is empty");
		Node * tmp1 = Head;
		Node * tmp2 = Head->Next;
		while (tmp1->Next)
		{
			while (tmp2)
			{
				if (tmp1->Data > tmp2->Data)
				{
					std::swap(tmp1->Data, tmp2->Data);
				}
				tmp2 = tmp2->Next;
			}
			tmp1 = tmp1->Next;
			tmp2 = tmp1->Next;
		}
	};

	void unique()
	{
		if (!Head) throw TEmptyList("This list is empty");
		Node * tmp1 = Head;
		Node * tmp2 = nullptr;
		while (tmp1)
		{
			tmp2 = tmp1->Next;
			while (tmp2)
			{
				Node * tmp = tmp2->Next;
				if (tmp1->Data == tmp2->Data)
				{
					Node * before = Head;
					while (before->Next != tmp2) before = before->Next;
					before->Next = tmp;
					delete tmp2;
					Num--;
				}
				tmp2 = tmp;
			}
			tmp1 = tmp1->Next;
		}
	}

	void reverse()
	{
		if (!Head) throw TEmptyList("This list is empty");
		if (Num == 1) return;
		Node * head = Head;
		Node * last = Head;
		while (last->Next) last = last->Next;
		for (size_type i = 0; i < Num / 2; ++i)
		{
			std::swap(head->Data, last->Data);
			head = head->Next;
			Node * beforelast = Head;
			while (beforelast->Next != last) beforelast = beforelast->Next;
			last = beforelast;
		}
	};

	class TIterator
	{
	public:

		Node * Uzel;
		TForwardList * List;


		TIterator(TForwardList * l) : List(l)
		{
			Uzel = new Node;

		}

		TIterator(Node * uzel, TForwardList * l) : List(l), Uzel(uzel) { };

		TIterator(const TIterator & obj)
		{
			Uzel = obj.Uzel;
			List = obj.List;
		}

		TIterator & operator=(const TIterator & obj)
		{
			if (&obj == this) return *this;
			if (Uzel) delete Uzel;
			Uzel = obj.Uzel;
			if (List) delete List;
			List = obj.List;
			return *this;
		}

		bool operator==(const TIterator & other) const
		{
			return ((Uzel == other.Uzel) && (List == other.List));
		};

		bool operator!=(const TIterator & other) const
		{
			return (Uzel != other.Uzel);
		};

		const_reference operator*() const
		{
			if (Uzel) return (Uzel->Data);
			else throw std::exception("It's the end of list");
		};

		reference operator*()
		{
			if (Uzel) return (Uzel->Data);
			else throw std::exception("It's the end of list");
		}


		TIterator & operator++()
		{
			if (Uzel) Uzel = Uzel->Next;
			else throw std::exception("It's the end of list");
			return *this;
		};

	};
	friend class TForwardList;


private:


	using iterator = TIterator;
	using const_iterator = const TIterator;


public:

	TForwardList(const_iterator first, const_iterator last)
	{
		Head = nullptr;
		Node * tmp = nullptr;
		TIterator head(first);
		while (head.Uzel->Next != last.Uzel)
		{
			if (!Head)
			{
				Head = new Node;
				if (!Head) throw TMemoryLeaks("Memory leaks");
				Head->Next = nullptr;
				Head->Data = *head;
				head++;
			}
			else
			{
				tmp = new Node();
				if (!tmp) throw TMemoryLeaks("Memory leaks");
				tmp->Data = *head;
				tmp->Next = Head;
				Head = tmp;
				head++;
			}
		}
	}


	iterator insert_after(const_iterator pos, const value_type & value)
	{
		if (pos == end()) push_back(value);
		else
		{
			TIterator next (pos);
			next++;
			TIterator nodeNew(this);
			*nodeNew = value;
			pos.Uzel->Next = nodeNew.Uzel;
			nodeNew.Uzel->Next = next.Uzel;
		}
		TIterator after(pos);
		after++;
		after++;
		return after;
	};

	iterator erase_after(const_iterator position)
	{
		TIterator tmp(position);
		tmp++;   tmp++;
		delete position.Uzel->Next;
		position.Uzel->Next = tmp.Uzel;
		return tmp;
	};

	iterator erase_after(const_iterator start, const_iterator end)
	{
		TIterator st(start);
		while (st.Uzel->Next != end.Uzel)
		{
			TIterator tmp(st);
			tmp++; tmp++;
			delete start.Uzel->Next;
			start.Uzel->Next = tmp.Uzel;
			st++;
		}
		return end;
	};

	iterator end()
	{
		if (!Head)  throw TEmptyList("This list is empty");
		Node * tmp = Head;
		while (tmp->Next) tmp = tmp->Next;
		TIterator end(tmp, this);
		return end;
	};

	iterator сend() const
	{
		if (!Head)  throw TEmptyList("This list is empty");
		Node * tmp = Head;
		while (tmp->Next) tmp = tmp->Next;
		TIterator end(tmp, this);
		return end;
	};

	iterator begin()
	{
		if (!Head)  throw TEmptyList("This list is empty");
		TIterator head(Head, this);
		return head;
	};

	iterator сbegin() const
	{
		if (!Head)  throw TEmptyList("This list is empty");
		TIterator head(Head, this);
		return head;
	};

	
	bool operator==(const  TForwardList<value_type> & rhs) const
	{
		if (Num != rhs.Num) return false;
		Node * headLhs = Head;
		Node * headRhs = rhs.Head;
		while (headLhs)
		{
			if (headLhs->Data != headRhs->Data) return false;
			headLhs = headLhs->Next;
			headRhs = headRhs->Next;
		}
		return true;
	};

	bool operator<(const  TForwardList<value_type> & rhs) const
	{
		if (Num > rhs.Num) return false;
		Node * headLhs = Head;
		Node * headRhs = rhs.Head;
		while (headLhs)
		{
			if (headLhs->Data >= headRhs->Data) return false;
			headLhs = headLhs->Next;
			headRhs = headRhs->Next;
		}
		return true;
	};

	bool operator<=(const  TForwardList<value_type> & rhs) const
	{
		if (Num > rhs.Num) return false;
		Node * headLhs = Head;
		Node * headRhs = rhs.Head;
		while (headLhs)
		{
			if (headLhs->Data > headRhs->Data) return false;
			headLhs = headLhs->Next;
			headRhs = headRhs->Next;
		}
		return true;
	}



};

template <class Type>
bool operator!=(const TForwardList <Type> & lhs, const  TForwardList<Type> & rhs)
{
	return !(lhs == rhs);
}


template <class Type>
bool operator>(const TForwardList <Type> & lhs, const  TForwardList<Type> & rhs)
{
	return !(lhs <= rhs);
}


template <class Type>
bool operator>=(const TForwardList <Type> & lhs, const  TForwardList<Type> & rhs)
{
	return !(lhs < rhs);
};




