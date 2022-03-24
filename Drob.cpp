//
// Created by Egor Salkov on 25.06.2020.
//

#include "Drob.h"

Drob::Drob(int a, int b) {
    int k = NOD(a, b);
    a /= k;
    b /= k;
    chis = a;
    znam = b;
    if (znam == 0)
        throw Incompetible_Denominator();

}

int Drob::NOD(int a, int b) {
    while (a > 0 && b > 0)
        if (a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}

void Drob::SetDrob(int a, int b) {
    int k = NOD(a, b);
    a /= k;
    b /= k;
    chis = a;
    znam = b;
    if (znam == 0)
        throw Incompetible_Denominator();

}


Drob::Drob(const Drob &other) {
    this->chis = other.chis;
    this->znam = other.znam;
}

Drob Drob::operator+(Drob &other) {
    Drob res(*this);
    if (this->znam != other.znam) {
        res.znam *=  other.znam;
        res.chis = this->chis * other.znam + other.chis * this->znam;
    } else {
        res.znam = other.znam;
        res.chis += other.chis ;
    }
    int k = NOD(res.chis, res.znam);
    res.znam /= k;
    res.chis /= k;
    return res;
}

Drob Drob::operator-(Drob &other) {
    Drob res(*this);
    if (this->znam != other.znam) {
        res.znam = this->znam * other.znam;
        res.chis = this->chis * other.znam - other.chis * this->znam;
    } else {
        res.znam = other.znam;
        res.chis = this->chis - other.chis;
    }
    int k = NOD(res.chis, res.znam);
    res.znam /= k;
    res.chis /= k;

    return res;
}

Drob &Drob::operator/(Drob &other) {
    Drob res(*this);
    res.chis = this->chis * other.znam;
    res.znam = this->znam * other.chis;
    int k = NOD(res.chis, res.znam);
    res.znam /= k;
    res.chis /= k;

    return res;
}

Drob &Drob::operator*(Drob &other) {
    Drob res(*this);
    res.chis *= other.chis;
    res.znam *= other.znam;
    int k = NOD(res.chis, res.znam);
    res.znam /= k;
    res.chis /= k;

    return res;
}

Drob &Drob::operator-() {
    Drob res(*this);
    res.chis *= -1;
    return res;
}

Drob &Drob::operator+() {
    return *this;
}

std::istream &operator>>(std::istream &in, Drob &fr) {
    in >> fr.chis;
    in >> fr.znam;
    return in;
}

std::ostream &operator<<(std::ostream &out, Drob &fr) {
    out << fr.chis << "/" << fr.znam;
    return out;

}
