#pragma once
#include <iostream>
#include <exception>


class TCastException : public std::exception
{
public:
	TCastException() : exception()
	{}
	TCastException(const char * const & data) : exception(data)
	{}
};

class TUnknown : public TCastException
{
public:
	TUnknown() : TCastException()
	{}
	TUnknown(const char * const & data) : TCastException(data)
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


//пponoтипы функций:
int intFromString(const char * data);
bool boolFromString(const char * data);
float floatFromString(const char * data);




