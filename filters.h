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
    std::sort(conteiner.begin(), conteiner.end(), std::greater<decltype(conteiner[0])>());
}

//filter by first byte
//template<typename Container>
//Container filter(const Container &conteiner, firstByte_type firstbyte)
//{
//    Container cont_;
//    std::copy_if(conteiner.begin(), conteiner.end(),
//                 std::back_inserter(cont_), [firstbyte](const auto &tuple)
//        {
//            return std::get<0>(tuple) == firstbyte;
//        });
//    return cont_;
//}

//filter by first and second bytes
//template<typename Container>
//Container filter(const Container &conteiner, firstByte_type firstbyte, secondByte_type secondbyte)
//{
//    Container cont_;
//    std::copy_if(conteiner.begin(), conteiner.end(),
//                 std::back_inserter(cont_), [firstbyte, secondbyte](const auto &tuple)
//        {
//            return (std::get<0>(tuple) == firstbyte) && (std::get<1>(tuple) == secondbyte);
//        });
//    return cont_;
//}

template<std::size_t i, typename Tuple, typename T>
inline bool pair_comparer(Tuple&& tuple, T a) {
  return std::get<i>(tuple) == a;
}

template<std::size_t i, typename Tuple, typename T, typename... Args>
inline bool pair_comparer(Tuple&& tuple, T a, Args... args) {
  return std::get<i>(tuple) == a && pair_comparer<i+1>(tuple, args...);
}

template<typename Container, typename... Args>
Container filter(const Container &conteiner, Args... bytes)
{
    static_assert(sizeof...(bytes) <= 4, "too more arg");
    static_assert(sizeof...(bytes) > 0, "too few arg");
    Container cont_;
    std::copy_if(conteiner.begin(), conteiner.end(),
                 std::back_inserter(cont_), [bytes...](const auto &tuple)
        {
            return pair_comparer<0>(tuple, bytes...);
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
