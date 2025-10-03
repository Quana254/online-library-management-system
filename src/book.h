#pragma once
#include <string>

class Book {
private:
    int id_;
    std::string title_;
    std::string author_;
    std::string genre_;
    int year_{};
    bool available_{true};

public:
    Book(int id, std::string title, std::string author,
         std::string genre = "", int year = 0);

    // Getters (encapsulation)
    int id() const;
    const std::string& title() const;
    const std::string& author() const;
    const std::string& genre() const;
    int year() const;
    bool available() const;

    // State transitions
    bool borrow();   // returns false if already borrowed
    void giveBack(); // mark available again
};
