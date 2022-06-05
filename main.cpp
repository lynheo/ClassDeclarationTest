#include <iostream>
#include <float.h>

template <typename T> 
class B;

template <typename T> 
class A
{
};

template <>
class A<int>
{
private:
	int a;
public:
	A() :a(0)
	{

	};
	void set(int _val)
	{
		a = _val;
	};

	int& getRef()
	{
		return a;
	};

	A<int> operator+ (const A<int>& _var);
};


template <typename T> 
class B
{
};

template <>
class B<int>
{
private:
	int& aRef;
public:
	B(A<int>& _var) :aRef(_var.getRef())
	{
	};
};

A<int> A<int>::operator+ (const A<int>& _var)
{
	A<int> result;
	B<int> b(*this);

	result.a = a + _var.a;
	return result;
}

int main()
{
	return 0;
}
