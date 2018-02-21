#ifndef QueueTp_H_
#define QueueTp_H_
#include<iostream>
#include<string>
//new comment 
template <typename T>
class QueueTp
{
	struct thing
	{
		T done;
		thing * next;
	
	};

	thing* first;
	thing* last;
	int count;
	int MAX ;
public:
	QueueTp();
	QueueTp(int q);
	~QueueTp();
	bool add(const T & t);
	bool del();
	bool isempty()const { return count <= 0; }
	bool isfull()const { return count == MAX; }
	void Show()const;
	int howmany()const{ return count; }


};

template<typename T>
void QueueTp<T>::Show()const
{
	if (isempty())
		std::cout << "Queue is empty!\n";
	else
	{
		thing *g = first;
		while (g != nullptr)
		{
			std::cout <<g->done << "\n";
			g = g->next;
		}
	}

}
template<typename T>
QueueTp<T>::QueueTp()
{
	MAX = 10;
	count = 0;
	first = nullptr;
	last = nullptr;
}
template<typename T>
QueueTp<T>::QueueTp(int q)
{
	MAX = q;
	count = 0;
	first = last = nullptr;
}

template<typename T>
QueueTp<T>::~QueueTp()
{
	thing * n;
	while (first != nullptr)
	{
		n = first;
		first = first->next;
		delete n;
	}
}
template<typename T>
bool QueueTp<T>::add(const T & t)
{
	if (isfull())
	{
		std::cout << "The Queue is already full! Can not add anything!" << std::endl;
		return false;
	}

	thing * n = new thing;
	n->done = t;
	n->next = nullptr;
	count++;
	if (first == nullptr)
		first = n;
	else
		last->next = n;
	last = n;
	return true;
}
template<typename T>
bool QueueTp<T>::del()
{
	if (isempty())
	{
		std::cout << "The Queue is already epmty" << std::endl;
		return false;
	}
	count--;
	thing * n = first;
	first = first->next;
	delete n;
	if (count == 0)
		last = nullptr;
	return true;
}

class Worker
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data()const;
	virtual void Get();
public:
	Worker() :fullname("no name"), id(0L){};
	Worker(const std::string & s, long n) : fullname(s), id(n){};
	virtual ~Worker()=0;
	virtual void Set()=0;
	virtual void Show() const = 0;
	friend std::ostream& operator<<(std::ostream & os, const Worker & w);

};

class Waiter:virtual public Worker
{
private:
	int panache;
protected:
	void Data()const;
	void Get();
public:
	Waiter() :Worker(), panache(0){};
	Waiter(const std::string & s, long n, int p = 0) :Worker(s, n), panache(p){};
	Waiter(const Worker & wk, int p = 0) :Worker(wk), panache(p){};
	void Set();
	void Show()const;
	friend std::ostream& operator<<(std::ostream & os, const Waiter& wt);
};

class Singer :virtual public Worker
{
protected:
	enum{other,alto,contralto,soprano,bass,baritone,tenor};
	enum{Vtypes =7};
	void Data()const;
	void Get();
private:
	static char *pv[ Vtypes ];
	int voice;
public:
	Singer() :Worker(), voice(other){};
	Singer(const std::string & s, long n, int v = other) :Worker(s, n), voice(v){};
	Singer(const Worker & wk, int v = other) :Worker(wk), voice(v){};
	void Set();
	void Show()const;
	friend std::ostream& operator<<(std::ostream& os, const Singer& s);
};

class SingingWaiter :public Singer, public Waiter
{
protected:
	void Data()const;
	void Get();
public:
	SingingWaiter(){};
	SingingWaiter(const std::string & s, long n, int p = 0, int v = other) :Worker(s, n), Waiter(s, n, p), Singer(s, n, v){};
	SingingWaiter(const Worker & wk, int p = 0, int v = other) :Worker(wk), Waiter(wk, p), Singer(wk, v){};
	SingingWaiter(const Waiter & wt, int v = other) :Worker(wt), Waiter(wt), Singer(wt, v){};
	SingingWaiter(const Singer & wt, int p) :Worker(wt), Waiter(wt, p), Singer(wt){};
	void Set();
	void Show()const;
	friend std::ostream& operator<<(std::ostream& os, const SingingWaiter& sw);
};
#endif QueueTp_H_
