#pragma once
#include <string>
#include <unordered_set>

class User {
    int id_;
    std::string name_;
    std::unordered_set<int> borrowed_; // book IDs
    size_t borrowLimit_{3};            // simple policy
public:
    User(int id, std::string name, size_t limit = 3)
        : id_(id), name_(std::move(name)), borrowLimit_(limit) {}

    int id() const { return id_; }
    const std::string& name() const { return name_; }
    size_t borrowCount() const { return borrowed_.size(); }
    size_t borrowLimit() const { return borrowLimit_; }
    bool hasBorrowed(int bookId) const { return borrowed_.count(bookId) > 0; }

    bool canBorrow() const { return borrowed_.size() < borrowLimit_; }
    void noteBorrow(int bookId) { borrowed_.insert(bookId); }
    void noteReturn(int bookId) { borrowed_.erase(bookId); }
};
