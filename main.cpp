#include <iostream>
#include "random_generator.h"
#include "shamir_separation.h"
#include "shamir_compound.h"

int main() {
    RandomGenerator();
    auto res = ShamirSeparation::separate(325420022323, 4 , 42);
    std::vector<SecretPart> vec(0);
    vec.emplace_back(res[21]);
    vec.emplace_back(res[5]);
    vec.emplace_back(res[7]);
    vec.emplace_back(res[12]);
    std::cout << ShamirCompound::compound(vec);
    return 0;
}
