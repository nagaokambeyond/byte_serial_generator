#include <iostream>
#include <iomanip>

const short MAX_VAL = 255;
short arr[] = {0, 0, 0, 0};

void display()
{
    for (short val : arr)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << val;
    }
    std::cout << std::endl;
}

void carry(int idx)
{
    if (arr[idx] <= MAX_VAL)
    {
        return;
    }
    int next_idx = idx - 1;
    if (next_idx >= 0)
    {
        arr[idx] = 0;
        arr[next_idx] += 1;
        carry(next_idx);
    }
    else
    {
        display();
    }
}

bool is_end()
{
    for (short val : arr)
    {
        if (val != MAX_VAL)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int tail = std::size(arr) - 1;
    for (int idx = 0; idx <= tail; idx += 1)
    {
        arr[idx] = 0;
    }

    do
    {
        for (short val = 0; val <= MAX_VAL; val += 1)
        {
            arr[tail] = val;
            // display();
        }
        if (is_end())
        {
            break;
        }
        arr[tail] += 1;
        carry(tail);
    } while (!is_end());
    display();
}
