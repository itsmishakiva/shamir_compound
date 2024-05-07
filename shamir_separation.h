#ifndef LAB_3_SHAMIR_SEPARATION_H
#define LAB_3_SHAMIR_SEPARATION_H

#include <boost/multiprecision/cpp_int.hpp>
#include <utility>
#include <vector>
#include "secret_part.h"

class ShamirSeparation {
public:
    static std::vector<SecretPart> separate(const boost::multiprecision::int512_t& m, const unsigned long& k,
                                     const unsigned long& n);

private:

};


#endif //LAB_3_SHAMIR_SEPARATION_H
