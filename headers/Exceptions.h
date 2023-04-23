#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H
#include <iostream>

class eroare_aplicatie : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class eroare_font : public eroare_aplicatie {
public:
    explicit eroare_font(const std::string& mesaj);
};

class eroare_imagine : public eroare_aplicatie {
public:
    explicit eroare_imagine(const std::string& mesaj);
};

#endif //OOP_EXCEPTIONS_H
