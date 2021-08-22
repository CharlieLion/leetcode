//P31 实现单例模式
#include<pthread.h>
#include<iostream>
#include<mutex>
using namespace std;

// std::mutex mtx;
// class Singleton
// {
//     private:
//         Singleton(){}
//     private:
//         static Singleton* m_instances;
//     public:
//         static Singleton* getinstance();
       
// };
// Singleton* Singleton::m_instances = nullptr;

// Singleton* Singleton::getinstance()
// {
//     if(nullptr==m_instances)
//     {
//         mtx.lock();
//         if(nullptr==m_instances)
//         {
//             m_instances =new Singleton();
//         }
//         mtx.unlock();
//     }
//     return m_instances;
// }

std::mutex mtx;
class Singleton
{
public:
    static Singleton* getinstance()
    {
        if(instance == nullptr)
        {
            lock_guard<std::mutex> lck(mtx);
            if(instance == nullptr)
            {
                instance = new Singleton();
            }
        }
        return instance;
    }
private:
    static Singleton* instance;
    Singleton(){}
};
Singleton* Singleton::instance = nullptr;



int main()
{
    Singleton *a1= Singleton::getinstance();
    std::cout<<a1<<std::endl;
    return 0;
}
