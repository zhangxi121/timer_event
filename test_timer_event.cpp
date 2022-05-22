#include <chrono>
#include <iostream>

#include "timer_event.h"
using namespace std;

void printANum(int a)
{
    std::cout << a << std::endl;
}

void printAString(std::string str)
{
    std::cout << str << std::endl;
}

void print3(void)
{
    std::cout << "11111111111111" << std::endl;
}

int main01(int argc, char **argv)
{
    TimerEvent timerevent(nullptr);
    auto f = std::bind(printANum, 100);
    auto f2 = std::bind(printAString, "hahahahhaha");

    timerevent.setTimeEvent(1, 1000, f, true);
    timerevent.setTimeEvent(2, 1000, f2, true);
    timerevent.setTimeEvent(3, 1000, print3, false);

    std::chrono::seconds sec(5);
    std::this_thread::sleep_for(sec);
    timerevent.cancelTimeEvent(1);
    std::chrono::seconds sec2(5);
    std::this_thread::sleep_for(sec2);

    return 0;
}

int main02(int argc, char **argv)
{
    ThreadPool *pool = new ThreadPool(3, 10);
    TimerEvent timerevent(pool);

    auto f = std::bind(printANum, 100);
    auto f2 = std::bind(printAString, "hahahahhaha");
    timerevent.setTimeEvent(1, 1000, f, true);
    timerevent.setTimeEvent(2, 1000, f2, true);
    std::chrono::seconds sec(5);
    std::this_thread::sleep_for(sec);
    timerevent.cancelTimeEvent(1);
    std::chrono::seconds sec2(30);  // 要给较长的时间, 让 threadppol 去回收线程, 正常退出,
    std::this_thread::sleep_for(sec2);

    return 0;
}



int main(int argc, char **argv)
{
    ThreadPool *pool = new ThreadPool(3, 10);
    TimerEvent timerevent(pool);

    auto f = std::bind(printANum, 100);
    auto f2 = std::bind(printAString, "hahahahhaha");

    timerevent.setTimeEvent(1, 1000, f, false);
    timerevent.setTimeEvent(2, 1000, f2, false);
    timerevent.setTimeEvent(3, 2000, f2, false);
    timerevent.setTimeEvent(4, 3000, f2, false);
    std::chrono::seconds sec(20);
    std::this_thread::sleep_for(sec);
  

    return 0;
}