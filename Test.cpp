/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Barak Dafna>
 *
 * Date: 2021-02
 */


#include <iostream>
#include "doctest.h"
#include "mat.hpp"

using namespace ariel;

#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */

string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}


TEST_CASE ("Good input") {
            /* check with size 1X1 */
            CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));

            CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                            "@-------@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-@---@-@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-------@\n"
                                                            "@@@@@@@@@"));

            CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                            "@-----------@\n"
                                                            "@-@@@@@@@@@-@\n"
                                                            "@-----------@\n"
                                                            "@@@@@@@@@@@@@"));

            /* check with bigger size */
            CHECK(nospaces(mat(33, 17, '$', '+')) == nospaces("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
                                                               "$+++++++++++++++++++++++++++++++$\n"
                                                               "$+$$$$$$$$$$$$$$$$$$$$$$$$$$$$$+$\n"
                                                               "$+$+++++++++++++++++++++++++++$+$\n"
                                                               "$+$+$$$$$$$$$$$$$$$$$$$$$$$$$+$+$\n"
                                                               "$+$+$+++++++++++++++++++++++$+$+$\n"
                                                               "$+$+$+$$$$$$$$$$$$$$$$$$$$$+$+$+$\n"
                                                               "$+$+$+$+++++++++++++++++++$+$+$+$\n"
                                                               "$+$+$+$+$$$$$$$$$$$$$$$$$+$+$+$+$\n"
                                                               "$+$+$+$+++++++++++++++++++$+$+$+$\n"
                                                               "$+$+$+$$$$$$$$$$$$$$$$$$$$$+$+$+$\n"
                                                               "$+$+$+++++++++++++++++++++++$+$+$\n"
                                                               "$+$+$$$$$$$$$$$$$$$$$$$$$$$$$+$+$\n"
                                                               "$+$+++++++++++++++++++++++++++$+$\n"
                                                               "$+$$$$$$$$$$$$$$$$$$$$$$$$$$$$$+$\n"
                                                               "$+++++++++++++++++++++++++++++++$\n"
                                                               "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"));
}

TEST_CASE ("Bad input") {

            SUBCASE("Bad Size Parameters") {
        /* 2 size parameters are even */
                CHECK_THROWS(mat(10, 2, '$', '%'));
        /* one of the size parameters are even */
                CHECK_THROWS(mat(10, 5, '$', '%'));
                CHECK_THROWS(mat(8, 3, '$', '%'));
                CHECK_THROWS(mat(7, 4, '$', '%'));
        /* size parameters: one is even, one is zero */
                CHECK_THROWS(mat(2, 0, '$', '%'));
                CHECK_THROWS(mat(0, 2, '$', '%'));
        /* size parameters: one is odd, one is zero */
                CHECK_THROWS(mat(5, 0, '$', '%'));
                CHECK_THROWS(mat(0, 5, '$', '%'));
        /*both of the size parameters are zero */
                CHECK_THROWS(mat(0, 0, '$', '%'));
        /*negative size parameters */
                CHECK_THROWS(mat(1, -17, '$', '%'));
                CHECK_THROWS(mat(-21, 13, '$', '%'));
                CHECK_THROWS(mat(-21, 12, '$', '%'));
                CHECK_THROWS(mat(-1, -12, '$', '%'));
                CHECK_THROWS(mat(-1, -15, '$', '%'));
                CHECK_THROWS(mat(0, -17, '$', '%'));
                CHECK_THROWS(mat(-4, 0, '$', '%'));
    }
            SUBCASE("Bad Symbols") {
                /*one of the symbols is bad */
                CHECK_THROWS(mat(7, 9, ' ', '%'));
                CHECK_THROWS(mat(7, 9, '$', '\r'));
                /*both symbols are bad */
                CHECK_THROWS(mat(1, 5, '7', '\n'));
                CHECK_THROWS(mat(3, 7, '\n', '9'));
                CHECK_THROWS(mat(23, 17, '\n', '\t'));
                CHECK_THROWS(mat(7, 9, '\t', ' '));
                CHECK_THROWS(mat(13, 3, '\n', '\0'));



    }
}

