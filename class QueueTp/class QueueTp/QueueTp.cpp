#include"QueueTp.h"
#include<iostream>
using namespace std;
Worker::~Worker(){};
void Worker::Data()const
{
	cout << "Name: " << fullname << endl << "Employee ID: " << id << endl;
}
void Worker::Get()
{
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}
ostream& operator<<(ostream & os, const Worker & w)
{
	os << "Name: " << w.fullname << endl << "Employee ID: " << w.id << endl;
	return os;
}
void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}
void Waiter::Show()const
{
	cout << "Catagory : waiter\n";
	Worker::Data();
	Data();
}
void Waiter::Data() const
{
	cout << "Panache raiting: " << panache << endl;
}
void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

ostream& operator<<(ostream& os, const Waiter & wt)
{
	wt.Show();
	return os;
}

char * Singer::pv[Singer::Vtypes] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };
void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show()const
{
	cout << "Category:singer\n";
	Worker::Data();
	Data();
}
void Singer::Data()const
{
	cout << "Vocal range: " << pv[voice] << endl;
}
void Singer::Get()
{
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}
ostream& operator<<(ostream& os, const Singer& s)
{
	s.Show();
	return os;
}
void SingingWaiter::Data()const
{
	Singer::Data();
	Waiter::Data();
}
void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}
void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}
void SingingWaiter::Show()const
{
	cout << "Category: singing waiter\n";
	Worker::Data();
	Data();
}
ostream& operator<<(ostream& os, const SingingWaiter& sw)
{
	sw.Show();
	return os;
}