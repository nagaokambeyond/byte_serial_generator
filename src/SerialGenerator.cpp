#include "SerialGenerator.h"
#include <algorithm>
#include <iomanip>
#include <iostream>

SerialGenerator::SerialGenerator() { std::fill(arr.begin(), arr.end(), 0); }

void SerialGenerator::generate(void) {
    do {
        for (short val = 0; val <= MAX_VAL; val += 1) {
            arr[tail] = val;
            // display();
        }
        if (isEnd()) {
            break;
        }
        arr[tail] += 1;
        carry();
    } while (!isEnd());
}

bool SerialGenerator::isEnd(void) {
    return std::all_of(arr.begin(), arr.end(), [this](short val) { return val == MAX_VAL; });
}

void SerialGenerator::carry(void) {
    int next_idx = 0;
    for (int idx = tail; idx >= 0; idx--) {
        if (arr[idx] <= MAX_VAL) {
            continue;
        }
        next_idx = idx - 1;
        if (next_idx < 0) {
            break;
        }
        arr[idx] = 0;
        arr[next_idx] += 1;
    }
}

void SerialGenerator::display(void) {
    for (short val : arr) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << val;
    }
    std::cout << std::endl;
}