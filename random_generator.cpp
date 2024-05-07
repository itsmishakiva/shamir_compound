#include "random_generator.h"

bool RandomGenerator::init = false;

RandomGenerator::RandomGenerator() {
    if (!init) {
        srand(time(nullptr));
        init = true;
    }
}

int RandomGenerator::even(int min, int max) {
    if (!init) return 0;
    return ((rand() % (max - min))) + min;
}

boost::multiprecision::int1024_t RandomGenerator::even(const boost::multiprecision::int1024_t& min, const boost::multiprecision::int1024_t& max) {
    boost::multiprecision::int1024_t res = 0;
    for (int i = 0; i < 512; i++) {
        res |= ((boost::multiprecision::int1024_t)even(0, 2) << i);
    }
    return res % (max - min) + min;
}