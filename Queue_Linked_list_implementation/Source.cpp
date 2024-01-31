#include<iostream>
#include<conio.h>
using namespace std;


class node
{
	int data;
	node* next;
public:
	void set_data(int d)
	{
		data = d;

	}
	int get_data()
	{
		return data;
	}
	void set_nextnode(node* gh)
	{
		next = gh;
	}
	node* get_nextnode()
	{
		return next;
	}
};

class Queue
{
private:
	int noe;
	node* front;
	node* rear;
public:
	Queue()
	{
		noe = 0;
		front = rear = NULL;
	}

	void Enqueue(int v)
	{
		node* newnode = new node();
		newnode->set_nextnode(NULL);
		newnode->set_data(v);

		if (rear == NULL)
		{
			rear = newnode;
			front = newnode;
		}
		else
		{
			rear->set_nextnode(newnode);
			rear = newnode;
		}
		noe++;
	}
	int Dequeue()
	{
		if (rear == NULL)
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			int temp = front->get_data();
			node* p = front;
			if (rear == p)
			{

				rear = NULL;
				front = NULL;
			}
			else
			{
				front = front->get_nextnode();
				delete p;
			     
			}
			noe--;
			return temp;
		}
	}
};

int main()
{
	Queue* obj = new Queue();
	obj->Enqueue(4);
	obj->Enqueue(3);
	obj->Enqueue(6);
	obj->Enqueue(1);

	cout << obj->Dequeue() << endl;
	cout << obj->Dequeue() << endl;

	return 0;
}