// 24_Ä¿¸Çµå
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
	virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Rect : public Shape
{
public:
	void Draw() { cout << "Rect Draw" << endl; }
};


class Circle : public Shape
{
public:
	void Draw() { cout << "Circle Draw" << endl; }
};

int main()
{
	vector<Shape*> shapes;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1) shapes.push_back(new Rect);
		else if (cmd == 2) shapes.push_back(new Circle);
		else if (cmd == 9) {
			for (int i = 0; i < shapes.size(); i++)
				shapes[i]->Draw();
		}
	}

}