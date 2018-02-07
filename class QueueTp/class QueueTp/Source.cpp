#include<iostream>
#include<cstring>
#include"QueueTp.h"
const int SIZE = 5;
int main()
{
	using namespace std;
	QueueTp<Worker*> locals(SIZE);
	Worker * g=nullptr;
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n" << "w: waiter s: singer t: singingwaiter p: process q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == nullptr)
		{
			cout << "Please enter w, s, t, p, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':
			{
					if (locals.isfull())
						break;
				delete g;
				g= new Waiter();
				cin.get();
				g->Set();
				locals.add(g); 
				break;
			}
			
		case 's':
			{
						if (locals.isfull())
								break;
				g = new Singer();
				cin.get();
				g->Set();
				locals.add(g);
				break;
		}
		case't':
		{
				   if (locals.isfull())
						break;
			g = new SingingWaiter();
			cin.get();
			g->Set();

			break;
		}
		}
	}
	cout << "There is " << locals.howmany() << "items in queue\n";
	locals.del();
	cout << "Now there is " << locals.howmany() << endl;
	while (locals.isfull())
		locals.del();
	cout << "Now no items in queue:	" << locals.howmany() << endl;
	cout << "Bye!\n";
	return 0;
}