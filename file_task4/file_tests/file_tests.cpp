// file_tests.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "../file_task4/MyFile.h"

BOOST_AUTO_TEST_CASE(FileCanBeOpen)
{
	CMyFile file;
	{
		BOOST_CHECK(file.Open("file.txt", "r"));
		BOOST_CHECK(file.IsOpened());
	}
}

BOOST_AUTO_TEST_CASE(FileCanBeOpenAgain)
{
	CMyFile file;
	BOOST_CHECK(file.Open("file.txt", "r"));
	BOOST_CHECK(file.IsOpened());

	BOOST_CHECK(file.Open("file.txt", "w"));
	BOOST_CHECK(file.IsOpened());
}

BOOST_AUTO_TEST_CASE(FileCanBeClose)
{
	//CMyFile file;
	//BOOST_CHECK(file.Open("file.txt", "r"));
	//file.Close();
}

BOOST_AUTO_TEST_CASE(CanGetChar)
{
	CMyFile file;
	{
		file.Open("file1.txt", "r");
		BOOST_CHECK_EQUAL(file.GetChar(), '=');
		BOOST_CHECK_EQUAL(file.GetChar(), '+');
		BOOST_CHECK_EQUAL(file.GetChar(), EOF);
		file.Close();
	}
	{
		/*file.Open("file3.txt", "r");
		BOOST_CHECK_EQUAL(file.GetChar(), -2);
		*/
	}
}

BOOST_AUTO_TEST_CASE(CanCheckIsEOF)
{
	CMyFile file;
	{
		BOOST_CHECK(file.Open("file2.txt", "r"));
		BOOST_CHECK_EQUAL(file.GetChar(), 'a');
		file.GetChar();
		BOOST_CHECK(file.IsEndOfFile());
	}
}

BOOST_AUTO_TEST_CASE(CanPutChar)
{
	CMyFile file;
	{
		BOOST_CHECK(file.Open("file2.txt", "w"));
		BOOST_CHECK(file.PutChar('a'));
		BOOST_CHECK(file.Open("file2.txt", "r"));
		BOOST_CHECK(!file.PutChar('a'));
	}
}

BOOST_AUTO_TEST_CASE(CanSeek)
{
	CMyFile file;
	{
		BOOST_CHECK(file.Open("file1.txt", "r"));
		BOOST_CHECK(file.Seek(2));
		BOOST_CHECK(!file.Seek(-2));
		BOOST_CHECK(file.Seek(5));
	}
}

BOOST_AUTO_TEST_CASE(ReturnCurrPosition)
{
	CMyFile file;
	{
		file.Open("file1.txt", "r");
		BOOST_CHECK_EQUAL(file.GetPosition(), 0);
		file.Seek(12);
		BOOST_CHECK_EQUAL(file.GetPosition(), 12);
	}
}

BOOST_AUTO_TEST_CASE(CanGetLenght)
{
	CMyFile file;
	{
		file.Open("file1.txt", "r");
		BOOST_CHECK_EQUAL(file.GetLength(), 2);
		BOOST_CHECK_EQUAL(file.GetPosition(), 0);
	}
}

