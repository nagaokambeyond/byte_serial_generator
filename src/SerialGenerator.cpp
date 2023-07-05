#include "SerialGenerator.h"
#include <algorithm>
#include <iomanip>
#include <iostream>

SerialGenerator::SerialGenerator() { std::fill(arr.begin(), arr.end(), 0); }

void SerialGenerator::generate(void) {
    const int tail = arr.size() - 1;

    do {
        for (short val = 0; val <= MAX_VAL; val += 1) {
            arr[tail] = val;
            // display();
        }
        if (isEnd()) {
            break;
        }
        arr[tail] += 1;
        carry(tail);
    } while (!isEnd());
}

bool SerialGenerator::isEnd(void) {
    return std::all_of(arr.begin(), arr.end(), [this](short val) { return val == MAX_VAL; });
}

void SerialGenerator::carry(const int idx) {
    if (arr[idx] <= MAX_VAL) {
        return;
    }
    const int next_idx = idx - 1;
    if (next_idx < 0) {
        return;
    }
    arr[idx] = 0;
    arr[next_idx] += 1;
    carry(next_idx);
}

void SerialGenerator::display(void) {
    for (short val : arr) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << val;
    }
    std::cout << std::endl;
}