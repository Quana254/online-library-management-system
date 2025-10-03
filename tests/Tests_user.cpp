#include "TestRunner.h"
#include "../src/user.h"

bool test_user_limit(){
    User u(7,"Alice",2);
    ASSERT_TRUE(u.canBorrow());
    ASSERT_TRUE(u.noteBorrow(10));
    ASSERT_TRUE(u.noteBorrow(11));
    ASSERT_TRUE(!u.canBorrow());
    ASSERT_TRUE(!u.noteBorrow(12)); // at limit
    ASSERT_TRUE(u.hasBorrowed(10));
    ASSERT_TRUE(u.noteReturn(10));
    ASSERT_TRUE(u.canBorrow());
    ASSERT_TRUE(!u.noteReturn(10)); // already returned
    return true;
}
int main(){ report("User borrow limit", test_user_limit()); }
