#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <optional>
#include "Book.h"
#include "User.h"

enum class Status {
    Ok,
    NotFound,
    AlreadyExists,
    NotAvailable,
    UserLimitReached,
    InvalidOperation
};

class Library {
    // Storage hidden (encapsulation)
    std::unordered_map<int, Book> books_; // id -> Book
    std::unordered_map<int, User> users_; // id -> User
public:
    // Books
    Status addBook(const Book& b);
    Status removeBook(int bookId);
    std::optional<Book> getBook(int bookId) const;
    std::vector<Book> searchByTitle(const std::string& q) const;
    std::vector<Book> searchByAuthor(const std::string& q) const;
    std::vector<Book> searchByGenre(const std::string& q) const;

    // Users
    Status addUser(const User& u);
    std::optional<User> getUser(int userId) const;

    // Borrow/Return
    Status borrowBook(int userId, int bookId);
    Status returnBook(int userId, int bookId);
};
