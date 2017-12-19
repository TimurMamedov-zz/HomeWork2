#define BOOST_TEST_MODULE test_simple

#include <boost/test/unit_test.hpp>
#include <vector>

#include "version.h"
#include "filters.h"

BOOST_AUTO_TEST_SUITE(Test_IP_Filter)

BOOST_AUTO_TEST_CASE(version_test)
{
    BOOST_CHECK( version() > 0 );
}

BOOST_AUTO_TEST_CASE(reverse_lexicographically_sort_test)
{
    std::vector<std::vector<std::string> > vec1, vec2;
    std::vector<std::string> vec1_temp, vec2_temp, vec3_temp, vec4_temp;
    vec1_temp.push_back("213");
    vec1_temp.push_back("219");
    vec1_temp.push_back("115");
    vec1_temp.push_back("76");

    vec2_temp.push_back("213");
    vec2_temp.push_back("213");
    vec2_temp.push_back("103");
    vec2_temp.push_back("190");

    vec3_temp.push_back("213");
    vec3_temp.push_back("213");
    vec3_temp.push_back("102");
    vec3_temp.push_back("167");

    vec4_temp.push_back("213");
    vec4_temp.push_back("213");
    vec4_temp.push_back("102");
    vec4_temp.push_back("166");

    vec1.push_back(vec3_temp);
    vec1.push_back(vec1_temp);
    vec1.push_back(vec4_temp);
    vec1.push_back(vec2_temp);
    filter(vec1);

    vec2.push_back(vec1_temp);
    vec2.push_back(vec2_temp);
    vec2.push_back(vec3_temp);
    vec2.push_back(vec4_temp);
    
    BOOST_CHECK_EQUAL_COLLECTIONS(vec1.begin(), vec1.begin(), vec2.begin(), vec2.begin());
}
BOOST_AUTO_TEST_SUITE_END()
