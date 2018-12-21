#include<iostream>

#include<cstdio>

#include<cstdio>

#include"Point.h"

#include"Figure.h"

#include"Rectangle.h"

#include"Square.h"

#include"Ellips.h"

#include"Circle.h"

using namespace std;

int main()
{

	Figure* array[4];
	array[0] = new Rectangle(Point(17, 14), 15, 20);
	array[1] = new Square(Point(5, 7), 25);
	array[2] = new Ellips(*(Rectangle*)array[0]);
	array[3] = new Circle(Point(12, 17), 18);


	//for (int i = 0; i < 4; i++)
	//{
	//	array[i]->Save();
	//	cout << endl;
	//}
	
	Figure* array1[4];
	array1[0] = new Rectangle;
	array1[1] = new Square;
	array1[2] = new Ellips;
	array1[3] = new Circle;
	for (int i = 0; i < 4; i++)
	{
		array1[i]->Load();
		array1[i]->Print();
		cout << endl;
	}

}