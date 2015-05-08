#pragma once
#include <string>
#include <vector>
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
	int Read(void * ptr, size_t size, size_t count);
	int Write(const void * ptr, size_t size, size_t count);


	bool IsOpened() const;
	bool IsEndOfFile() const;
	int GetLength();
	int GetPosition() const;

private:
	FILE *m_file;
};

