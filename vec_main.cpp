#include <iostream>
#include "vector1.h"

int main() {
    Vector vec;
    vec.push_back(99);
    vec.push_back(7);
    vec.push_back(56);
    std::cout << vec.begin() << " ";
    std::cout << vec.end() << " ";
    std::cout << vec.at(1) << " ";
    vec.shrink_to_fit();
}
