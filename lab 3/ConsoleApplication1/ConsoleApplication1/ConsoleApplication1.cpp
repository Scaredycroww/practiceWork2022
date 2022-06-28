#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>

using namespace std;

class MYstring
{
protected:
    char* Str;
    int Length;
public:
    MYstring();
    MYstring(const char* ptr);
    MYstring(const MYstring& t);
    MYstring& operator = (MYstring& t);
    MYstring& operator += (const MYstring& t);
    void clear();
    bool operator == (const MYstring& t) const;
    bool operator != (const MYstring& t) const;
    bool is_empty() const;
    const char* getStr() const;
    int getLength() const;

    ostream& show(ostream& os) const;
    friend ostream& operator << (ostream& os, const MYstring& s)
    {
        return s.show(os);
    }

    ~MYstring();
};

//////////////////////////////////////////////////////////////////////////////////


MYstring::MYstring()
{
    Str = 0;
    Length = 0;
}

MYstring::MYstring(const char* ptr)
    : Str(new char[strlen(ptr) + 1]), Length(strlen(ptr) + 1)
{
    strcpy(Str, ptr);
}

MYstring::MYstring(const MYstring& t)
    : Str(new char[t.Length]), Length(t.Length)
{
    strcpy(Str, t.Str);
}

MYstring& MYstring::operator = (MYstring& t)
{
    this->Length = t.Length;
    Str = new char[Length];
    strcpy(Str, t.Str);
    return *this;
}

MYstring& MYstring::operator += (const MYstring& t)
{
    int newLength = Length + t.Length;
    char* newStr = new char[newLength + 1];
    strcpy(newStr, Str);
    strcat(newStr, t.Str);
    delete[] Str;
    Str = newStr;
    newStr = nullptr;
    Length = newLength;
    return *this;
}

void MYstring::clear()
{
    this->Length = 0;
    delete[] this->Str;
    this->Str = nullptr;
}

bool MYstring::operator == (const MYstring& t) const
{
    return Length == t.Length && strcmp(Str, t.Str) == 0;
}

bool MYstring::operator != (const MYstring& t) const
{
    return !(operator == (t));
}

bool MYstring::is_empty() const
{
    return Str == 0 || Str[0] == '\0';
}

const char* MYstring::getStr() const
{
    return Str;
}

int MYstring::getLength() const
{
    return Length;
}

ostream& MYstring::show(ostream& os) const
{
    return os << "\"" << (Str ? Str : "") << "\"";
}

MYstring::~MYstring()
{
    Length = 0;
    delete[] Str;
    Str = 0;
}

//////////////////////////////////////////////////////////////////////////////////

class Password : public MYstring
{
public:
    Password() {}
    Password(const char* ptr) :MYstring(ptr) {}
    Password(const MYstring* t) : MYstring(*t) {}
    ~Password() {}

    friend ostream& operator << (ostream& os, const Password& s)
    {
        for (size_t i = 0; i < s.Length; i++)
        {
            os << "*";
        }
        return os;
    }

private:

};


//////////////////////////////////////////////////////////////////////////////////

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MYstring s("0 1 2 3 4 5 6 7 8 9 A B C D E F");
    Password f("Qwertyy");
    cout << s << endl;
    cout << (s == f) << endl;
    s += f;
    cout << s << endl;
    cout << f << endl;

    system("pause");
    return 0;
}
