#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <time.h>
#include <string>
#include <iostream>
#include <Windows.h>
#include "ClickButton.h"
#include "ToDoListBox.h"
using namespace sf;
using namespace std;





string itos(int c) {
	string st;
	st = std::to_string(c);
	return st;
}

string convertSeconds(int s)
{
	string stu;
	int sec;
	int min;
	min = s / 60;
	sec = s % 60;
	string a, b;
	a = itos(min);
	b = itos(sec);
	if (sec < 10) { b = "0" + b; }
	if (min < 10) { a = "0" + a; }
	stu = a + ":" + b;

	return stu;
}
void makeWindowOnTop(sf::RenderWindow& window)
{
	HWND hwnd = window.getSystemHandle();
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
}
int main()
{
	//int width = 800;
	//int height = 500;

	//FreeConsole();
	/////////////////////////////////////////////////////////////       SIZES OF WINDOW
	int width = VideoMode::getDesktopMode().width / 3;
	int height = VideoMode::getDesktopMode().height / 3;
	int widthS = VideoMode::getDesktopMode().width / 8;// cout << widthS << "\n";
	int heightS = VideoMode::getDesktopMode().height / 18;// cout << heightS;
	int currentW = widthS;
	int currentH = heightS;
	/////////////////////////////////////////////////////////////       Positions OF WINDOW
	int posxL = VideoMode::getDesktopMode().width / 2 - width / 2;
	int posyL = VideoMode::getDesktopMode().height / 2 - height / 2;
	int posxS = VideoMode::getDesktopMode().width - widthS;
	int posyS = VideoMode::getDesktopMode().height - heightS;
	int currentPX = posxS / 2;// cout << currentPX;
	int currentPY = posyS / 2;
	bool windowSmall = false;
	bool clickActive = true;

	int seconds = 1501;
	sf::RenderWindow window(sf::VideoMode(width, height), "", sf::Style::None);
	makeWindowOnTop(window);
	window.setKeyRepeatEnabled(false);
	sf::RectangleShape background(Vector2f(800 - 2, 800 - 2));
	background.setPosition(1, 1);
	background.setFillColor(Color(42, 62, 80));
	background.setOutlineColor(Color(34, 49, 63));
	background.setOutlineThickness(1);

	sf::Font font;
	if (!font.loadFromFile("roboto.ttf"))
	{
		// error...
	}
	////////////// BUTTONS
	ClickButton settings;
	ClickButton addtask;
	settings.setSize(200, 200);
	settings.setPosition(Vector2f(0, 0));
	settings.setLabel("Settings", font, 22);
	addtask.setColor("sunflower");
	addtask.setSize(200, 200);
	addtask.setPosition(Vector2f(200, 0));
	addtask.setLabel("Add Task", font, 22);
	//////////////////////



	Vector2f mousePositionFloat;
	sf::Text text;
	text.setCharacterSize(26);
	text.setPosition(Vector2f(0 + 800 / 2, 0 + 800 / 2 - 5));
	text.setFont(font);
	text.setString("Pomodoro");
	text.setColor(Color::White);
	cout << text.getPosition().x;
	Clock clock;
	SoundBuffer buffer;

	if (!buffer.loadFromFile("d.wav")) {
		//error
	}
	Sound sound;
	sound.setBuffer(buffer);

	string wf;


	string CurrentTask = "Work   ";

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		/*
		int timer = clock.getElapsedTime().asSeconds();
		if (timer > 0) {
			seconds--;
			wf = convertSeconds(seconds);
			text.setString(CurrentTask + wf);

			clock.restart();
		}
		if (seconds == 0) { sound.play(); seconds = 301; CurrentTask = "Pause   "; }

		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		*/
		window.clear();

		window.draw(background);
		settings.setColor("pomegranate");
		mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		if (clickActive) {
			if (settings.cBox.contains(mousePositionFloat)) {

				settings.setColor("alizarin");
				if (Mouse::isButtonPressed(Mouse::Left)) {
					
					window.setPosition(Vector2i(posxS, posyS));
					window.setSize(Vector2u(widthS, heightS));
					windowSmall = true;
					clickActive = false;
					Sleep(1);
					clickActive = true;
				}
				if (clickActive) {
					if (windowSmall) {
						if (Mouse::isButtonPressed(Mouse::Left)) {
							window.setPosition(Vector2i(posxL, posyL));
							window.setSize(Vector2u(width, height));
							windowSmall = false;

						}
					}
				}
			}
		}
		settings.show(window);
		addtask.show(window);
		window.draw(text);
		window.display();
	}

	return 0;
}