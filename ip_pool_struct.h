#pragma once
#include <string>
#include <vector>
#include <tuple>

using firstByte_type = unsigned int;
using secondByte_type = unsigned int;
using thirdByte_type = unsigned int;
using fourthByte_type = unsigned int;

using IP_type = std::tuple<firstByte_type, secondByte_type, thirdByte_type, fourthByte_type>;

struct IP : public IP_type
{
    IP(firstByte_type&& firstbyte, secondByte_type&& secondbyte,
       thirdByte_type&& thirdbyte, fourthByte_type&& fourthbyte)
        :IP_type(firstbyte, secondbyte, thirdbyte, fourthbyte){}

    friend std::ostream &operator<<(std::ostream &os, const IP &ip)
    {
        os << std::get<0>(ip)<< "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip) ;
        return os;
    }
};

using IP_Pool_type = std::vector<IP>;

struct Fixture
{
    Fixture()
    {
        IP tuple1_temp(213, 219, 115, 76);
        IP tuple2_temp(213, 213, 103, 190);
        IP tuple3_temp(213, 213, 102, 167);
        IP tuple4_temp(213, 213, 102, 166);

        IP tuple5_temp(46, 70, 1, 166);
        IP tuple6_temp(46, 70, 1, 165);

        IP tuple7_temp(1, 213, 102, 166);
        IP tuple8_temp(1, 213, 46, 166);

        value.push_back(tuple3_temp);
        value.push_back(tuple1_temp);
        value.push_back(tuple4_temp);
        value.push_back(tuple2_temp);
        value.push_back(tuple7_temp);
        value.push_back(tuple6_temp);
        value.push_back(tuple8_temp);
        value.push_back(tuple5_temp);
    }

    IP_Pool_type value;
};
