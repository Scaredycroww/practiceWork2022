#include <iostream>
#include <conio.h>
#include <string>
#include "windows.h"

using namespace std;

class clas
{
public:
    clas();
    clas(int a);
    ~clas() { delete mass; }
    void g_mass(int[]);
    int* p_mass() { return mass; }
    int p_mass(int a) { return mass[a]; }
    int p_temp();


    clas operator + (const clas&);
    clas operator - (const clas&);
    clas operator * (const clas&);
    clas& operator = (const clas&);

private:
    int* mass;
};


clas::clas(int a)
{
    mass = new int[a];
};

void clas::g_mass(int  mas[])
{
    for (int i = 0; mas[i] != '\0'; i++)
        mass[i] = mas[i];
};


clas clas::operator + (const clas& v)
{
    cout << "\nПо елементне додавання масивів:";
    for (int i = 0; v.mass[i] != '\0'; i++) {
        v.mass[i] += p_mass(i);
        cout << " " << v.mass[i];
    }
    cout << "\n";
    return v;
};

clas clas::operator - (const clas& v)
{
    cout << "\nПо елементне віднімання масивів:";
    for (int i = 0; v.mass[i] != '\0'; i++) {
        v.mass[i] -= p_mass(i);
        cout << " " << v.mass[i];
    }
    cout << "\n";
    return v;
};

clas clas::operator * (const clas& v)
{
    cout << "\nПо елементне множення масивів:";
    for (int i = 0; v.mass[i] != '\0'; i++) {
        v.mass[i] *= p_mass(i);
        cout << " " << v.mass[i];
    }
    cout << "\n";
    return v;
};

clas& clas::operator =(const clas& temp)
{
    cout << "\nДинамічне присвоєння:";
    if (this == &temp)
        return *this;
    cout << mass << endl;
    cout << "\n";
    return *this;
};

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    clas A(5), B(5), C(5), D(5), E(5), F(5);
    int a[5], b[5];

    cout << "Масив А:";
    for (int i = 0; i < 5; i++) {
        a[i] = 1 + rand() % 10;
        cout << " " << a[i];
    }

    cout << "\n";

    cout << "Масив B:";
    for (int i = 0; i < 5; i++) {
        b[i] = 1 + rand() % 10;
        cout << " " << b[i];
    }

    A.g_mass(a);
    B.g_mass(b);
    C.g_mass(a);
    D.g_mass(b);
    E.g_mass(a);
    F.g_mass(b);

    A + B;

    D - C;

    F* E;

    B = A;




    system("pause");
    return 0;
}