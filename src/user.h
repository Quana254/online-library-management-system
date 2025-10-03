// src/user.h
#pragma once
#include <string>
#include <unordered_set>

class User {
private:
    int id_;
    std::string name_;
    std::unordered_set<int> borrowed_; // book IDs
    size_t borrowLimit_{3};            // simple policy

public:
    User(int id, std::string name, size_t limit = 3);

    int id() const;
    const std::string& name() const;
    size_t borrowCount() const;
    size_t borrowLimit() const;
    bool hasBorrowed(int bookId) const;

    bool canBorrow() const;
    void noteBorrow(int bookId);
    void noteReturn(int bookId);
};
