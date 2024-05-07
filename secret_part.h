#ifndef LAB_2_SECRET_PART_H
#define LAB_2_SECRET_PART_H

#include <boost/multiprecision/cpp_int.hpp>

struct SecretPart {
    SecretPart() = default;

    SecretPart(boost::multiprecision::int512_t part, unsigned long index,
               boost::multiprecision::int512_t polynomialPow, boost::multiprecision::int512_t fieldMod) {
        this->part = std::move(part);
        this->index = std::move(index);
        this->polynomialPow = std::move(polynomialPow);
        this->fieldMod = std::move(fieldMod);
    }

    boost::multiprecision::int512_t part;
    unsigned long index;
    boost::multiprecision::int512_t polynomialPow;
    boost::multiprecision::int512_t fieldMod;
};



#endif //LAB_2_SECRET_PART_H
