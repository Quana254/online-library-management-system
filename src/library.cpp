#include "Library.h"
#include <algorithm>

static bool containsIC(const std::string& hay, const std::string& needle) {
    auto toLower = [](std::string s){ for (auto& c : s) c = (char)tolower(c); return s; };
    auto H = toLower(hay), N = toLower(needle);
    return H.find(N) != std::string::npos;
}

// ---- Books ----
Status Library::addBook(const Book& b) {
    if (books_.count(b.id())) return Status::AlreadyExists;
    books_.emplace(b.id(), b);
    return Status::Ok;
}

Status Library::removeBook(int bookId) {
    if (!books_.count(bookId)) return Status::NotFound;
    // Optional rule: disallow removing borrowed books
    if (!books_.at(bookId).available()) return Status::InvalidOperation;
    books_.erase(bookId);
    return Status::Ok;
}

std::optional<Book> Library::getBook(int bookId) const {
    auto it = books_.find(bookId);
    if (it == books_.end()) return std::nullopt;
    return it->second;
}

std::vector<Book> Library::searchByTitle(const std::string& q) const {
    std::vector<Book> out;
    for (const auto& [_, b] : books_) if (containsIC(b.title(), q)) out.push_back(b);
    return out;
}
std::vector<Book> Library::searchByAuthor(const std::string& q) const {
    std::vector<Book> out;
    for (const auto& [_, b] : books_) if (containsIC(b.author(), q)) out.push_back(b);
    return out;
}
std::vector<Book> Library::searchByGenre(const std::string& q) const {
    std::vector<Book> out;
    for (const auto& [_, b] : books_) if (containsIC(b.genre(), q)) out.push_back(b);
    return out;
}

// ---- Users ----
Status Library::addUser(const User& u) {
    if (users_.count(u.id())) return Status::AlreadyExists;
    users_.emplace(u.id(), u);
    return Status::Ok;
}

std::optional<User> Library::getUser(int userId) const {
    auto it = users_.find(userId);
    if (it == users_.end()) return std::nullopt;
    return it->second;
}

// ---- Borrow / Return ----
Status Library::borrowBook(int userId, int bookId) {
    auto bu = users_.find(userId);
    if (bu == users_.end()) return Status::NotFound;
    auto bb = books_.find(bookId);
    if (bb == books_.end()) return Status::NotFound;

    User& u = bu->second;
    Book& b = bb->second;

    if (!b.available()) return Status::NotAvailable;
    if (!u.canBorrow()) return Status::UserLimitReached;

    if (!b.borrow()) return Status::NotAvailable;
    u.noteBorrow(bookId);
    return Status::Ok;
}

Status Library::returnBook(int userId, int bookId) {
    auto bu = users_.find(userId);
    if (bu == users_.end()) return Status::NotFound;
    auto bb = books_.find(bookId);
    if (bb == books_.end()) return Status::NotFound;

    User& u = bu->second;
    Book& b = bb->second;

    if (!u.hasBorrowed(bookId)) return Status::InvalidOperation;

    b.giveBack();
    u.noteReturn(bookId);
    return Status::Ok;
}
