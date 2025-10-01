#define CATCH_CONFIG_MAIN
#include "../third_party/catch.hpp"
#include "../src/User.h"

TEST_CASE("User borrow limits work") {
    User u(1, "Alice", 2);
    REQUIRE(u.canBorrow());
    u.noteBorrow(10);
    REQUIRE(u.borrowCount() == 1);
    REQUIRE(u.canBorrow());
    u.noteBorrow(20);
    REQUIRE(u.borrowCount() == 2);
    REQUIRE_FALSE(u.canBorrow());
    u.noteReturn(10);
    REQUIRE(u.borrowCount() == 1);
    REQUIRE(u.canBorrow());
}
