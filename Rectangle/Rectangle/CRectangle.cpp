#include "stdafx.h"
#include "CRectangle.h"


CRectangle::CRectangle(int left, int top,
	int width, int heigth)
	:m_left(left), m_top(top),
	m_width(width), m_height(heigth)
{
	if (width < 0)
	{
		m_width = 0;
	}
	if (heigth < 0)
	{
		m_height = 0;
	}

	m_right = m_left + m_width;
	m_bottom = m_top - m_height;
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
	return m_right;
}

int CRectangle::GetBottom() const
{
	return m_bottom;
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
	if (height < 0)
	{
		m_height = 0;
	}
	else
	{
		m_height = height;
	}
	m_bottom = DetermBottom(GetTop(), GetHeight());
}

void CRectangle::SetWidth(int width)
{
	if (width < 0)
	{
		m_width = 0;
	}
	else
	{
		m_width = width;
	}
	m_right = DetermRight(GetLeft(), GetWidth());
}

void CRectangle::SetLeft(int left)
{
	if (left > GetRight())
	{
		return;
	}
	m_left = left;
	m_width = DetermWidth(GetLeft(), GetRight());
}

void CRectangle::SetTop(int top)
{
	if (top < GetBottom())
	{
		return;
	}
	m_top = top;
	m_height = DetermHeight(GetTop(), GetBottom());
}

void CRectangle::SetRight(int right)
{
	if (right < GetLeft())
	{
		return;
	}
	m_right = right;
	m_width = DetermWidth(GetLeft(), GetRight());
}

void CRectangle::SetBottom(int bottom)
{
	if (bottom > GetTop())
	{
		return;
	}
	m_bottom = bottom;
	m_height = DetermHeight(GetTop(), GetBottom());
}

void CRectangle::Move(int dx, int dy)
{ 
	m_left += dx;
	m_right += dx;
	m_bottom += dy;
	m_top += dy;
}

void CRectangle::Scale(int sx, int sy)
{
	if (sx < 0 || sy < 0)
	{
		return;
	}
	m_right += (m_right - m_left) * (sx - 1);
	m_bottom -= (m_top - m_bottom) * (sy - 1);
	m_height = GetTop() - GetBottom();
	m_width = GetRight() - GetLeft();
}

int DetermBottom(int top, unsigned height)
{
	return top - height;
}

unsigned DetermHeight(int top, int bottom)
{
	return top - bottom;
}

int DetermRight(int left, int width)
{
	return left + width;
}

int DetermWidth(int left, int right)
{
	return right - left;
}
