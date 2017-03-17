#include <exception>

class TCastException : public std::exception
{
public:
	TCastException() : std::exception()
	{}
	TCastException(const char * const & data) : std::exception(data)
	{}
};


class TMax : public TCastException
{
public:
	TMax() : TCastException()
	{}
	TMax(const char * const & data) : TCastException(data)
	{}
};

class TMin : public TCastException
{
public:
	TMin() : TCastException()
	{}
	TMin(const char * const & data) : TCastException(data)
	{}
};
