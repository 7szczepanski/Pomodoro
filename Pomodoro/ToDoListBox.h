#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;


class ToDoListBox
{
public:
	ToDoListBox();
	~ToDoListBox();
	RectangleShape bg; //background of this "widget"
	RectangleShape txtr; //Storage for text
	RectangleShape addbtn;
	RectangleShape delbtn;
	FloatRect bgBox;   //we need this to deal with events
	FloatRect txtrBox;
	FloatRect addbtnBox;
	FloatRect delbtnBox;
	// ok we want to set position of BG then set positions of other buttons and stuff acording to that rectangle, thats why i will write everything 
	// in one function setPositon(parameters) and if access to other shapes will be needed, we can do it quite easly;
	// In background I need place where all tasks will be shown, then add buttons "Add" and "Delete" to manage the tasks
	// Propably I'll need to create one more rectangle with some alpha to simulate "popup" window;
	// Maybe change of color when user wants to set current task, and then app will ask if it's finished or no? If yes, the task will be removed from 
	// Txtr and added to donetasks.txt

};

