//
// Created by Egor Salkov on 25.06.2020.
//

#ifndef EXAM_DROB_H
#define EXAM_DROB_H
#include <iostream>

class Incompetible_Denominator : public std::exception
{
public:
    Incompetible_Denominator() {};
    const char* what()  { return "Denominator cannot be 0!"; };
    ~Incompetible_Denominator() {};
};
class Drob
{
private:
    int chis;
    int znam;
public:
    Drob(int, int);
    Drob() : chis(0), znam(1) {};
    int NOD(int, int);
    void SetDrob(int, int);
    Drob(const Drob&);
    ~Drob() { };
    Drob& operator +(Drob&);
    Drob& operator -(Drob&);
    Drob& operator /(Drob&);
    Drob& operator *(Drob&);
    Drob& operator -();
    Drob& operator +();
    friend std::istream& operator >>(std::istream&, Drob&);
    friend std::ostream& operator <<(std::ostream&, Drob&);
};

#endif //EXAM_DROB_H
