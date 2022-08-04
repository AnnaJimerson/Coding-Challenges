// Multithreaded_HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

static int HeapInt = 0;
int counter = 0;
bool run = true;

void HelloWorldButCool() {
    while (run) {
        counter++;
        
        if (counter > 1000) counter = 0;
    }
}

int main()
{
    char input;
    HeapInt = 5;
    std::thread Hello(HelloWorldButCool);

    while (run) {
        std::cout << "Input character to stop counter and hit enter.\n";
        std::cout << "(q to quit)" << std::endl;
        std::cin >> input;
        std::cout << "ThreadCounter: " << counter << std::endl;

        if (input == 'q') run = false;
    }

    Hello.join();
    return 0;
}
