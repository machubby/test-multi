#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <ctime>
#include <string>

void tic(int mode=0) {
    static std::chrono::_V2::system_clock::time_point t_start;
    
    if (mode==0)
        t_start = std::chrono::high_resolution_clock::now();
    else {
        auto t_end = std::chrono::high_resolution_clock::now();
        std::cout << "Elapsed time is " << (t_end-t_start).count()*1E-9 << " seconds\n";
    }
}
void toc() { tic(1); }
 
void foo()
{
    //std::thread::id this_id = std::this_thread::get_id();
    //std::cout << "thread " << this_id << std::endl;
    std::string sysCallStr = "./print";
    system(sysCallStr.c_str());
}

int main()
{

    tic();
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    std::thread t4(foo);
    std::thread t5(foo);
    std::thread t6(foo);
    std::thread t7(foo);
    std::thread t8(foo);
    std::thread t9(foo);
    std::thread t10(foo);
 
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    toc();

    tic();
    foo();
    foo();
    foo();
    foo();
    foo();
    foo();
    foo();
    foo();
    foo();
    foo();
    toc(); 
}