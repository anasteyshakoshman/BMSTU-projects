#pragma once
#include <iostream>
#include <exception>


class TCastException : public std::exception
{
public:
	TCastException() : exception()
	{}
	TCastException(const char *  data) : exception(data)
	{}
};

class TUnknown : public TCastException
{
public:
	TUnknown() : TCastException()
	{}
	TUnknown(const char *  data) : TCastException(data)
	{}
};

class TMax : public TCastException
{
public:
	TMax() : TCastException()
	{}
	TMax(const char * data) : TCastException(data)
	{}
};

class TMin : public TCastException
{
public:
	TMin() : TCastException()
	{}
	TMin(const char * data) : TCastException(data)
	{}	
};



//пponoтипы функций:
template <typename T>
T FromString(const char * data);
template <>
int FromString <int> (const char * data);
template <>
bool FromString <bool> (const char * data);
template <>
float FromString <float> (const char * data);







