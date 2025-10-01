#include <iostream>
#include "Library.h"

static const char* toString(Status s) {
    switch (s) {
        case Status::Ok: return "Ok";
        case Status::NotFound: return "NotFound";
        case Status::AlreadyExists: return "AlreadyExists";
        case Status::NotAvailable: return "NotAvailable";
        case Status::UserLimitReached: return "UserLimitReached";
        case Status::InvalidOperation: return "InvalidOperation";
        default: return "Unknown";
    }
}

int main() {
    Library lib;
    lib.addUser(User(1, "Alice", 2));
    lib.addUser(User(2, "Librarian", 5));

    lib.addBook(Book(100, "Clean Code", "Robert Martin", "Software", 2008));
    lib.addBook(Book(101, "The Pragmatic Programmer", "Andrew Hunt", "Software", 1999));

    std::cout << "Borrow result: " << toString(lib.borrowBook(1, 100)) << "\n";
    std::cout << "Borrow same again (should fail): " << toString(lib.borrowBook(1, 100)) << "\n";
    std::cout << "Return result: " << toString(lib.returnBook(1, 100)) << "\n";

    auto results = lib.searchByAuthor("martin");
    std::cout << "Search by author 'martin' -> " << results.size() << " hit(s)\n";
    return 0;
}
