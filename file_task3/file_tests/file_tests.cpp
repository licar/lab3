// file_tests.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "../file_task4/MyFile.h"

BOOST_AUTO_TEST_CASE(FileCanBeOpen)
{
	{
		CMyFile file;
		BOOST_CHECK(file.Open("file.txt", "r"));
		BOOST_CHECK(file.IsOpened());
	}
	{
		CMyFile file;
		BOOST_CHECK(!file.IsOpened());
	}
}

BOOST_AUTO_TEST_CASE(FileCanBeOpenAgain)
{
	CMyFile file;
	
	BOOST_CHECK(file.Open("file.txt", "r"));
	BOOST_CHECK(file.IsOpened());

	BOOST_CHECK(file.Open("file.txt", "w"));
	BOOST_CHECK(file.IsOpened());

	BOOST_CHECK(file.Open("file.txt", "r"));
	BOOST_CHECK(file.IsOpened());
}

BOOST_AUTO_TEST_CASE(FileCanBeClose)
{
	{
		CMyFile file;
		BOOST_CHECK(file.Open("file.txt", "r"));
		file.Close();
		BOOST_CHECK(!file.IsOpened());
	}
	{
		CMyFile file;
		file.Open("file.txt", "w");
		file.Close();
		file.Close();
		BOOST_CHECK(!file.IsOpened());
	}
	{
		CMyFile file;
		file.Close();
		BOOST_CHECK(!file.IsOpened());
	}
}

BOOST_AUTO_TEST_CASE(CanGetChar)
{
	{
		CMyFile file;
		file.Open("file1.txt", "r");
		BOOST_CHECK_EQUAL(file.GetChar(), '=');
		BOOST_CHECK_EQUAL(file.GetChar(), '+');
		BOOST_CHECK_EQUAL(file.GetChar(), EOF);
		file.Close();
	}
	{
		CMyFile file;
		file.Open("fileout.txt", "w");
		BOOST_CHECK_EQUAL(file.GetChar(), EOF);
	}
	{
		CMyFile file;
		file.Open("file3.txt", "r");
		BOOST_CHECK_EQUAL(file.GetChar(), EOF);
	}
	{
		CMyFile file;
		//BOOST_CHECK_EQUAL(file.GetChar(), -2);
	}
}

BOOST_AUTO_TEST_CASE(CanCheckIsEOF)
{
	{
		CMyFile file;
		file.Open("file3.txt", "r");
		BOOST_CHECK_EQUAL(file.GetChar(), EOF);
		BOOST_CHECK(file.IsEndOfFile());
	}
	{
		CMyFile file;
		file.Open("file2.txt", "r");
		BOOST_CHECK(file.GetChar() != EOF);
		BOOST_CHECK(!file.IsEndOfFile());
	}
	{
		CMyFile file;
		//BOOST_CHECK(!file.IsEndOfFile());
	}
}

BOOST_AUTO_TEST_CASE(CanPutChar)
{
	{
		CMyFile file;
		BOOST_CHECK(file.Open("file2.txt", "w"));
		BOOST_CHECK(file.PutChar('a'));
		BOOST_CHECK(file.Open("file2.txt", "r"));
		BOOST_CHECK_EQUAL(file.GetChar(), 'a');
	}
	{
		CMyFile file;
		BOOST_CHECK(file.Open("file2.txt", "r"));
		BOOST_CHECK(!file.PutChar('a'));
	}
	{
		CMyFile file;
		//BOOST_CHECK(!file.PutChar('a'));
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
	{
		CMyFile file;
		file.Open("file6.txt", "w");
		BOOST_CHECK_EQUAL(file.Write("loves", 1, 5), 5);
		file.Open("file6.txt", "r");
		vector<char> data;
		data.resize(5);
		BOOST_CHECK_EQUAL(file.Read(data.data(), 1, 5), 5);
		string str = "loves";
		for (size_t i = 0; i != str.length(); ++i)
		{
			BOOST_CHECK_EQUAL(data[i], str[i]);
		}
	}
	{
		CMyFile file;
		//BOOST_CHECK_EQUAL(file.Write("loves", 1, 5), 0);
	}
}
