#include <array>

#ifndef SERIAL_GENERATOR_H
#define SERIAL_GENERATOR_H

class SerialGenerator {
  private:
    const short MAX_VAL = 255;
    std::array<short, 4> arr;
    bool isEnd(void);
    void carry(const int idx);

  public:
    SerialGenerator(void);
    void generate(void);
    void display(void);
};

#endif