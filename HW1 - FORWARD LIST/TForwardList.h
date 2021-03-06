#pragma once
#include <iostream>
#include <initializer_list>
#include "TException.h"
#include <string>


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
		
	};

private:

	Node * Head;
	size_type Num;


public:

	explicit TForwardList()
	{
		Head = nullptr;
		Num = 0;
	};

	

	explicit TForwardList(size_type num, const value_type &val = value_type())
	{
		if (num > max_size()) throw TUnknownValue("Number of elements is more than size_max");
		Head = nullptr;
		Num = 0;
		while (Num != num)
		{
			push_back(val);
		}
	};  

	
	explicit TForwardList(std::initializer_list<value_type> init)
	{
		Head = nullptr;
		Num = 0;
		for (auto & i : init)
		{
			push_back(i);			
		}
	};



	friend std::ostream & operator <<(std::ostream & out, TForwardList<value_type> & obj)
	{
		Node * tmp = obj.Head;
		while (tmp)
		{
			out << tmp->Data << "  ";
			tmp = tmp->Next;
		}
		return out;
	};

	

	TForwardList(const TForwardList<value_type> & obj)
	{
		Head = nullptr;
		if (obj.Num)
		{
			Node * tmp = obj.Head;
			while (Num != obj.Num)
			{
				push_back(tmp->Data);
				tmp = tmp->Next;
			}
		}
		else Num = 0;		
	};

	TForwardList & operator =(const TForwardList<value_type> & obj)
	{
		if (&obj == this) return *this;
		if (Num) clear();
		Head = nullptr;
		if (obj.Num)
		{
			Node * tmp = obj.Head;
			while (Num != obj.Num)
			{
				push_back(tmp->Data);
				tmp = tmp->Next;
			}
		}
		else Num = 0;
		return *this;
	};

	~TForwardList()
	{
		clear();
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
		delete last;
		if (Num == 1) Head = nullptr;
		Num--;
	};

	void pop_front()
	{
		if (!Head) throw TEmptyList("This list is empty");
		Node * tmp = Head->Next;
		delete Head;
		Head = tmp;
		Num--;
	};

	void push_back(const value_type & val)
	{
		if (!Head) push_front(val);
		else
		{
			Node * 	tmp = Head;
			while (tmp->Next) tmp = tmp->Next;
			Node * newNode = new Node;
			if (!newNode) throw TMemoryLeaks("Memory leaks");
			newNode->Data = val;
			tmp->Next = newNode;
			newNode->Next = nullptr;
			Num++;
		}
		
	};

	void push_front(const value_type & val)
	{
		if (!Head)
		{
			Head = new Node;
			if (!Head) throw TMemoryLeaks("Memory leaks");
			Head->Data = val;
			Head->Next = nullptr;
		}
		else
		{
			Node * tmp = new Node;
			if (!tmp) throw TMemoryLeaks("Memory leaks");
			tmp->Data = val;
			tmp->Next = Head;
			Head = tmp;
		}
		Num++;
	};

	void remove(const value_type & val)
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

	void resize(size_type num, const value_type & val = value_type())
	{
		if (num < 0) throw TUnknownValue("Uncorrect value of number");
		if (num == Num) return;
		if (!num) clear();
		if (Num > num)
		{
			while (Num != num) pop_back();
		}
		if (Num < num)
		{
			while (Num != num) push_back(val);
		}
	};

	void clear()
	{
		while (Head)
		{
			Node * tmp = Head->Next;
			delete Head;
			Head = tmp;
		}
		Head = nullptr;
		Num = 0;
	};

	void swap(TForwardList<value_type> & ob)
	{
		std::swap(Num, ob.Num);
		std::swap(Head, ob.Head);
	}

	void assign(size_type n, const value_type & val)
	{
		if (!n) return;
		if ((Num + n) > max_size()) throw std::length_error("This number more than SIZE_MAX");
		while (Num != n) push_back(val);
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

	reference front()
	{
		if (!Head) throw TEmptyList("The list is empty");
		return Head->Data;
	};

	const_reference front() const
	{
		if (!Head) throw TEmptyList("The list is empty");
		return Head->Data;
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
	private:

		Node * Uzel;

	public:

		TIterator()
		{
			Uzel = new Node;
			if (!Uzel) throw TMemoryLeaks("Memory leaks");
		}

		TIterator(Node * uzel) :  Uzel(uzel)
		{ };

		TIterator(const TIterator & obj)
		{
			Uzel = obj.Uzel;
		}


		TIterator & operator=(const TIterator & obj)
		{
			if (&obj == this) return *this;
			if (Uzel) delete Uzel;
			Uzel = obj.Uzel;
			return *this;
		}

		bool operator==(const TIterator & other) const
		{
			return (Uzel == other.Uzel);
		};

		bool operator!=(const TIterator & other) const
		{
			return (Uzel != other.Uzel);
		};

		reference operator*() const
		{
			if (Uzel) return (Uzel->Data);
			else throw std::exception("It's the end of list");
		};

		const_reference operator*()
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

		const TIterator operator++(int)
		{
			TIterator result(*this);
			++*this;
			return result;
		}


		Node * node() const
		{
			return Uzel;
		}
	};


private:


	using iterator = TIterator;
	using const_iterator = const TIterator;


public:

	explicit TForwardList(const_iterator first, const_iterator last)
	{ 
		Head = nullptr;
		Node * tmp = nullptr;
		TIterator head(first);
		while (head != last)
		{
			if (!Head)
			{
				Head = new Node;
				if (!Head) throw TMemoryLeaks("Memory leaks");
				Head->Next = nullptr;
				Head->Data = *head;
				head++;
				Num++;
			}
			else
			{
				tmp = new Node();
				if (!tmp) throw TMemoryLeaks("Memory leaks");
				tmp->Data = *head;
				tmp->Next = Head;
				Head = tmp;
				head++;
				Num++;
			}
		}
		reverse();
	};


	iterator insert_after(const_iterator pos, const_reference value)
	{
		if (pos == end())
		{
			push_back(value);
			Node * last = Head;
			while (last != nullptr) last = last->Next;
			return TIterator(last);
		}
		else
		{
			Node * position = pos.node();
			Node * nodeNew = new Node;
			if (!nodeNew) throw TMemoryLeaks("Memory leaks");
			nodeNew->Data = value;
			nodeNew->Next = position->Next->Next;
			position->Next = nodeNew;
			Num++;
			return TIterator(nodeNew);
		}
		
	};

	 iterator erase_after(const_iterator position)
	{
		 if (position == end()) throw TUnknownValue("Can not erase invalide null element");
		 Node * tmp = Head;
		 while (tmp->Next) tmp = tmp->Next;
		 if (position == TIterator(tmp)) throw std::length_error("It's the end of the list");
 		 Node * next = position.node();
		 next = next->Next->Next;
		 Node * pos = position.node();
		 delete pos->Next;
		 pos->Next = next;
		 return TIterator(next);
	};

	 iterator erase_after(const_iterator position, const_iterator last)
	{
		 if (position == end()) throw std::length_error("It's the end of the list");
		 TIterator tmp(position);
		 Node * fir = position.node();
		 Node * las = last.node();
		 while (fir->Next != las)
		 {
			 Node * next = fir;
			 next = next->Next->Next;
			 delete fir->Next;
			 fir->Next = next;
			 fir = fir->Next;
			 Num--;
		 }
		 return last;
	};

	iterator end()
	{
		if (!Head)  throw TEmptyList("This list is empty");
		return TIterator(nullptr);
	};

	iterator сend() const
	{
		if (!Head)  throw TEmptyList("This list is empty");
		return TIterator(nullptr);
	};

	iterator begin()
	{
		if (!Head)  throw TEmptyList("This list is empty");
		return TIterator(Head);
	};

	iterator сbegin() const
	{
		if (!Head)  throw TEmptyList("This list is empty");
		return TIterator(Head);
	};

	
	bool operator ==(const  TForwardList<value_type> & rhs) const
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

	bool operator <(const  TForwardList<value_type> & rhs) const
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




