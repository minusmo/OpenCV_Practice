//
// Created by HoJoonEum on 2023/02/28.
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "../calc.h"

BOOST_AUTO_TEST_SUITE(calc_testsuite)

BOOST_AUTO_TEST_CASE(addvalues_zero)
    {
        BOOST_CHECK_EQUAL (add_values(1,4),5);
        BOOST_CHECK_EQUAL (add_values(2,3),5);
    }
}