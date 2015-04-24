#pragma once
class CRectangle
{
public:
	CRectangle(int left = 0, int top = 0,
		int width = 0, int heigth = 0);
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
	int m_right;
	int m_bottom;
};

int DetermBottom(int top, unsigned height);
unsigned DetermHeight(int top, int bottom);
int DetermRight(int left, int width);
int DetermWidth(int left, int right);