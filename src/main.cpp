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

void carry(int idx) {
    if (arr.at(idx) <= MAX_VAL) {
        return;
    }
    int next_idx = idx - 1;
    if (next_idx >= 0) {
        arr.at(idx) = 0;
        arr.at(next_idx) += 1;
        carry(next_idx);
    } else {
        display();
    }
}

bool is_end() {
    for (short val : arr) {
        if (val != MAX_VAL) {
            return false;
        }
    }
    return true;
}
int main() {

    int tail = arr.size() - 1;
    for (std::size_t idx = 0; idx < arr.size(); idx += 1) {
        arr.at(idx) = 0;
    }

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
}
