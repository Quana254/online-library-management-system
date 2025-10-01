#pragma once
#include <string>
#include <utility>

class Book {
    int id_;
    std::string title_;
    std::string author_;
    std::string genre_;
    int year_{};
    bool available_{true};
public:
    Book(int id, std::string title, std::string author,
         std::string genre = "", int year = 0)
        : id_(id),
          title_(std::move(title)),
          author_(std::move(author)),
          genre_(std::move(genre)),
          year_(year),
          available_(true) {}

    // Getters (encapsulation)
    int id() const { return id_; }
    const std::string& title() const { return title_; }
    const std::string& author() const { return author_; }
    const std::string& genre() const { return genre_; }
    int year() const { return year_; }
    bool available() const { return available_; }

    // State transitions
    bool borrow() {
        if (!available_) return false;
        available_ = false; return true;
    }
    void giveBack() { available_ = true; }
};
