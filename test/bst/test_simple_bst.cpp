#include <vector>
#include "catch.hpp"

#include "bst/simple_bst.h"

using namespace dst;

TEST_CASE("Basic SimpleBST construction") {
    std::vector<int> value = {1, 2, 3};
    SimpleBST<int> bst(value.begin(), value.end());
    SimpleBST<int> other = {1, -2, 0};
}

TEST_CASE("SimpleBST comparison") {
    SimpleBST<int> a = {1, 4, 6}, b = {1, 4, 6}, c = {1, 4},
            d = {}, e = {6, 4}, f = {-7, 8, 9, 10, 2};

    REQUIRE(a == b);
    REQUIRE(a != c);
    REQUIRE(a != d);
    REQUIRE(a != e);
    REQUIRE(a != f);
}


TEST_CASE("SimpleBST iteration") {
    SimpleBST<int> bst = {1, 4, 6, 7, 8, 2, 9, 5, 3};
    std::vector<int> iteration(9), expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::copy(bst.begin(), bst.end(), iteration.begin());

    REQUIRE(iteration == expected);
}

TEST_CASE("SimpleBST contains") {
    SimpleBST<int> bst = {1, 4, -2};
    REQUIRE(bst.contains(1));
    REQUIRE(!bst.contains(2));
}

TEST_CASE("SimpleBST insertion") {
    SimpleBST<int> bst;
    bst.insert(1);
    REQUIRE(bst == SimpleBST<int>({1}));
    bst.insert(-4);
    REQUIRE(bst == SimpleBST<int>({-4, 1}));
}