#pragma once
#include <string>
#include <unordered_set>

class User {
private:
    int id_;
    std::string name_;
    std::unordered_set<int> borrowed_; // book IDs
    size_t borrowLimit_{3};

public:
    User(int id, std::string name, size_t limit = 3);

    int id() const;
    const std::string& name() const;
    size_t borrowCount() const;
    size_t borrowLimit() const;
    bool hasBorrowed(int bookId) const;

    bool canBorrow() const;
    bool noteBorrow(int bookId); // false if at limit or already borrowed
    bool noteReturn(int bookId); // false if not present
};
