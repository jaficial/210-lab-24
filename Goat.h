// COMSC-210 | Lab 24 | Jed Aficial 
// github link: https://github.com/jaficial/210-lab-24

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    // default constructor (doesn't take any parameters)
    Goat()                          { name = ""; age = 0; color = ""; }
    // constructor with name as argument
    Goat(string goat_name) {name = goat_name;}
    // constructor with name and age
    Goat(string goat_name, int goat_age) {name = goat_name; age = goat_age;}
    // constructor with name, age, and color
    Goat(string goat_name, int goat_age, string goat_color) {name = goat_name; age = goat_age; color = goat_color;}

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    bool operator< (const Goat &other) const{
        return name < other.name;
    }
};

#endif