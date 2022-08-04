// Multithreaded_HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

static int HeapInt = 0;

void HelloWorldButCool() {
    std::cout << "Hello and good day to you World!" << std::endl;
}

int main()
{
    HeapInt = 5;

    std::cout << "Hello World!\n";
    std::thread Hello(HelloWorldButCool);
    Hello.join();
    return 0;
}
