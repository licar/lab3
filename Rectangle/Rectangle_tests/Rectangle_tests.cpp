// Rectangle_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Rectangle/CRectangle.h"
#include "../Rectangle/Canvas.h"

BOOST_AUTO_TEST_CASE(Initialization)
{
	CRectangle rectangle(1, 2, 2, 2);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 1);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 2);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 2);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 2);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 4);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 3);
}

BOOST_AUTO_TEST_CASE(RectangleCanNotHaveNegotiveWidthAndHeight)
{
	CRectangle rectangle(1, 2, -14, -12);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 1);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 2);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 0);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 2);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 1);
}

BOOST_AUTO_TEST_CASE(CheckMethodsOfRectangle)
{
	CRectangle rectangle(1, 2, 2, 4);
	rectangle.SetLeft(3);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 3);
	rectangle.SetTop(4);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 4);
	rectangle.SetHeight(11);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 11);
	rectangle.SetWidth(5);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 5);
	rectangle.SetBottom(12);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 12);
	rectangle.SetRight(12);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 12);
}

BOOST_AUTO_TEST_CASE(ValuesHaveInterval)
{
	CRectangle rectangle(1, 2, 2, 4);
	rectangle.SetLeft(4);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 4);
	rectangle.SetTop(-3);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), -3);
	rectangle.SetBottom(4);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 4);
	rectangle.SetRight(14);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 14);
}

BOOST_AUTO_TEST_CASE(CanGiveAreaAndPerimeter)
{
	CRectangle rectangle(1, 1, 2, 2);
	BOOST_CHECK_EQUAL(rectangle.GetArea(), 4);
	BOOST_CHECK_EQUAL(rectangle.GetPerimeter(), 8);
}

BOOST_AUTO_TEST_CASE(CanMove)
{
	CRectangle rectangle(1, 1, 2, 2);
	rectangle.Move(1, 1);
	BOOST_CHECK_EQUAL(rectangle.GetLeft(), 2);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 4);
	BOOST_CHECK_EQUAL(rectangle.GetTop(), 2);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 4);
}

BOOST_AUTO_TEST_CASE(CanScale)
{
	CRectangle rectangle(1, 1, 2, 2);
	rectangle.Scale(2, 2);
	BOOST_CHECK_EQUAL(rectangle.GetRight(), 5);
	BOOST_CHECK_EQUAL(rectangle.GetBottom(), 5);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 4);
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 4);
}

BOOST_AUTO_TEST_CASE(CanCheckIntersect)
{
	CRectangle rectangle1(0, 10, 20, 20);
	CRectangle rectangle2(0, 10, 20, 20);
	CRectangle rectangle3(0, 8, 20, 20);
	CRectangle rectangle4(100, 100, 20, 20);
	BOOST_CHECK(rectangle1.Intersect(rectangle2));
	BOOST_CHECK(rectangle1.Intersect(rectangle3));
	BOOST_CHECK(!rectangle1.Intersect(rectangle4));
}

BOOST_AUTO_TEST_CASE(CanBeCreateCanvas)
{
	CCanvas canvas(10, 8);
	BOOST_CHECK_EQUAL(canvas.GetWidht(), 10);
	BOOST_CHECK_EQUAL(canvas.GetHeight(), 8);
}

BOOST_AUTO_TEST_CASE(CanBeClear)
{
	CCanvas canvas(10, 8);
	canvas.Clear('a');
	BOOST_CHECK_EQUAL(canvas.GetPixel(0, 0), 'a');
	canvas.Clear('a');
	BOOST_CHECK_EQUAL(canvas.GetPixel(0, 0), 'a');
}

