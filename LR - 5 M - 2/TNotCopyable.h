////Цель: применить RAII к классу TNotCopyable
////	В файле TNotCopyable.h реализована плохая обертка над FILE*.Как мы помним,
//если мы открываем файл, используя функцию fopen, то необходимо закрывать файл, вызвав функцию fclose.
////	В test.cpp приведет код, который подвержен проблеме : из - за возни
//кающего исклюнения не вызывается метод Close объекта obj.Необходимо создать
//класс, реализующий идиому RAII для класса TNotCopyable.С помощью 
//этого класса избавиться от описанной проблемы в файле test.cpp

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
	class TRAII
	{
	public:

		FILE * Ptr;

		TRAII() : Ptr(nullptr)
		{}

		TRAII(FILE * file) : Ptr(file)
		{}

		~TRAII()
		{
			fclose(Ptr);
		}

	};

	TRAII  Descriptor;

public:

	TNotCopyable() : Descriptor(nullptr)
	{}

	TNotCopyable(const TNotCopyable&) = delete;
	TNotCopyable& operator = (const TNotCopyable&) = delete;

	void OpenToWrite(std::string const & fileName)
	{
		if (Descriptor.Ptr != nullptr) throw FileAlreadyOpened();
		Descriptor = fopen(fileName.c_str(), "w");
	}

	void OpenToRead(std::string const & fileName)
	{
		if (Descriptor.Ptr != nullptr) throw FileAlreadyOpened();
		Descriptor = fopen(fileName.c_str(), "r");
	}

	void Close() throw()
	{
		if (Descriptor.Ptr != nullptr)
		{
			Descriptor = nullptr;
		}
	}

	FILE * Get()
	{
		return Descriptor.Ptr;
	}
};

#endif // __NOTCOPYABLE_INCLUDED__

