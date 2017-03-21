#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class ClickButton
{
public:
	RectangleShape cbutton;
	Text buttonLabel;
	FloatRect cBox;
	ClickButton();
	~ClickButton();


	void setOrigin();
	void setPosition(Vector2f);
	void setLabel(string,Font, int);
	void setSize(float, float);
	void show(RenderWindow &);
	void setColor(string);
protected:
	Vector2f pos;
	string label;
	Font bfont;
	
};

