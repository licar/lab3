// file_task4.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "MyFile.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CMyFile fileInput;
	CMyFile fileOutput;

	string fileInputName = argv[1];
	string fileOutputName = argv[2];

	fileInput.Open(fileInputName, "r");
	if (!fileInput.IsOpened())
	{
		cout << "File didn't open";
		return 1;
	}

	fileOutput.Open(fileOutputName, "w");
	if (!fileInput.IsOpened())
	{
		cout << "File didn't open";
		return 1;
	}

	vector<char> data;
	data.resize(fileInput.GetLength());

	if (fileInput.Read(data.data(), 1, fileInput.GetLength())
		!= fileInput.GetLength())
	{
		cout << "Did't read from file";
		return 1;
	}

	reverse(data.begin(), data.end());

	if (fileOutput.Write(data.data(), 1, data.size())
		!= data.size())
	{
		cout << "Did't write to file";
		return 1;
	}
	
	return 0;
}

