#define BOOST_TEST_MODULE ip_filter_test

#include <boost/test/unit_test.hpp>
#include <vector>

#include "version.h"
#include "filters.h"
#include "ip_pool_struct.h"

BOOST_AUTO_TEST_SUITE(Test_IP_Filter)

BOOST_AUTO_TEST_CASE(version_test)
{
    BOOST_CHECK( version() > 0 );
}

BOOST_AUTO_TEST_CASE(reverse_lexicographically_sort_test)
{
    IP_Pool vec1, expected;
    IP vec1_temp, vec2_temp, vec3_temp, vec4_temp;
    vec1_temp.emplace_back(std::string("213"));
    vec1_temp.emplace_back(std::string("219"));
    vec1_temp.emplace_back(std::string("115"));
    vec1_temp.emplace_back(std::string("76"));

    vec2_temp.emplace_back(std::string("213"));
    vec2_temp.emplace_back(std::string("213"));
    vec2_temp.emplace_back(std::string("103"));
    vec2_temp.emplace_back(std::string("190"));

    vec3_temp.emplace_back(std::string("213"));
    vec3_temp.emplace_back(std::string("213"));
    vec3_temp.emplace_back(std::string("102"));
    vec3_temp.emplace_back(std::string("167"));

    vec4_temp.emplace_back(std::string("213"));
    vec4_temp.emplace_back(std::string("213"));
    vec4_temp.emplace_back(std::string("102"));
    vec4_temp.emplace_back(std::string("166"));

    vec1.push_back(vec3_temp);
    vec1.push_back(vec1_temp);
    vec1.push_back(vec4_temp);
    vec1.push_back(vec2_temp);
    filter(vec1);

    expected.push_back(vec1_temp);
    expected.push_back(vec2_temp);

    expected.push_back(vec4_temp);
    expected.push_back(vec3_temp);

    BOOST_REQUIRE_EQUAL(vec1.size(), expected.size());

    BOOST_CHECK_EQUAL_COLLECTIONS(vec1.begin(), vec1.begin(), expected.begin(), expected.begin());
}

BOOST_AUTO_TEST_SUITE_END()
