#pragma once
#include <string>
#include <math.h>
#include <iostream>
#include "Structs.h"
using namespace std;
enum Color {
	red,
	blue,
	green,
	yellow,
	none
};


class Geometry
{
public:
	Color color = none;
	Vector2f center;
	Geometry() {
		color = none;
		center = {0,0};
	}
	void setCenter() {
		cout << "Enter x and y for center\n";
		cin >> center.x >> center.y;
	}
	void setCenter(double x, double y) {
		center.x = x;
		center.y = y;
	}
	string getColor() {
		switch (color)
		{
		case red:
			return "Red";
		case blue:
			return "Blue";
		case green:
			return "Green";
		case yellow:
			return "Yellow";
		case none:
			return "None";
		}
	}
	
};

class Round :public Geometry {
	double radius = 0;
public:
	Round() {
		color = red;
	}
	double square() {
		return atan(1) * 4 * radius;
	}
	/*
	странное немного условие, по сути условие говорит тчо главное что бы описывающий прямоугольник не был меньше,
	то есть он может сопрекасаться, и например с квадратом и прямоугольником можно просто возвращать их же координаты
	*/
	Vector2f* describe() {
		Vector2f ret[4] =
		{
			Vector2f{center.x - radius,center.y + radius},
			Vector2f{center.x + radius,center.y + radius},
			Vector2f{center.x + radius,center.y - radius},
			Vector2f{center.x - radius,center.y - radius}
		};
		return ret;
	}
	void set() {
		setCenter();
		cout << "Enter round radius\n";
		cin >> radius;
	}
	void set(double n) {
		radius = n;
	}
};

class Rectangle : public Geometry {
	double height = 0;
	double width = 0;
public:
	Rectangle() {
		color = yellow;
	}
	double square() {
		return height * width;
	}
	Vector2f* describe() {
		Vector2f ret[4] =
		{
			Vector2f{center.x - (width/2),center.y + (height/2)},
			Vector2f{center.x + (width / 2),center.y + (height / 2)},
			Vector2f{center.x + (width / 2),center.y - (height / 2)},
			Vector2f{center.x - (width / 2),center.y - (height / 2)}
		};
		return ret;
	}
	void set() {
		setCenter();
		cout << "Enter rectangle height and width\n";
		cin >> height >> width;
	}
	void set(double h , double w) {
		height = h;
		width = w;
	}
};

class Triangle : public Geometry {
	double side = 0;
public:
	Triangle() {
		color = blue;
	}
	double square() {
		return (side * side) * sqrt(3) / 4;
	}
	Vector2f* describe() {
		double height = sqrt((side * side) - ((side * side) / 4));
		Vector2f ret[4] =
		{
			Vector2f{center.x - (side / 2),center.y + (height / 2)},
			Vector2f{center.x + (side / 2),center.y + (height / 2)},
			Vector2f{center.x + (side / 2),center.y - (height / 2)},
			Vector2f{center.x - (side / 2),center.y - (height / 2)}
		};
		return ret;
	}
	void set() {
		setCenter();
		cout << "Enter triangle side\n";
		cin >> side;
	}
	void set(double n) {
		side = n;
	}
};

class Square : public Geometry {
	double side = 0;
public:
	Square() {
		color = green;
	}
	double square() {
		return side * side;
	}
	Vector2f* describe() {
		Vector2f ret[4] =
		{
			Vector2f{center.x - (side / 2),center.y + (side / 2)},
			Vector2f{center.x + (side / 2),center.y + (side / 2)},
			Vector2f{center.x + (side / 2),center.y - (side / 2)},
			Vector2f{center.x - (side / 2),center.y - (side / 2)}
		};
		return ret;
	}
	void set() {
		setCenter();
		cout << "Enter square side\n"; 
		cin >> side;
	}
	void set(double n) {
		side = n;
	}


};