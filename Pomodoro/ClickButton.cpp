#include "ClickButton.h"



ClickButton::ClickButton()
{
}


ClickButton::~ClickButton()
{
}

void ClickButton::setPosition(Vector2f pos) {
	cbutton.setPosition(pos); sf::FloatRect buttonBox(cbutton.getPosition().x, cbutton.getPosition().y, cbutton.getSize().x, cbutton.getSize().y);
	cBox = buttonBox;
}
void ClickButton::setLabel(string s, Font f, int siz) {
	label = s;
	bfont = f;
	buttonLabel.setCharacterSize(siz);
	buttonLabel.setFont(bfont);
	buttonLabel.setString(s);
	buttonLabel.setPosition(this->cbutton.getPosition().x + cbutton.getSize().x / 2, this->cbutton.getPosition().y + cbutton.getSize().y / 2);
	buttonLabel.setOrigin(buttonLabel.getLocalBounds().width / 2, buttonLabel.getLocalBounds().height / 2);

}
void ClickButton::setOrigin() {
	cbutton.setOrigin(cbutton.getSize().x / 2, cbutton.getSize().y / 2);

}
void ClickButton::setSize(float w, float h) {
	cbutton.setSize(Vector2f(w, h));
}

void ClickButton::show(RenderWindow &target_) {
	target_.draw(cbutton);
	target_.draw(buttonLabel);
}
void ClickButton::setColor(string color) {
	if (color == "sunflower") { cbutton.setFillColor(Color(241, 196, 15)); }
	else if (color == "alizarin") { cbutton.setFillColor(Color(231, 76, 60)); }
	else if (color == "wisteria") { cbutton.setFillColor(Color(142, 68, 173)); }
	else if (color == "peterriver") { cbutton.setFillColor(Color(52, 152, 219)); }
	else if (color == "pomegranate") { cbutton.setFillColor(Color(192, 57, 43)); }
	else if (color == "nephritis") { cbutton.setFillColor(Color(39, 174, 96)); }
}