#include "stdafx.h"
#include "CRectangle.h"
#include <algorithm>

CRectangle::CRectangle()
{
}

CRectangle::CRectangle(int left, int top,
	int width, int heigth)
	:m_left(left),
	m_top(top),
	m_width(std::max(0, width)),
	m_height(std::max(0, heigth))
{
}

CRectangle::~CRectangle()
{
}

unsigned CRectangle::GetHeight() const
{
	return m_height;
}

unsigned CRectangle::GetWidth() const
{
	return m_width;
}

int CRectangle::GetLeft() const
{
	return m_left;
}

int CRectangle::GetRight() const
{
	return m_left + m_width;
}

int CRectangle::GetBottom() const
{
	return m_top - m_height;
}

int CRectangle::GetTop() const
{
	return m_top;
}

unsigned CRectangle::GetArea() const
{
	return GetHeight() * GetWidth();
}

unsigned CRectangle::GetPerimeter() const
{
	return 2 * (GetHeight() + GetWidth());
}

void CRectangle::SetHeight(int height)
{
	m_height = std::max(0, height);
}

void CRectangle::SetWidth(int width)
{
	m_width = std::max(0, width);
}

void CRectangle::SetLeft(int left)
{
	if (left > GetRight())
	{
		return;
	}
	m_left = left;
}

void CRectangle::SetTop(int top)
{
	if (top < GetBottom())
	{
		return;
	}
	m_top = top;
}

void CRectangle::SetRight(int right)
{
	if (right < GetLeft())
	{
		return;
	}
	m_width = right - m_left;
}

void CRectangle::SetBottom(int bottom)
{
	if (bottom > GetTop())
	{
		return;
	}
	m_height = m_top - bottom;
}

void CRectangle::Move(int dx, int dy)
{ 
	m_left += dx;
	m_top += dy;
}

void CRectangle::Scale(int sx, int sy)
{
	if (sx < 0 || sy < 0)
	{
		return;
	}
	m_height *= sy;
	m_width *= sx;
}

