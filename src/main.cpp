#include <algorithm>
#include <array>
#include <chrono>
#include <iomanip>
#include <iostream>

const short MAX_VAL = 255;
std::array<short, 4> arr;

void display() {
    for (short val : arr) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << val;
    }
    std::cout << std::endl;
}

void carry(const int idx) {
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

bool is_end() {
    return std::all_of(arr.begin(), arr.end(), [](short val) { return val == MAX_VAL; });
}
int main() {
    const auto start = std::chrono::system_clock::now();

    std::fill(arr.begin(), arr.end(), 0);
    const int tail = arr.size() - 1;

    do {
        for (short val = 0; val <= MAX_VAL; val += 1) {
            arr[tail] = val;
            // display();
        }
        if (is_end()) {
            break;
        }
        arr[tail] += 1;
        carry(tail);
    } while (!is_end());
    display();

    const auto end = std::chrono::system_clock::now();
    const auto dur = end - start;
    const auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::cout << std::dec << msec << " milli sec \n";
}
