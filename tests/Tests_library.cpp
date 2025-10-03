#include "TestRunner.h"
#include "../src/library.h"

bool test_library_crud() {
    Library lib;
    ASSERT_TRUE(lib.addBook(Book(1,"A","Auth","",2020)));
    ASSERT_TRUE(!lib.addBook(Book(1,"Dup","X","",2021))); // duplicate ID
    auto v1 = lib.searchByAuthor("Auth");
    ASSERT_EQ(v1.size(), 1u);

    ASSERT_TRUE(lib.removeBook(1));
    ASSERT_TRUE(!lib.removeBook(1)); // already removed

    ASSERT_TRUE(lib.addUser(User(10,"Bob")));
    ASSERT_TRUE(!lib.addUser(User(10,"Dup")));
    return true;
}
int main(){ report("Library CRUD/search", test_library_crud()); }
