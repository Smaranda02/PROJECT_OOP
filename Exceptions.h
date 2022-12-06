//
// Created by smaranda on 11/21/2022.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H
#include <stdexcept>

class eroare_aplicatie : public std::runtime_error {
        using std::runtime_error::runtime_error;
};

class eroare_font : public eroare_aplicatie {
public:
    eroare_font() : eroare_aplicatie("eroare font: Fontul nu s a incarcat corect!") {}
    using eroare_aplicatie::eroare_aplicatie;
};


class eroare_constructor : public eroare_aplicatie{
public:
    using eroare_aplicatie::eroare_aplicatie;
};

#endif //OOP_EXCEPTIONS_H
