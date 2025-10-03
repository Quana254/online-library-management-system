// src/book.cpp
#include "book.h"
#include <utility>

Book::Book(int id, std::string title, std::string author,
           std::string genre, int year)
    : id_(id),
      title_(std::move(title)),
      author_(std::move(author)),
      genre_(std::move(genre)),
      year_(year),
      available_(true) {}

int Book::id() const { return id_; }
const std::string& Book::title() const { return title_; }
const std::string& Book::author() const { return author_; }
const std::string& Book::genre() const { return genre_; }
int Book::year() const { return year_; }
bool Book::available() const { return available_; }

bool Book::borrow() {
    if (!available_) return false;
    available_ = false;
    return true;
}

void Book::giveBack() {
    available_ = true;
}
