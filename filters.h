#ifndef FILTERS_H
#define FILTERS_H

#include <assert.h>
#include <algorithm>

using firstByte_type = unsigned int;
using secondByte_type = unsigned int;
using anyByte_type = unsigned int;

//reverse lexicographically sort
template<typename Container>
void filter(Container &&conteiner)
{
    std::sort(conteiner.begin(), conteiner.end(),[](auto cont1, auto cont2)
        {
            assert(cont1.size() == 4 && cont2.size() == 4);

            if(std::stoi(cont1[0]) != std::stoi(cont2[0]))
                return std::stoi(cont1[0]) > std::stoi(cont2[0]);
            else if(std::stoi(cont1[1]) != std::stoi(cont2[1]))
                return std::stoi(cont1[1]) > std::stoi(cont2[1]);
            else if(std::stoi(cont1[2]) != std::stoi(cont2[2]))
                return std::stoi(cont1[2]) > std::stoi(cont2[2]);
            else if(std::stoi(cont1[3]) != std::stoi(cont2[3]))
                return std::stoi(cont1[3]) > std::stoi(cont2[3]);
        });
}

//filter by first byte
template<typename Container>
Container filter(const Container &conteiner, firstByte_type firstbyte)
{
    Container cont_;
    for(const auto& cont : conteiner)
    {
        if(cont.size() > 0)
        {
            if(std::stoi(cont[0]) == firstbyte)
            {
                cont_.push_back(cont);
            }
        }
    }
    return cont_;
}

//filter by first and second bytes
template<typename Container>
Container filter(const Container &conteiner, firstByte_type firstbyte, secondByte_type secondbyte)
{
    Container cont_;
    for(const auto& cont : conteiner)
    {
        if(cont.size() > 1)
        {
            if(std::stoi(cont[0]) == firstbyte && std::stoi(cont[1]) == secondbyte)
            {
                cont_.push_back(cont);
            }
        }
    }
    return cont_;
}

//filter by any byte
template<typename Container>
Container filter_any(const Container &conteiner, anyByte_type anybyte)
{
    Container cont_;
    for(const auto& cont : conteiner)
    {
        assert(cont.size() == 4);
        if(std::stoi(cont[0]) == anybyte || std::stoi(cont[1]) == anybyte ||
                std::stoi(cont[2]) == anybyte || std::stoi(cont[3]) == anybyte)
        {
            cont_.push_back(cont);
        }
    }
    return cont_;
}

#endif // FILTERS_H
