#include "line-editor.h"

linkedList::linkedList()
{
	head = NULL;
	tail = NULL;
}
int linkedList::getSize(node* head) //Recursive function returns the length of the list
{
	if(head==NULL)
	{
		return 0;
	}
	
	return 1 + getSize(head->next);
}	
void linkedList::insertEnd(string value) //Insert data at end of list
{
	node *temp=new node;
	temp->data=value;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
		temp=NULL;
	}
	else
	{	
		tail->next=temp;
		tail=temp;
	}
}
void linkedList::printList() //Display the list
{
	node *temp=new node;
	temp=head;
	int i=1;
	while(temp!=NULL)
	{
		cout<< i <<" "<<temp->data<<"\n";
		temp=temp->next;
		i++;
	}
}
void linkedList::insertAtIndex(int index, string value) //Insert value at index
{
	node *previous=new node;
	node *current=new node;
	node *temp=new node;
	current=head;
	int listSize=getSize(head);
	
	if(index <= listSize+1) //Only insert if the requested index exists or will add to the end
	{
		if(index==1 && listSize==0) 
		{	
			insertEnd(value); //If this is the first entry, use insertEnd to insert data
		}
		else if(index==1 && listSize!=0)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=head;
			head=temp;
		}
		else
		{
			for(int i=1;i<index;i++)
			{
				if(i<index)
				{
					previous=current;
					current=current->next;
				}
			}
			temp->data=value;
			previous->next=temp;	
			temp->next=current;
		}
	}
}
void linkedList::deleteAtIndex(int index) //Delete a node at a specified index
{			
	node *current=new node;
	node *previous=new node;
	current=head;
	int listSize=getSize(head);
	if(index<=listSize) //Specified index to delete must exist
	{
		if(index==1)
		{
			node *temp=new node;
			temp=head;
			head=head->next;
			delete temp;
		}
		else
		{
			for(int i=1;i<index;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
	}
}
void linkedList::replace(int index, string newLine)
{
	deleteAtIndex(index);
	insertAtIndex(index, newLine);
}
void linkedList::search(string text)
{
	node *current=new node;
	current=head;
	string currentData;
	bool found = false;
	int i=1;
	while(current!=NULL)
	{
		currentData=current->data;
		if(currentData.find(text) != string::npos)
		{
			found=true;
			cout << i <<" "<< current->data <<"\n";
			current=current->next;
			i++;
		}
		else
		{
			current=current->next;
			i++;
		}
	}
	if (!found)
	{
		cout<<"not found\n";
	}
}	
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
