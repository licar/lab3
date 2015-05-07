#pragma once
#include <string>

using namespace std;

class CMyFile
{
public:
	CMyFile();
	~CMyFile();

	enum Error
	{
		FILE_ERROR = -2
	};

	bool Open(string const &fileName, string  const &mode);
	void Close();
	int GetChar();
	bool PutChar(int character);
	bool Seek(int position);
	string Read(const int count);
	int Write(string const &str);


	bool IsOpened() const;
	bool IsEndOfFile() const;
	int GetLength();
	int GetPosition() const;

private:
	FILE *m_file;
};

