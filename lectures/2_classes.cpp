#include <iostream>

using namespace std;

// writing a minimal class -- simplest

class Simplest {}; //needs a semi-colon. Simplest object, uses only default constructor

int main_simplest() {
    Simplest x;
    return 0;
}

// public interface 
// member functions

class Simple {
    public:
        void display() {
            cout << "Display" << endl;
        }   

};

int main_member_function() {
    Simple simpleton;
    simpleton.display();
    return 0;
}

// member variables

class Vorlon {
    public:
        void display() {cout << "a vorlon named: " << myName << endl; }
        string myName;
};

int main_member_variable() {
    Vorlon v1;
    v1.myName = "Kosh";
    v1.display();
    return 0;
}

// private members

class Sorlon {
    public:
        Sorlon(const string& aName) {myName = aName;}
        void display() {cout << "a sorlon named: " << myName << endl; }
    private:
        string myName;
};

int main_private_member() {
    Sorlon s1("Kosh");
    s1.display();
    return 0;
}

// Initialization List
// do better than Sorlon -- setting name after initializing the empty string

class Dorlon {
    public:
        // initialization list -- don't create empty string then update it, rather initialize the object with the string you're passing in
        Dorlon(const string& aName) : myName(aName) {}
        void display() {cout << "a dorlon named: " << myName << endl; }
    private:
        // Can only initialize, can not assign it at any other point in time
        const string myName;
};

// The Default Constructor
int main_constructor() {
    Vorlon v1; // this does compile
    // Dorlon d1; // relies on default constructor -- doesn't take any arguments -- this doesn't compile bc dorlon has a constructor
    // every object gets provided the default constructor so long as you don't create one 
    // we did here, so this doesn't compile
    // Default constructor initializes the class's member variable -- EXCEPT -- built-in types (int, char, double) & member variables that are pointers
    // we can specify how the others (such as string or other defined classes) can be initialized, otherwise they get initialized by their default constructors
}

// Copy constructors

// WHEN does a copy get made / WHEN is the copy constructor called

void someFunc(Dorlon d) {} // uses the copy constructor -- pass by value
Dorlon anotherFunc() { // returns a Dorlon by value -- each time the function returns, we call the copy constructor to initialize the copy of the item being returned
    Dorlon a("zoop");
    return a;
}

int main_copy_constructor() {
    Dorlon d1("Kosh");
    Dorlon d3(d1);
    Dorlon d4 = d1;
    // both use the copy constructor
    return 0;
}
