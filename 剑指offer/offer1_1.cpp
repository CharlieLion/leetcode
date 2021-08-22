#include<iostream>
class A
{
    private:
        int value;
    public:
        A(int n):value(n){};
        A(const A &other): value(other.value){};
        void print()
        {
            std::cout<<value<<std::endl;
        }
};

int main()
{
    A a = 10;
    a.print();
    return 0;
}