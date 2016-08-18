#include <vector>
#include "catch.hpp"

#include "bst/simple_bst.h"

using namespace dst;

TEST_CASE("Basic SimpleBST construction") {
    std::vector<int> value = {1, 2, 3};
    SimpleBST<int> bst(value.begin(), value.end());
    SimpleBST<int> other = {1, -2, 0};
}

TEST_CASE("SimpleBST iteration") {
    SimpleBST<int> bst = {1, 4, 6, 7, 8, 2, 9, 5, 3};
    std::vector<int> iteration(9), expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::copy(bst.begin(), bst.end(), iteration.begin());

    REQUIRE(iteration == expected);
}

