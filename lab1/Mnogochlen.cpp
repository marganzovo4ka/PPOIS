#include "Mnogochlen.h"

using namespace std;

Mnogochlen Mnogochlen :: operator*(const Odnochlen* a) {
    Mnogochlen copy(*this);
    Odnochlen* od = copy.head;
    while (od != NULL) {
        od->coef *= a->coef;
        od->power += a->power;
        od = od->next;
    }
    return copy;
}

Mnogochlen& Mnogochlen ::operator*=(const Odnochlen* a) {
    Odnochlen* od = this->head;
    while (od != NULL) {
        od->coef *= a->coef;
        od->power += a->power;
        od = od->next;
    }
    return *this;
}

Mnogochlen& Mnogochlen ::operator += (const Odnochlen* a) {
    (*this).Add_elem(a);
    return *this;
}

Mnogochlen::Odnochlen* Mnogochlen::Get_Elem(double coef, int el_power) {
    Odnochlen* elem = new Odnochlen;
    elem->coef = coef;
    elem->power = el_power;
    return elem;
}

Mnogochlen Mnogochlen::operator-() const
{
    Odnochlen* od = this->head;
    while (od != NULL)
    {
        od->coef = -od->coef;
        od = od->next;
    }
    return *this;
}

void Mnogochlen::Del_spis() {
    Odnochlen* od = this->head;
    while (this->head != NULL) {
        od = this->head;
        this->head = (this->head)->next;
        delete od;
    }
}

void Mnogochlen::Del_elem(Odnochlen* elem) {
    if (elem == this->head) {
        if (elem->next != NULL) {
            head = elem->next;
            head->prev = NULL;
            delete elem;
        }
        else {
            head->prev = NULL;
            delete elem;
            head = end = NULL;
        }
    }
    else if (elem == this->end) {
        if (elem->prev != NULL)
            end = elem->prev;
        end->next = NULL;
        delete elem;
    }
    else {
        Odnochlen* od = elem->prev;
        od->next = elem->next;
        elem->next->prev = od;
        delete elem;
    }
}

bool Mnogochlen::Add_elem1(const Odnochlen* elem)
{
    Odnochlen* od = this->head;
    while (od != NULL && od->power > elem->power && od != end)
        od = od->next;
    if (od == NULL) {
        Odnochlen* c = Get_Elem(elem->coef, elem->power);
        end = head = c;
        c->next = c->prev = NULL;
        return 1;
    }
    if (od->power == elem->power) {
        od->coef += elem->coef;
        if (od->coef == 0)
            Del_elem(od);
        return 1;
    }
    return false;
}



void Mnogochlen::Add_elem2(const Odnochlen* elem)
{
    Odnochlen* od = this->head;
    while (od != NULL && od->power > elem->power && od != end)
        od = od->next;
    Odnochlen* c = Get_Elem(elem->coef, elem->power);
    if (od == end && c->power < end->power) {
        c->prev = end;
        end->next = c;
        c->next = NULL;
        end = c;
        return;
    }
    if (od == head) {
        c->next = head;
        head->prev = c;
        c->prev = NULL;
        head = c;
    }
    else {
        od->prev->next = c;
        c->prev = od->prev;
        c->next = od;
        od->prev = c;
    }
    return;
}

void Mnogochlen::Add_elem(const Odnochlen* elem) {
    if (Add_elem1(elem))
        return;
    Add_elem2(elem);
}

bool Mnogochlen::Deduct_elem1(Odnochlen* elem) {
    Odnochlen* od = this->head;
    while (od->power > elem->power && od != end)
        od = od->next;
    if (od->power == elem->power) {
        od->coef -= elem->coef;
        if (od->coef == 0)
            Del_elem(od);
        return 1;
    }
    return false;
}

void Mnogochlen::Deduct_elem2(Odnochlen* elem) {
    Odnochlen* od = this->head;
    while (od->power > elem->power && od != end)
        od = od->next;
    Odnochlen* c = Get_Elem(-(elem->coef), elem->power);
    if (od == end && c->power < end->power) {
        c->prev = end;
        end->next = c;
        c->next = NULL;
        end = c;
        return;
    }
    if (od == head && c->power > head->power) {
        c->next = head;
        head->prev = c;
        c->prev = NULL;
        head = c;
    }
    else {
        od->prev->next = c;
        c->prev = od->prev;
        c->next = od;
        od->prev = c;
    }
}

void Mnogochlen::Deduct_elem(Odnochlen* elem) {
    if (Deduct_elem1(elem))
        return;
    Deduct_elem2(elem);
}

Mnogochlen::Odnochlen* Mnogochlen::Get_mnozhitel(Odnochlen* bigger, Odnochlen* less) {
    double coef = bigger->coef / less->coef;
    int power = bigger->power - less->power;
    Odnochlen* result = Get_Elem(coef, power);
    return result;
}


Mnogochlen::Mnogochlen() {
    this->head = this->end = NULL;
}

Mnogochlen::Mnogochlen(int power, double* arr) {     //���������� �������� ���������(������������ �������)
    this->head = this->end = NULL;
    for (int i = power; i >= 0; i--) {
        double coef;
        int el_power = power - i;
        coef = arr[i];
        if (coef == 0)
            continue;
        Odnochlen* elem = Get_Elem(coef, el_power);
        if (head == NULL) {
            elem->next = elem->prev = NULL;
            this->head = this->end = elem;
        }
        else {
            elem->next = head;
            this->head->prev = elem;
            elem->prev = NULL;
            this->head = elem;
        }
    }
}

