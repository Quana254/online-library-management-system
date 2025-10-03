#include "user.h"
#include <utility>

User::User(int id, std::string name, size_t limit)
    : id_(id), name_(std::move(name)), borrowed_{}, borrowLimit_(limit) {}

int User::id() const { return id_; }
const std::string& User::name() const { return name_; }
size_t User::borrowCount() const { return borrowed_.size(); }
size_t User::borrowLimit() const { return borrowLimit_; }
bool User::hasBorrowed(int bookId) const { return borrowed_.count(bookId) > 0; }

bool User::canBorrow() const { return borrowed_.size() < borrowLimit_; }

bool User::noteBorrow(int bookId) {
    if (!canBorrow()) return false;
    return borrowed_.insert(bookId).second;
}

bool User::noteReturn(int bookId) {
    return borrowed_.erase(bookId) > 0;
}
