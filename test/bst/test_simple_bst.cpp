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

    bst = {};
    iteration.resize(0);
    std::copy(bst.begin(), bst.end(), iteration.begin());

    REQUIRE(iteration == std::vector<int>());

    bst = {1};
    iteration.resize(1);
    std::copy(bst.begin(), bst.end(), iteration.begin());

    REQUIRE(iteration == std::vector<int>({1}));
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
    REQUIRE(bst.size() == 1);
    bst.insert(-4);
    REQUIRE(bst == SimpleBST<int>({-4, 1}));
    REQUIRE(bst.size() == 2);
}

TEST_CASE("SimpleBST removal") {
    SimpleBST<int> bst = {0, 1, 2, 3, 4, 5}, a = {0, 1, 2, 3, 4, 5},
            b = {0, 1, 2, 4, 5}, c = {0, 2, 4, 5}, d = {2, 4, 5}, e = {2, 5},
            f = {2}, g = {};

    bst.remove(-4);
    REQUIRE(bst == a);
    REQUIRE(bst.size() == 6);

    bst.remove(3);
    REQUIRE(bst == b);
    REQUIRE(bst.size() == 5);

    bst.remove(1);
    REQUIRE(bst == c);
    REQUIRE(bst.size() == 4);

    bst.remove(0);
    REQUIRE(bst == d);
    REQUIRE(bst.size() == 3);

    bst.remove(4);
    REQUIRE(bst == e);
    REQUIRE(bst.size() == 2);

    bst.remove(8547);
    REQUIRE(bst == e);
    REQUIRE(bst.size() == 2);

    bst.remove(5);
    REQUIRE(bst == f);
    REQUIRE(bst.size() == 1);

    bst.remove(2);
    REQUIRE(bst == g);
    REQUIRE(bst.size() == 0);


}

TEST_CASE("SimpleBST size") {
    SimpleBST<int> a = {}, b = {1, 2, 3}, c = {1, 1, 1, 4, 7, -8};
    REQUIRE(a.size() == 0);
    REQUIRE(b.size() == 3);
    REQUIRE(c.size() == 6);
}