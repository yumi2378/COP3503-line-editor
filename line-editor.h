#ifndef LINE_EDITOR_H
#define LINE_EDITOR_H
#include<iostream>
#include<string>
using namespace std;

struct node
{
	string data;
	node *next;
};
class linkedList
{
	private:
	node *head, *tail;
	public:
	linkedList();
	int getSize(node* head);
	void insertEnd(string value);
	void printList();
	void insertAtIndex(int index, string value);
	void deleteAtIndex(int index);
	void replace(int index, string newLine);
	void search(string text);
};

//Variables
linkedList doc;
bool quit=false;
bool hasText;
int lastChar;
string command;
int index;
string text;
#endif
