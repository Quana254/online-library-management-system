#include "TestRunner.h"
#include "../src/book.h"

bool test_book() {
    Book b(1,"Clean Code","Robert Martin","SE",2008);
    ASSERT_TRUE(b.available());
    ASSERT_TRUE(b.borrow(100));
    ASSERT_TRUE(!b.available());
    ASSERT_TRUE(!b.borrow(101)); // cannot double-borrow
    ASSERT_TRUE(b.giveBack());
    ASSERT_TRUE(b.available());
    ASSERT_TRUE(!b.giveBack());  // cannot give back twice
    return true;
}
int main(){ report("Book borrow/return", test_book()); }
