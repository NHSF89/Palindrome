/*
Palindrome
The operations utilize Stacks and Queues
to determine whether the input is a palindrome or not.
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


//Stack Class
#ifndef _STACK
#define _STACK

class Stack
{
      private:
      int stack; //Stack Count
      int MAX_BUFFER; //Max Buffer Length
      char* data; //Default Pointer

      public:
      //Default Constructor
      Stack()
      {
           MAX_BUFFER = 10;
           data = new char[MAX_BUFFER];
           stack = 0;
      }
      
      Stack(int i)
      {
                MAX_BUFFER = i;
                data = new char[MAX_BUFFER];
                stack = 0;
      }//End Constructor


      //isEmpty
      bool isEmpty()
      {
           bool is = false;
           if (stack == 0)
           is = true;
           return is;
           
      }//End isEmpty
      
      //Push
      void push(char anItem)
      {
           if (stack < MAX_BUFFER)
           {
              data[stack] = anItem;
              stack++;
           }
           else
           cout << "Stack is FULL; Unable to add Item to stack." << endl;
           
      }//End Push
      
      //Pop
      void pop()
      {
           if (stack > 0)
           {
                data[stack]='-1';
                stack--;
           }
           else
           cout << "Stack is already EMPTY; Unable to remove an item." << endl;

           
      }//End Pop
      
      //Peek
      char peek()
      {
           return data[stack-1];
      }//End Peek
      
      //Deconstructor
      ~Stack()
      {
              delete [] data;
              stack = 0;
      }
      //End Deconstructor
};

#endif
//End Stack Class

// Queue Class
#ifndef _QUEUE
#define _QUEUE

const int MAX_QUEUE = 100;

class Queue
{
	private:
	char entries[MAX_QUEUE];
	int front;
	int back;
	int count;

	public:
	Queue()
	{
	front = 0; 
	back = MAX_QUEUE-1; 
	count = 0;
	}
	bool enqueue(char newEntry)
	{
		if (count +1 > MAX_QUEUE)
		return false;
		else
		{
			back++;
			back = back % MAX_QUEUE;
			entries[back] = newEntry;
			count++;
		}
		return true;
	}
	bool dequeue()
	{
		front++;
		front = front % MAX_QUEUE;
		count--;
	}
	char peek()
	{
		return entries[front];
	}
	bool isEmpty()
	{
		return (count == 0);
	}
};
#endif
//End Queue Class

//Main
int main()
{
    int i = 0;
    string j;

    cout << "Please enter in a string to determine whether it's a palindrome or not: ";
    getline(cin, j, '\n');
    
     i = j.length();
     
     Stack m(i);
     Queue n;
     bool tof = true; 
     
     for (int x = 0; x < i; x++)
     {
         m.push(j[x]);
         n.enqueue(j[x]);
     }
     int x = 0;
    
     while (x < i && tof == true)
     {
        if (toupper(m.peek()) == toupper(n.peek()))
        {
           m.pop();
           n.dequeue();
        }
        else
        tof = false;
        x++;
     }
     
     if (tof == true)
     cout << j << " IS A PALINDROME." << endl;
     else
     cout << j << " IS NOT A PALINDROME." << endl;
     
    
     system("PAUSE");

return 0;
}
//End Main


