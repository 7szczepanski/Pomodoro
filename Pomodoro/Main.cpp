#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <time.h>
#include <string>
#include <iostream>
#include <Windows.h>
using namespace sf;
using namespace std;



int width = 220;
int height = 60;

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
	FreeConsole();

	int seconds = 1501;
	sf::RenderWindow window(sf::VideoMode(width, height), "", sf::Style::None);
	makeWindowOnTop(window);
	window.setPosition(Vector2i(1920 - width, 1080 - height));
	sf::RectangleShape background(Vector2f(width - 2, height - 2));
	background.setPosition(1, 1);
	background.setFillColor(Color(51, 51, 51));
	background.setOutlineColor(Color(124, 7, 25));
	background.setOutlineThickness(1);

	sf::Font font;

	if (!font.loadFromFile("roboto.ttf"))
	{
		// error...
	}

	sf::Text text;
	text.setCharacterSize(38);
	text.setPosition(Vector2f(width / 2, height / 2-10));
	text.setFont(font);
	text.setString("Pomodoro");
	text.setColor((Color::White));


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

		int timer = clock.getElapsedTime().asSeconds();
		if (timer > 0) {
			seconds--;
			wf = convertSeconds(seconds);
			text.setString(CurrentTask + wf);

			clock.restart();
		}
		if (seconds == 0) { sound.play(); seconds = 301; CurrentTask = "Pause   "; }

		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		//cout << text.getLocalBounds().width << "    " << text.getLocalBounds().height << endl;
		window.clear();

		window.draw(background);

		window.draw(text);
		window.display();
	}

	return 0;
}