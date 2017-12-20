#pragma once
#include <string>
#include <vector>

using IP_type = std::vector<std::string>;

struct IP : public IP_type
{
    bool operator!=(const IP &rhs) const
    {
        if(this->size() != rhs.size())
            return true;
        else
        {
            for(size_t i = 0; i < rhs.size(); i++)
            {
                if(this->at(i) != rhs.at(i))
                    return true;
            }
        }
        return false;
    }

    friend std::ostream &operator<<(std::ostream &os, const IP &ip)
    {
        if(ip.size() == 4)
            os << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] ;
        return os;
    }
};

using IP_Pool_type = std::vector<IP>;

struct IP_Pool : public IP_Pool_type
{
    bool operator!=(const IP_Pool &rhs) const
    {
        if(this->size() != rhs.size())
            return true;
        else
        {
            for(size_t i = 0; i < rhs.size(); i++)
            {
                if(this->at(i) != rhs.at(i))
                    return true;
            }
        }
        return false;
    }

    friend std::ostream &operator<<(std::ostream &os, const IP_Pool &ip_pool)
    {
        for(const auto& ip: ip_pool)
        {
            if(ip.size() == 4)
                os << ip << "\n";
        }
        return os;
    }
};
