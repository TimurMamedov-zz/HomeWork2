#ifndef FILTERS_H
#define FILTERS_H

#include <assert.h>
#include <algorithm>

using firstByte_type = unsigned int;
using secondByte_type = unsigned int;
using anyByte_type = unsigned int;

template<typename Container>
void reverse_lexicographically_sort(Container &&conteiner)
{
    std::sort(conteiner.begin(), conteiner.end(), [](const auto &a, const auto &b){ return a > b; });
}

//filter by first byte
template<typename Container>
Container filter(const Container &conteiner, firstByte_type firstbyte)
{
    Container cont_;
    std::copy_if(conteiner.begin(), conteiner.end(),
                 std::back_inserter(cont_), [firstbyte](const auto &tuple)
        {
            return std::get<0>(tuple) == firstbyte;
        });
    return cont_;
}

//filter by first and second bytes
template<typename Container>
Container filter(const Container &conteiner, firstByte_type firstbyte, secondByte_type secondbyte)
{
    Container cont_;
    std::copy_if(conteiner.begin(), conteiner.end(),
                 std::back_inserter(cont_), [firstbyte, secondbyte](const auto &tuple)
        {
            return (std::get<0>(tuple) == firstbyte) && (std::get<1>(tuple) == secondbyte);
        });
    return cont_;
}

//filter by any byte
template<typename Container>
Container filter_any(const Container &conteiner, anyByte_type anybyte)
{
    Container cont_;
    std::copy_if(conteiner.begin(), conteiner.end(),
                 std::back_inserter(cont_), [anybyte](const auto &tuple)
        {
            return (std::get<0>(tuple) == anybyte) || (std::get<1>(tuple) == anybyte) ||
                    (std::get<2>(tuple) == anybyte) || (std::get<3>(tuple) == anybyte);
        });
    return cont_;
}

#endif // FILTERS_H
