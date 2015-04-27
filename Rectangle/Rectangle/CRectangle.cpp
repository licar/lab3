#include "stdafx.h"
#include "CRectangle.h"
#include <algorithm>

CRectangle::CRectangle()
	:m_left(0), 
	m_top(0),
	m_height(0), 
	m_width(0)
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
	m_left = left;
}

void CRectangle::SetTop(int top)
{
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

bool CRectangle::Intersect(CRectangle const &other)
{
	int maxY = std::min(GetTop(), other.GetTop());
	int minY = std::max(GetBottom(), other.GetBottom());
	int maxX = std::min(GetRight(), other.GetRight());
	int minX = std::max(GetLeft(), other.GetLeft());

	if (maxX >= GetLeft() && maxX <= GetRight() &&
		minX >= GetLeft() && minX <= GetRight() &&
		maxY >= GetBottom() && maxY <= GetTop() &&
		minY >= GetBottom() && minY <= GetTop())
	{
		m_left = minX;
		m_top = maxY;
		m_height = maxY - minY;
		m_width = maxX - minX;
		return true;
	}
	m_height = 0;
	m_width = 0;
	return false;
}