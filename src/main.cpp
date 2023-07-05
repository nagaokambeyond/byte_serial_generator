#include "SerialGenerator.h"
#include <chrono>
#include <iostream>

int main(void) {
    SerialGenerator cls;

    const auto start = std::chrono::system_clock::now();
    cls.generate();
    cls.display();

    const auto end = std::chrono::system_clock::now();
    const auto dur = end - start;
    const auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::cout << std::dec << msec << " milli sec \n";
}
