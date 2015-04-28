#include "stdafx.h"
#include "Canvas.h"

CCanvas::CCanvas(unsigned widht, unsigned height)
{
	std::vector<char> line(widht, ' ');
	for (size_t i = 0; i != height; ++i)
	{
		m_canvas.push_back(line);
	}
}

CCanvas::~CCanvas()
{
}

unsigned CCanvas::GetWidht() const
{
	if (m_canvas.size() > 0)
	{
		return m_canvas[0].size();
	}
	return 0;
};

unsigned CCanvas::GetHeight() const
{
	return m_canvas.size();
};

void CCanvas::Clear(char code)
{
	if (code < ' ')
	{
		return;
	}

	for (size_t y = 0; y != GetHeight(); ++y)
	{
		for (size_t x = 0; x != GetWidht(); ++x)
		{
			m_canvas[y][x] = code;
		}
	}
}

void CCanvas::SetPixel(int x, int y, char code)
{
	if (code < ' ')
	{
		return;
	}

	if (x < 0 || x > (int) GetWidht() ||
		y < 0 || y > (int) GetHeight())
	{
		return;
	}

	m_canvas[y][x] = code;
}

char CCanvas::GetPixel(int x, int y) const
{
	if (x < 0 || x > (int)GetWidht() ||
		y < 0 || y > (int)GetHeight())
	{
		return ' ';
	}

	return m_canvas[y][x];
}

void CCanvas::Write(std::ostream &ostream) const
{
	for (auto line : m_canvas)
	{
		for (auto pixel : line)
		{
			ostream << pixel;
		}
		ostream << '\n';
	}
}

void FillRectangle(CRectangle const &rect,
	char code, CCanvas &canvas)
{
	for (size_t y = rect.GetTop(); y != (size_t)rect.GetBottom(); ++y)
	{
		for (size_t x = rect.GetLeft(); x != (size_t)rect.GetRight(); ++x)
		{
			canvas.SetPixel(x, y, code);
		}
	}
}