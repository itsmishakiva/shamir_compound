#ifndef LAB_3_SHAMIR_COMPOUND_H
#define LAB_3_SHAMIR_COMPOUND_H

#include <boost/multiprecision/cpp_int.hpp>
#include "secret_part.h"

class ShamirCompound {
public:
    static boost::multiprecision::int512_t compound(const std::vector<SecretPart>& parts);
};


#endif //LAB_3_SHAMIR_COMPOUND_H
