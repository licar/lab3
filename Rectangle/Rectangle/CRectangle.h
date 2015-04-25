#pragma once
class CRectangle
{
public:
	CRectangle();
	CRectangle(int left, int top,
		int width, int heigth);
	~CRectangle();

	unsigned GetHeight() const;
	unsigned GetWidth() const;
	int GetLeft() const;
	int GetTop() const;
	int GetRight() const;
	int GetBottom() const;
	unsigned GetArea() const;
	unsigned GetPerimeter() const;

	void SetHeight(int height);
	void SetWidth(int width);
	void SetLeft(int left);
	void SetTop(int top);
	void SetRight(int right);
	void SetBottom(int bottom);
	void Move(int dx, int dy);
	void Scale(int sx, int sy);

private:
	unsigned m_height;
	unsigned m_width;
	int m_left;
	int m_top;
};