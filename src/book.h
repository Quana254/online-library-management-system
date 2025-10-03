#pragma once
#include <string>
#include <utility>
#include <optional>

class Book {
private:
    int id_;
    std::string title_;
    std::string author_;
    std::string genre_;
    int year_{};
    bool available_{true};
    std::optional<int> borrowerId_; // which user has it

public:
    Book(int id, std::string title, std::string author,
         std::string genre = "", int year = 0);

    // Getters
    int id() const;
    const std::string& title() const;
    const std::string& author() const;
    const std::string& genre() const;
    int year() const;
    bool available() const;
    std::optional<int> borrowerId() const;

    // State transitions
    bool borrow(int userId);  // false if already borrowed
    bool giveBack();          // false if already available
};
