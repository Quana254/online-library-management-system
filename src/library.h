#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include "book.h"
#include "user.h"

class Library {
private:
    std::unordered_map<int, Book> booksById_;
    std::unordered_map<int, User> usersById_;

public:
    // Book management
    bool addBook(const Book& b);
    bool removeBook(int bookId); // fails if book not found or borrowed
    Book* findBook(int bookId);
    const Book* findBook(int bookId) const;

    std::vector<Book*> searchByTitle(const std::string& title);
    std::vector<Book*> searchByAuthor(const std::string& author);
    std::vector<Book*> searchByYear(int year);

    // User management
    bool addUser(const User& u);
    bool removeUser(int userId); // fails if user not found or holds books
    User* findUser(int userId);
    const User* findUser(int userId) const;

    // Circulation
    bool borrowBook(int bookId, int userId);
    bool returnBook(int bookId, int userId);
};
