#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

const short MAX_VAL = 255;
std::vector<short> arr = {0, 0, 0, 0};

void display() {
    for (short val : arr) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << val;
    }
    std::cout << std::endl;
}

void carry(const int idx) {
    if (arr.at(idx) <= MAX_VAL) {
        return;
    }
    const int next_idx = idx - 1;
    if (next_idx < 0) {
        return;
    }
    arr.at(idx) = 0;
    arr.at(next_idx) += 1;
    carry(next_idx);
}

bool is_end() {
    return std::all_of(arr.begin(), arr.end(), [](short val) { return val == MAX_VAL; });
}
int main() {
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    std::fill(arr.begin(), arr.end(), 0);
    const int tail = arr.size() - 1;

    do {
        for (short val = 0; val <= MAX_VAL; val += 1) {
            arr.at(tail) = val;
            // display();
        }
        if (is_end()) {
            break;
        }
        arr.at(tail) += 1;
        carry(tail);
    } while (!is_end());
    display();

    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    std::chrono::microseconds dur = end - start;
    long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::cout << msec << " milli sec \n";
}
