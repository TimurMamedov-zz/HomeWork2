#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "filters.h"

using IP_pool_type = std::vector<std::vector<std::string> >;

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
    for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";

            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
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
            ip_pool.emplace_back(split(v.at(0), '.'));
        }

        filter(ip_pool);
        print_IP_pool(ip_pool);

//        std::cout << std::endl << std::endl;
        auto&& ip1 = filter(ip_pool, 1);

        print_IP_pool(ip1);

//        std::cout << std::endl << std::endl;
        auto&& ip46_70 = filter(ip_pool, 46, 70);

        print_IP_pool(ip46_70);

//        std::cout << std::endl << std::endl;
        auto&& ip_any46 = filter_any(ip_pool, 46);

        print_IP_pool(ip_any46);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
