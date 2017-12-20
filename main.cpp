#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "filters.h"

using firstByte_type = unsigned int;
using secondByte_type = unsigned int;
using thirdByte_type = unsigned int;
using fourthByte_type = unsigned int;

using IP_pool_type = std::vector<std::tuple<firstByte_type, secondByte_type, thirdByte_type, fourthByte_type> >;

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
auto split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    auto stop = str.find_first_of(d);

    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

auto print_IP_pool = [](auto&& ip_pool)
{
    for(const auto& tuple: ip_pool)
    {
        std::cout << std::get<0>(tuple) << "." << std::get<1>(tuple) << "." <<
                 std::get<2>(tuple) << "." << std::get<3>(tuple) <<std::endl;
    }
};

int main(int argc, char const *argv[])
{
    try
    {
        IP_pool_type ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            auto&& v = split(line, '\t');
            auto&& bytes = split(v.at(0), '.');
            assert(bytes.size() == 4);
            ip_pool.emplace_back(std::make_tuple(std::stoi(bytes[0]), std::stoi(bytes[1]),
                    std::stoi(bytes[2]), std::stoi(bytes[3])));
        }

        reverse_lexicographically_sort(ip_pool);

        auto&& ip1 = filter(ip_pool, 1);

        auto&& ip46_70 = filter(ip_pool, 46, 70);

        auto&& ip_any46 = filter_any(ip_pool, 46);

        print_IP_pool(ip_pool);
        //        std::cout << std::endl << std::endl;
        print_IP_pool(ip1);
        //        std::cout << std::endl << std::endl;
        print_IP_pool(ip46_70);
        //        std::cout << std::endl << std::endl;
        print_IP_pool(ip_any46);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
