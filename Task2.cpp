#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;


void Task2() {
	cout << "Enter figure name\n";
	string str;
	cin >> str;
	
	if (str == "circle") {
		Round figure;
		figure.set();
		cout << "Color is " << figure.getColor() << "\nSquare is " << figure.square() << endl;
		Vector2f *tmp = figure.describe();
		cout << "Describe rectangle: " << tmp[0].get() << tmp[1].get() << tmp[2].get() << tmp[3].get() << endl;
	}
	else if (str == "triangle") {
		Triangle figure;
		figure.set();
		cout << "Color is " << figure.getColor() << "\nSquare is " << figure.square() << endl;
		Vector2f* tmp = figure.describe();
		cout << "Describe rectangle: " << tmp[0].get() << tmp[1].get() << tmp[2].get() << tmp[3].get() << endl;
	}
	else if (str == "rectangle") {
		Rectangle figure;
		figure.set();
		cout << "Color is " << figure.getColor() << "\nSquare is " << figure.square() << endl;
		Vector2f* tmp = figure.describe();
		cout << "Describe rectangle: " << tmp[0].get() << tmp[1].get() << tmp[2].get() << tmp[3].get() << endl;
	}
	else if (str == "square") {
		Square figure;
		figure.set();
		cout << "Color is " << figure.getColor() << "\nSquare is " << figure.square() << endl;
		Vector2f* tmp = figure.describe();
		cout << "Describe rectangle: " << tmp[0].get() << tmp[1].get() << tmp[2].get() << tmp[3].get() << endl;
	}


}