Mnogochlen::Mnogochlen(const Mnogochlen& other) {
    Odnochlen* buf = other.head;
    this->head = this->end = NULL;
    while (buf != NULL) {
        Odnochlen* elem = Get_Elem(buf->coef, buf->power);
        if (this->end == NULL) {
            this->end = this->head = elem;
            elem->next = elem->prev = NULL;
        }
        else {
            elem->prev = this->end;
            this->end->next = elem;
            elem->next = NULL;
            this->end = elem;
        }
        buf = buf->next;
    }
}

Mnogochlen::~Mnogochlen() {
    Del_spis();
}


void Mnogochlen::View() {
    Odnochlen* od = head;
    while (od != NULL) {
        if (od->power == 0) {
            if (od->coef < 0)
                cout << od->coef;
            else
                cout << "+" << od->coef;
            od = od->next;
        }
        else {
            if (od->coef < 0)
                cout << od->coef << "x^" << od->power;
            else
                cout << "+" << od->coef << "x^" << od->power;
            od = od->next;
        }
    }
    cout << endl;
}

string Mnogochlen::ToString()
{
    std::stringstream s;
    Odnochlen* od = this->head;
    while (od->next != NULL) {
        s << od->coef << " ";
        od = od->next;
    }
    s << od->coef;
    return s.str();
}

Mnogochlen Mnogochlen::operator + (const Mnogochlen& a) {
    if (this->head == NULL) {
        return a;
    }
    if (a.head == NULL) {
        return *this;
    }
    Mnogochlen copy(a);
    Odnochlen* od = this->head;
    while (od != NULL) {
        copy.Add_elem(od);
        od = od->next;
    }
    return copy;
}

Mnogochlen& Mnogochlen::operator = (const Mnogochlen& other) {
    if (this->head != NULL) {
        Del_spis();
        this->end = this->head = NULL;
    }
    Odnochlen* buf = other.head;
    while (buf != NULL) {
        Odnochlen* elem = Get_Elem(buf->coef, buf->power);
        if (this->end == NULL) {
            this->end = this->head = elem;
            elem->next = elem->prev = NULL;
        }
        else {
            elem->prev = this->end;
            this->end->next = elem;
            elem->next = NULL;
            this->end = elem;
        }
        buf = buf->next;
    }
    return *this;
}

Mnogochlen Mnogochlen::operator - (const Mnogochlen& a) {
    if (a.head == NULL) {
        return *this;
    }
    if (this->head == NULL) {
        Mnogochlen copy(a);
        return -copy;
    }
    Mnogochlen copy(*this);
    Odnochlen* od = a.head;
    while (od != NULL) {
        copy.Deduct_elem(od);
        od = od->next;
    }
    return copy;
}

Mnogochlen& Mnogochlen::operator += (const Mnogochlen& a) {
    if (this->head == NULL) {
        *this = a;
    }
    else if (a.head != NULL) {
        Odnochlen* od = a.head;
        while (od != NULL) {
            (*this).Add_elem(od);
            od = od->next;
        }
    }
    return *this;
}

Mnogochlen& Mnogochlen::operator -= (const Mnogochlen& a) {
    if (this->head == NULL) {
        *this = -a;
    }
    else if (a.head != NULL) {
        Odnochlen* od = a.head;
        while (od != NULL) {
            (*this).Deduct_elem(od);
            od = od->next;
        }
    }
    return *this;
}

Mnogochlen Mnogochlen::operator * (const Mnogochlen& a) {
    if (a.head == NULL)
        return a;
    if (this->head == NULL)
        return *this;
    Mnogochlen copy(a);
    Odnochlen* od = this->head;
    Mnogochlen buf;
    while (od != NULL) {
        if (buf.head == NULL)
            buf = copy * od;
        else
            buf += copy * od;
        od = od->next;
    }
    return buf;
}

Mnogochlen& Mnogochlen::operator *= (const Mnogochlen& a) {
    if (a.head == NULL)
        *this = a;
    else if (this->head != NULL) {
        Odnochlen* od = a.head;
        Mnogochlen copy(*this);
        while (od != NULL) {
            if (od == a.head)
                *this *= od;
            else
                *this += (copy * od);
            od = od->next;
        }
    }
    return *this;
}

Mnogochlen Mnogochlen::operator / (const Mnogochlen& a) {
    if (this->head == NULL)
        return *this;
    Mnogochlen result, copy1(*this), copy2(a);
    Odnochlen* od = copy1.head;
    while (od->power >= a.head->power && od != NULL) {
        Odnochlen* mnozhitel = Get_mnozhitel(od, a.head);
        result += mnozhitel;
        copy1 -= (copy2 * mnozhitel);
        od = copy1.head;
    }
    return result;
}

double Mnogochlen::operator () (const double a) {
    double result = 0;
    Odnochlen* od = this->head;
    while (od != NULL) {
        result += pow(a, od->power) * od->coef;
        od = od->next;
    }
    return result;
}

double Mnogochlen::operator[] (const int power) {
    Odnochlen* od = this->head;
    while (od != NULL && od->power > power)
        od = od->next;
    if (od->power < power || od == NULL)
        return 0;
    else
        return  od->coef;
}
