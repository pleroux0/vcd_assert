#include "parse/util/array_append.hpp"

#include <catch2/catch.hpp>

using namespace Parse;

constexpr std::array<char, 1> arr_1 {'a'};
constexpr std::array<char, 3> arr_2 {'b', 'c', 'd'};
constexpr std::array<char, 1> arr_3 {'e'};

constexpr std::array<char, 5> arr_123 {'a', 'b', 'c', 'd', 'e'};

TEST_CASE("Parse.Util.ArrayAppend", "[Util]") {
  constexpr auto appended_arr = Util::array_append(arr_1, arr_2, arr_3);
  REQUIRE(std::equal(arr_123.begin(), arr_123.end(), appended_arr.begin()));
}
