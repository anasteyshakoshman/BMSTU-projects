#include <exception>


class TCastException : public std::exception
{
public:
	TCastException() : exception()
	{}
	TCastException(const char *  data) : exception(data)
	{}
};

class TUnknownValue : public TCastException
{
public:
	TUnknownValue() : TCastException()
	{}
	TUnknownValue(const char *  data) : TCastException(data)
	{}
};

class TEmptyList : public TCastException
{
public:
	TEmptyList() : TCastException()
	{}
	TEmptyList(const char * data) : TCastException(data)
	{}
};

class TMemoryLeaks : public TCastException
{
public:
	TMemoryLeaks() : TCastException()
	{}
	TMemoryLeaks(const char * data) : TCastException(data)
	{}
};
