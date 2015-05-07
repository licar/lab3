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
	{
		BOOST_CHECK(file.Open("file.txt", "r"));
		BOOST_CHECK(file.IsOpened());

		BOOST_CHECK(file.Open("file.txt", "w"));
		BOOST_CHECK(file.IsOpened());
	}
}

BOOST_AUTO_TEST_CASE(FileCanBeClose)
{
	CMyFile file;
	{
		BOOST_CHECK(file.Open("file.txt", "r"));
		file.Close();
		BOOST_CHECK(!file.IsOpened());
	}
	{
		file.Open("file.txt", "w");
		file.Close();
		file.Close();
		BOOST_CHECK(!file.IsOpened());
	};
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
		file.Open("fileout.txt", "w");
		int character = file.GetChar();
		BOOST_CHECK_EQUAL(character, EOF);
	}
	{
		file.Open("file3.txt", "r");
		int character = file.GetChar();
		file.GetChar();
		BOOST_CHECK_EQUAL(character, EOF);
	};
}

BOOST_AUTO_TEST_CASE(CanCheckIsEOF)
{
	CMyFile file;
	{
		file.Open("file3.txt", "r");
		file.GetChar();
		BOOST_CHECK(file.IsEndOfFile());
	}
	{
		file.Open("file2.txt", "r");
		BOOST_CHECK(!file.IsEndOfFile());
	}
	{
		file.Open("file3.txt", "w");
		BOOST_CHECK(file.IsEndOfFile());
	}
	{
		file.Open("file3.txt", "w");
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
		BOOST_CHECK_EQUAL(file.GetChar(), 'a');
	}
	{
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
		BOOST_CHECK_EQUAL(file.GetPosition(), 2);
		BOOST_CHECK(!file.Seek(-2));
		BOOST_CHECK_EQUAL(file.GetPosition(), 2);
		BOOST_CHECK(file.Seek(5));
		BOOST_CHECK_EQUAL(file.GetPosition(), 5);
	}
}
/*
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
		file.Open("file5.txt", "r");
		BOOST_CHECK_EQUAL(file.GetLength(), 50);
		BOOST_CHECK_EQUAL(file.GetPosition(), 0);
	}
}

BOOST_AUTO_TEST_CASE(CanWriteBlock)
{
	CMyFile file;
	{
		file.Open("file6.txt", "w");
		BOOST_CHECK_EQUAL(file.Write("love"), 4);
		file.Open("file6.txt", "r");
		BOOST_CHECK_EQUAL(file.Read(4), "love");
	}
}
*/
