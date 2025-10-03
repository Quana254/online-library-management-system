#include "library.h"

bool Library::addBook(const Book& b) {
    return booksById_.emplace(b.id(), b).second;
}

bool Library::removeBook(int bookId) {
    auto it = booksById_.find(bookId);
    if (it == booksById_.end()) return false;
    if (!it->second.available()) return false; // can't remove borrowed book
    booksById_.erase(it);
    return true;
}

Book* Library::findBook(int bookId) {
    auto it = booksById_.find(bookId);
    return (it == booksById_.end()) ? nullptr : &it->second;
}
const Book* Library::findBook(int bookId) const {
    auto it = booksById_.find(bookId);
    return (it == booksById_.end()) ? nullptr : &it->second;
}

std::vector<Book*> Library::searchByTitle(const std::string& title) {
    std::vector<Book*> out;
    for (auto& kv : booksById_) if (kv.second.title() == title) out.push_back(&kv.second);
    return out;
}
std::vector<Book*> Library::searchByAuthor(const std::string& author) {
    std::vector<Book*> out;
    for (auto& kv : booksById_) if (kv.second.author() == author) out.push_back(&kv.second);
    return out;
}
std::vector<Book*> Library::searchByYear(int year) {
    std::vector<Book*> out;
    for (auto& kv : booksById_) if (kv.second.year() == year) out.push_back(&kv.second);
    return out;
}

bool Library::addUser(const User& u) {
    return usersById_.emplace(u.id(), u).second;
}

bool Library::removeUser(int userId) {
    auto it = usersById_.find(userId);
    if (it == usersById_.end()) return false;
    if (it->second.borrowCount() > 0) return false; // holding books
    usersById_.erase(it);
    return true;
}

User* Library::findUser(int userId) {
    auto it = usersById_.find(userId);
    return (it == usersById_.end()) ? nullptr : &it->second;
}
const User* Library::findUser(int userId) const {
    auto it = usersById_.find(userId);
    return (it == usersById_.end()) ? nullptr : &it->second;
}

bool Library::borrowBook(int bookId, int userId) {
    Book* b = findBook(bookId);
    User* u  = findUser(userId);
    if (!b || !u) return false;
    if (!u->canBorrow()) return false;
    if (!b->available()) return false;

    if (!b->borrow(userId)) return false;
    if (!u->noteBorrow(bookId)) { // rollback if user step fails
        b->giveBack();
        return false;
    }
    return true;
}

bool Library::returnBook(int bookId, int userId) {
    Book* b = findBook(bookId);
    User* u  = findUser(userId);
    if (!b || !u) return false;
    if (!u->hasBorrowed(bookId)) return false;

    if (!b->giveBack()) return false;
    return u->noteReturn(bookId);
}
