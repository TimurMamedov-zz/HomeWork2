#define BOOST_TEST_MODULE ip_filter_test

#include <boost/test/unit_test.hpp>
#include "ip_pool_struct.h"

#include "version.h"
#include "filters.h"


BOOST_AUTO_TEST_CASE(version_test)
{
    BOOST_CHECK( version() > 0 );
}

BOOST_AUTO_TEST_SUITE(Test_IP_Filter)

BOOST_FIXTURE_TEST_CASE(reverse_lexicographically_sort_test, Fixture)
{
//    IP_Pool_type expected;

//    IP tuple1_temp(213, 219, 115, 76);
//    IP tuple2_temp(213, 213, 103, 190);
//    IP tuple3_temp(213, 213, 102, 167);
//    IP tuple4_temp(213, 213, 102, 166);

//    IP tuple5_temp(46, 70, 1, 166);
//    IP tuple6_temp(46, 70, 1, 165);

//    IP tuple7_temp(1, 213, 102, 166);
//    IP tuple8_temp(1, 213, 46, 166);

//    expected.push_back(tuple1_temp);
//    expected.push_back(tuple2_temp);
//    expected.push_back(tuple3_temp);
//    expected.push_back(tuple4_temp);
//    expected.push_back(tuple5_temp);
//    expected.push_back(tuple6_temp);
//    expected.push_back(tuple7_temp);
//    expected.push_back(tuple8_temp);

//    reverse_lexicographically_sort(value);

//    BOOST_CHECK_EQUAL_COLLECTIONS(value.begin(), value.end(), expected.begin(), expected.end());
}

BOOST_FIXTURE_TEST_CASE(filter_by_first_byte_test, Fixture)
{
//    IP_Pool_type expected;

//    IP tuple7_temp(1, 213, 102, 166);
//    IP tuple8_temp(1, 213, 46, 166);

//    expected.push_back(tuple7_temp);
//    expected.push_back(tuple8_temp);

//    reverse_lexicographically_sort(value);
//    auto&& ip_1 = filter(value, 1);

//    BOOST_CHECK_EQUAL_COLLECTIONS(ip_1.begin(), ip_1.end(), expected.begin(), expected.end());
}

BOOST_FIXTURE_TEST_CASE(filter_by_first_and_second_bytes_test, Fixture)
{
//    IP_Pool_type expected;

//    IP tuple5_temp(46, 70, 1, 166);
//    IP tuple6_temp(46, 70, 1, 165);

//    expected.push_back(tuple5_temp);
//    expected.push_back(tuple6_temp);

//    reverse_lexicographically_sort(value);
//    auto&& ip_46_70 = filter(value, 46, 70);

//    BOOST_CHECK_EQUAL_COLLECTIONS(ip_46_70.begin(), ip_46_70.end(), expected.begin(), expected.end());
}

BOOST_FIXTURE_TEST_CASE(filter_by_any_byte_test, Fixture)
{
//    IP_Pool_type expected;

//    IP tuple5_temp(46, 70, 1, 166);
//    IP tuple6_temp(46, 70, 1, 165);
//    IP tuple8_temp(1, 213, 46, 166);

//    expected.push_back(tuple5_temp);
//    expected.push_back(tuple6_temp);
//    expected.push_back(tuple8_temp);

//    reverse_lexicographically_sort(value);
//    auto&& ip_any_46 = filter_any(value, 46);

//    BOOST_CHECK_EQUAL_COLLECTIONS(ip_any_46.begin(), ip_any_46.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_SUITE_END()
