#include <iostream>
#include <string>

using namespace std;

class person
{
private:
    string _FIO;
    string _adress;
    int _year = 0;
    string _phone;
    double _height;
    double _weight;
    string _sex;
public:
    person();
    void input();
    void show();
    friend int GetMen(person* people, int amount);
    friend int GetWomen(person* people, int amount);
};

int GetMen(person* people, int amount)
{
    int count = 0;
    for (int i = 0; i < amount; i++)
        if (people[i]._sex == "m") count++;
    return count;
}

int GetWomen(person* people, int amount)
{
    int count = 0;
    for (int i = 0; i < amount; i++)
        if (people[i]._sex == "w") count++;
    return count;
}

person::person()
{
    _FIO = "";
    _adress = "";
    _year = 0;
    _phone = "";
    _height = 0.0;
    _weight = 0.0;
    _sex = "";
}

void person::input()
{
    cout << "PIB: ";
    getline(cin, this->_FIO);
    cout << "Adress: ";
    getline(cin, this->_adress);
    cout << "Year of birth: ";
    cin >> this->_year;
    cin.ignore();
    cout << "Phone number: ";
    getline(cin, this->_phone);
    cout << "Height: ";
    cin >> this->_height;
    cin.ignore();
    cout << "Weight: ";
    cin >> this->_weight;
    cin.ignore();
    cout << "Sex  (w/m)  : ";
    getline(cin, this->_sex);
    cout << endl;
}
void person::show()
{
    cout << "FIO: " << this->_FIO << endl;
    cout << "Adress: " << this->_adress << endl;
    cout << "Year of birth: " << this->_year << endl;
    cout << "Phone number: " << this->_phone << endl;
    cout << "Height: " << this->_height << endl;
    cout << "Weight: " << this->_weight << endl;
    cout << "Sex: " << this->_sex << endl;
    cout << endl;
}

int main()
{
    cout << "Amount of people: ";
    int amount;
    cin >> amount;
    cin.ignore();
    person* people = new person[amount];
    for (int i = 0; i < amount; i++)
        people[i].input();
    for (int i = 0; i < amount; i++)
        people[i].show();
    cout << "Men: " << GetMen(people, amount) << endl;
    cout << "Women: " << GetWomen(people, amount) << endl;
    delete[]people;
    system("pause");
    return 0;
}