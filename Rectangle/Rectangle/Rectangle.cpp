// Rectangle.cpp: определяет точку входа для консольного приложения.
//
#pragma once
#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "CRectangle.h"
#include "Canvas.h"

using namespace std;

void CallCommands(ifstream &fileInput,
	string const &cmd, CRectangle &rectangle)
{
	if (cmd == "Rectangle")
	{
		int left, top, widht, height;
		fileInput >> left >> top 
			>> widht >> height;

		rectangle.SetLeft(left);
		rectangle.SetTop(top);
		rectangle.SetHeight(height);
		rectangle.SetWidth(widht);
		return;
	}
	if (cmd == "Move")
	{
		int dx, dy;
		fileInput >> dx >> dy;
		rectangle.Move(dx, dy);
		return;
	}
	if  (cmd == "Scale")
	{
		int sx, sy;
		fileInput >> sx >> sy;
		rectangle.Scale(sx, sy);
		return;
	}
}

bool ReadFromFileCommands(
	string const &fileName,
	CRectangle &rectangle)
{
	ifstream fileInput(fileName);
	
	if (!fileInput)
	{
		return false;
	}

	string cmd;

	while (!fileInput.eof())
	{
		fileInput >> cmd;
		CallCommands(fileInput, cmd, rectangle);
		cmd.clear();
	}
	fileInput.close();
	return true;
}

void WriteDataOfRectangles(CRectangle &rectangle,
	ofstream &fileOutput, int index)
{
	fileOutput << "Rectangle : " << index << ' ' << endl
		<< '\t' << "Left top  : "
		<< '(' << rectangle.GetLeft() << ';' << rectangle.GetTop() << ')' << endl
		<< '\t' << "Size : " << rectangle.GetHeight() * rectangle.GetWidth() << endl
		<< '\t' << "Right bottom  : "
		<< '(' << rectangle.GetRight() << ';' << rectangle.GetBottom() << ')' << endl
		<< '\t' << "Area : " << rectangle.GetArea() << endl
		<< '\t' << "Perimetr : " << rectangle.GetPerimeter() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CRectangle rectangle1;
	CRectangle rectangle2;

	if (!ReadFromFileCommands("input1.txt", rectangle1))
	{
		cout << "first file didn't open";
		return 1;
	}

	if (!ReadFromFileCommands(argv[1], rectangle2))
	{
		cout << "second file didn't open";
		return 1;
	}

	ofstream fileOutput("output.txt");
	if (!fileOutput)
	{
		cout << "output file didn't open";
		return 1;
	}
	
	CCanvas canvas(60, 20);
	FillRectangle(rectangle1, '+', canvas);
	FillRectangle(rectangle2, '-', canvas);

	if (rectangle1.Intersect(rectangle2))
	{
		FillRectangle(rectangle1, '#', canvas);
	}

	if (argv[3])
	{
		ofstream fileCanvas(argv[3]);
		canvas.Write(fileCanvas);
	}
	else
	{
		canvas.Write(cout);
	}

	WriteDataOfRectangles(rectangle1, fileOutput, 1);
	WriteDataOfRectangles(rectangle2, fileOutput, 2);
	return 0;
}

