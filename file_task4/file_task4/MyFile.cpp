#include "stdafx.h"
#include "MyFile.h"
#include <stdlib.h>
#include <stdio.h>

CMyFile::CMyFile()
	:m_file(nullptr)
{
}

CMyFile::~CMyFile()
{
	Close();
}

bool CMyFile::Open(string const &fileName, string const &mode)
{
	Close();

	if (fopen_s(&m_file, fileName.c_str(), mode.c_str()) != 0)
	{
		m_file = nullptr;
	}

	return IsOpened();
}

void CMyFile::Close()
{
	if (m_file)
	{
		fclose(m_file);
		m_file = nullptr;
	}
}

bool CMyFile::IsOpened() const
{
	return (m_file != nullptr);
}

bool CMyFile::IsEndOfFile() const
{
	return (m_file && feof(m_file));
}

int CMyFile::GetChar()
{
	if (IsEndOfFile())
	{
		return EOF;
	}
	
	int character = fgetc(m_file);
	
	if (!character || !IsOpened())
	{
		return FILE_ERROR;
	}

	return character;
}

bool CMyFile::PutChar(int character)
{
	if (fputc(character, m_file) != character)
	{
		return false;
	}
	return true;
}

bool CMyFile::Seek(unsigned position)
{
	if (fseek(m_file, position, SEEK_SET) == 0)
	{
		return true;
	}
	return false;
}

int CMyFile::GetLength()
{
	int currPositon = GetPosition();
	Seek(SEEK_END);
	int position = GetPosition();
	Seek(currPositon);
	return position;
}

int CMyFile::GetPosition() const
{
	return ftell(m_file);
}

int CMyFile::Write(string const &str)
{
	return fwrite(str.c_str(), str.length(),
		str.length(), m_file);
}

string CMyFile::Read(string const &str, const unsigned count)
{
	char * buffer;
	malloc(count);
	int numberRead = fread(&buffer, count, count, m_file);
	
	string str;
	for (int i = 0; i != numberRead; ++i)
	{
		str.push_back(buffer[i]);
	}

	}

}