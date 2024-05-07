#ifndef LAB_2_RANDOM_GENERATOR_H
#define LAB_2_RANDOM_GENERATOR_H

#include <boost/multiprecision/cpp_int.hpp>

class RandomGenerator {
public:
    RandomGenerator();

    static int even(int min, int max);

    static boost::multiprecision::int1024_t even(const boost::multiprecision::int1024_t& min, const boost::multiprecision::int1024_t& max);

private:
    static bool init;
};



#endif //LAB_2_RANDOM_GENERATOR_H
