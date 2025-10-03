#include <iostream>
#include "library.h"

int main() {
    Library lib;
    lib.addBook(Book(1,"Clean Code","Robert C. Martin","SE",2008));
    lib.addBook(Book(2,"The Pragmatic Programmer","Andrew Hunt","SE",1999));
    lib.addUser(User(101,"Student A",2));

    std::cout << "== Library Demo ==\n";
    std::cout << "Borrow book 1 by user 101: "
              << (lib.borrowBook(1,101) ? "OK" : "FAIL") << "\n";
    std::cout << "Borrow book 1 again: "
              << (lib.borrowBook(1,101) ? "OK" : "FAIL") << "\n";
    std::cout << "Return book 1: "
              << (lib.returnBook(1,101) ? "OK" : "FAIL") << "\n";

    std::cout << "\nBooks by Robert C. Martin:\n";
    for (auto* b : lib.searchByAuthor("Robert C. Martin")) {
        std::cout << " - " << b->title() << " (" << b->year() << ")\n";
    }
    return 0;
}
