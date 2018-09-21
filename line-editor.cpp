#include "line-editor.h"

//Variables
linkedList doc;
bool quit=false;
bool hasText;
int lastChar;
string command;
int index;
string text;

int main()
{
	while(!quit)
	{
		hasText=false;
		
		cin>>command;
		if(command=="insert" || command=="delete" || command=="edit")
		{
			cin>>index;
		}
		getline(cin, text); //Read in the text
		lastChar = text.size()-1;
		
		if(text[1]=='"' && text[lastChar]=='"')
		{
			hasText=true;
		}
		if(hasText)
		{
			text=text.substr(2,lastChar-2);
		}
		//Perform actions based on input
		if(command=="insertEnd" && hasText)
		{
			doc.insertEnd(text);
		}
		else if(command=="print")
		{
			doc.printList();
		}
		else if(command=="insert" && hasText)
		{
			doc.insertAtIndex(index, text);
		}
		else if(command=="delete")
		{
			doc.deleteAtIndex(index);
		}
		else if(command=="edit" && hasText)
		{
			doc.replace(index, text);
		}
		else if(command=="search")
		{
			doc.search(text);
		}
		else if(command=="quit")
		{
			quit=true;
		}
	}	
	return 0;
}
