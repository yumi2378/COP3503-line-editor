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
	linkedList()
	{
		head = NULL;
		tail = NULL;
	}
	int getSize(node* head) //Recursive function returns the length of the list
	{
		if(head==NULL)
		{
			return 0;
		}
		
		return 1 + getSize(head->next);
	}	
	void insertEnd(string value) //Insert data at end of list
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
	void printList() //Display the list
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
	void insertAtIndex(int index, string value) //Insert value at index
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
	void deleteAtIndex(int index) //Delete a node at a specified index
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
	void replace(int index, string newLine)
	{
		deleteAtIndex(index);
		insertAtIndex(index, newLine);
	}
	void search(string text)
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
};
#endif
