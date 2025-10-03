#include "TestRunner.h"
#include "../src/library.h"

bool test_flow(){
    Library lib;
    lib.addBook(Book(1,"DSA","Weiss","",2014));
    lib.addBook(Book(2,"OOP","Bjarne","",2013));
    lib.addUser(User(100,"Brian",1)); // max 1

    ASSERT_TRUE(lib.borrowBook(1,100));
    ASSERT_TRUE(!lib.borrowBook(2,100));   // over limit
    ASSERT_TRUE(!lib.removeBook(1));       // cannot remove borrowed
    ASSERT_TRUE(lib.returnBook(1,100));
    ASSERT_TRUE(lib.borrowBook(2,100));    // now ok
    return true;
}
int main(){ report("Integration borrow/return", test_flow()); }
