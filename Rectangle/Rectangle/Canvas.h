#pragma once
#include <vector>
#include <fstream>
#include "CRectangle.h"

class CCanvas
{
public:
	CCanvas(unsigned widht, unsigned height);
	~CCanvas();

	unsigned GetWidht() const;
	unsigned GetHeight() const;
	char GetPixel(int x, int y) const;
	void Write(std::ostream &ostream) const;

	void Clear(char code = ' ');
	void SetPixel(int x, int y, char code);
private:
	std::vector<std::vector<char>> m_canvas;
};

void FillRectangle(CRectangle const &rect,
	char code, CCanvas &canvas);