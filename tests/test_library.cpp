#include "../third_party/catch.hpp"
#include "../src/Library.h"

TEST_CASE("Add, search, borrow, return flow") {
    Library lib;
    REQUIRE(lib.addUser(User(1, "Alice")) == Status::Ok);
    REQUIRE(lib.addBook(Book(100, "Clean Code", "Robert Martin", "Software", 2008)) == Status::Ok);
    REQUIRE(lib.addBook(Book(101, "DDD", "Eric Evans", "Software", 2003)) == Status::Ok);

    SECTION("Search by title/author/genre") {
        auto t = lib.searchByTitle("clean");
        REQUIRE(t.size() == 1);
        auto a = lib.searchByAuthor("eric");
        REQUIRE(a.size() == 1);
        auto g = lib.searchByGenre("software");
        REQUIRE(g.size() == 2);
    }

    SECTION("Happy path borrow/return") {
        REQUIRE(lib.borrowBook(1, 100) == Status::Ok);
        auto b = lib.getBook(100);
        REQUIRE(b.has_value());
        REQUIRE_FALSE(b->available());

        REQUIRE(lib.returnBook(1, 100) == Status::Ok);
        b = lib.getBook(100);
        REQUIRE(b->available());
    }

    SECTION("Negative cases") {
        REQUIRE(lib.borrowBook(1, 999) == Status::NotFound);     // book missing
        REQUIRE(lib.borrowBook(999, 100) == Status::NotFound);   // user missing

        // Borrow twice to hit NotAvailable
        REQUIRE(lib.borrowBook(1, 100) == Status::Ok);
        REQUIRE(lib.borrowBook(1, 100) == Status::NotAvailable);
        // Return without having (different book)
        REQUIRE(lib.returnBook(1, 101) == Status::InvalidOperation);
    }
}
