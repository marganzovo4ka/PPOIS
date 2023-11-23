#pragma once
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class Mnogochlen {

    class Odnochlen {
    public:
        double coef;
        int power;
        Odnochlen* next;
        Odnochlen* prev;
    };

    Odnochlen* head;
    Odnochlen* end;

    Mnogochlen operator*(const Odnochlen* a);

    Mnogochlen& operator*=(const Odnochlen* a);

    Mnogochlen& operator += (const Odnochlen* a);

    Odnochlen* Get_Elem(double coef, int el_power);

    Mnogochlen operator - () const;

    void Del_spis();

    void Del_elem(Odnochlen* elem);

    bool Add_elem1(const Odnochlen* elem);

    void Add_elem2(const Odnochlen* elem);
    
    void Add_elem(const Odnochlen* elem);

    bool Deduct_elem1(Odnochlen* elem);

    void Deduct_elem2(Odnochlen* elem);

    void Deduct_elem(Odnochlen* elem);

    Odnochlen* Get_mnozhitel(Odnochlen* bigger, Odnochlen* less);

public:

    Mnogochlen();

    Mnogochlen(int power, double *arr);

    Mnogochlen(const Mnogochlen& other);

    ~Mnogochlen();

    void View();

    string ToString();

    Mnogochlen operator + (const Mnogochlen& a);

    Mnogochlen& operator = (const Mnogochlen& other);

    Mnogochlen operator - (const Mnogochlen& a);
    
    Mnogochlen& operator += (const Mnogochlen& a);

    Mnogochlen& operator -= (const Mnogochlen& a);
    
    Mnogochlen operator * (const Mnogochlen& a);
    
    Mnogochlen& operator *= (const Mnogochlen& a);

    Mnogochlen operator / (const Mnogochlen& a);

    double operator () (const double a);
    
    double operator[] (const int power);
};