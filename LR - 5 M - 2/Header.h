#ifndef __NOTCOPYABLE_INCLUDED__
#define __NOTCOPYABLE_INCLUDED__
#include <string>

#pragma warning(disable:4996)
#include <exception>
#include <cstdio>
#include <string>





struct FileAlreadyOpened : public std::exception
{
	FileAlreadyOpened() = default;
	FileAlreadyOpened(const char* const message) : std::exception(message)
	{}
};

class TNotCopyable
{


	FILE * Descriptor;

public:

	TNotCopyable() : Descriptor(nullptr)
	{}

	TNotCopyable(const TNotCopyable&) = delete;
	TNotCopyable& operator = (const TNotCopyable&) = delete;

	void OpenToWrite(std::string const & fileName)
	{
		if (Descriptor != nullptr) throw FileAlreadyOpened();
		Descriptor = fopen(fileName.c_str(), "w");
	}

	void OpenToRead(std::string const & fileName)
	{
		if (Descriptor != nullptr) throw FileAlreadyOpened();
		Descriptor = fopen(fileName.c_str(), "r");
	}

	void Close() throw()
	{
		if (Descriptor != nullptr)
		{
			Descriptor = nullptr;
		}
	}

	FILE * Get()
	{
		return Descriptor;
	}
};


class TRAII
{
public:

	TNotCopyable * Des;

	TRAII() : Des(nullptr)
	{}

	TRAII(TNotCopyable * filename) : Des(filename)
	{}

	~TRAII()
	{
		Des->Close();
	}

};

#endif // __NOTCOPYABLE_INCLUDED__

