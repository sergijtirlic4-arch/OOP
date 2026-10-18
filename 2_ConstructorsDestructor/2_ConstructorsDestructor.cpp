#include <iostream>
#include <Windows.h>
using namespace std;

void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct Coord
{
	int x, y;
};

class Rectangles
{
	int width, height;
	char symbol;
	Coord coord;
public:
	Rectangles();
	Rectangles(int size);
	Rectangles(int width, int height);
	~ Rectangles();

	void ChangeSize(int Height, int Width);
	void Move(int X, int Y);
	void ShowRectangle() ;
};

 Rectangles:: Rectangles()
{
	 width = 5;
	 height = 4;
	 symbol = '#';
	 coord.x = 0;
	 coord.y = 0;
}

 Rectangles:: Rectangles(int size)
{
	 if (size > 0) {
		 width = size;
		 height = size;
	 }
	 else {
		 cout << "Error size";
		 width = 1;
		 height = 1;
	 }
	 symbol = '#';
	 coord.x = 0;
	 coord.y = 0;
}

 Rectangles:: Rectangles(int width, int height)
{
	 if (width > 0 && height > 0) {
		 this->width = width;
		 this->height = height;
	 }
	 else {
		 cout << "Error width or height";
		 this->width = 1;
		 this->height = 1;
	 }
	 symbol = '#';
	 coord.x = 0;
	 coord.y = 0;
}

 Rectangles::~ Rectangles()
{
}

 void Rectangles:: ChangeSize(int Height, int Width)
 {
	 if (this->height + Height > 0 && this->width + Width > 0) {
		 this->height += Height;
		 this->width += Width;
	 }
	 else {
		 cout << "Error" << endl;
	 }
 }

 void Rectangles:: Move(int X, int Y)
 {
	 if (coord.x + X >= 0 && coord.y + Y >= 0) {
		 coord.x += X;
		 coord.y += Y;
	 }
	 else {
		 cout << "Error" << endl;
	 }
 }

 void Rectangles:: ShowRectangle()
 {
	 for (int i = 0; i < height; ++i) {
		 SetPos(coord.x, coord.y + i);
		 for (int j = 0; j < width; ++j) {
			 cout << symbol;
		 }
	 }
	 cout << endl;
 }

int main()
{
	Rectangles rect(5, 4);

	rect.ShowRectangle();

	system("pause");
	system("cls");

	rect.Move(1, 10);
	rect.ShowRectangle();

	system("pause");
	system("cls");

	rect.ChangeSize(9, -3);
	rect.ShowRectangle();

	rect.ChangeSize(10, -20);
}
