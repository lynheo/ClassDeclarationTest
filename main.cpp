template<typename T>
class B;

template<>
class B<int>;

template<typename T>
class A
{
};

template<>
class A<int>
{
    private:
        int a;
    public:
        A() : a(0) {};
        void set(int _val)
        {
            a = _val;
        };
        int& getRef()
        {
            return  a;
        };
    A   operator+(const A& _var)
    {
        A<int>  result;
        B<int>  b = *this;

        /* 
            참조 클래스인 B의 인스턴스 b를 이용하는 부분...
        */
        result.a = a + _var.a;

        return  result;
    };
};

template<typename T>
class B
{
};

template<>
class B<int>
{
    private:
        int &aRef;
    public:
        B(A<int>& _var) : aRef(_var.getRef()) {};
};

int main()
{
    

    return  0;
}
