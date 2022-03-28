#include <iostream>
// library to look in for definition of cout and code used for output operator
using namespace std; // saves some typing later on. Would need to do std::cout

int main_1() {
    cout << "Hello World\n"; 
    // cout = output stream but can be redirected someplace else
    // << = output operator
    return 0;
}

#include <string>

int main_2() {
    string name = "world";
    cout << "Hello ";
    cout << name;
    cout << "!\n";
    // better
    cout << "Hello " << name << "!\n";
    return 0;
}

int main_basics() {
    string name;
    cout << "What is your name? ";
    cin >> name;
    cout << "Hello " << name << "!\n";
    // conditionals 
    if (1) {
        cout << "Hello world!\n";
    } else if (2) {
        cout << "Hello world!\n";
    } else {
        cout << "Hello world!\n";
    }
    // logical operators &&, ||
    // looping
    cout << "Starting loop\n";
    // for loop
    // 3 parts - initialization, test increment parts
    for(int i = 0; i < 5; ++i) {
        cout << "Hello world!\n";
    }
    // while loop
    cout << "while loop\n";
    int i = 0;
    while (i < 5) {
        cout << "Hello world!\n";
        ++i;
    }
    // do-while loop
    // definitely want to do something once, and then check the test
    cout << "Do-while loop\n";
    int j = 0;
    do {
        cout << "Hello world!\n";
        ++j;
    } while ( j < 5 );
    return 0;
}

#include <fstream>
// file i/o
int main_3() {
    // open a file
    ifstream ifs("data.txt");
    int x;
    // check if file opened
    if (!ifs) {
        cerr << "Could not open the file.\n";
        exit(1);
    }
    // read from a file
    ifs >> x;
    cout << x << '\n';
    ifs.close();
    return 0;
}

// file i/o 2
int main_4() {
    ifstream ifs("data.txt");
    string line;
    while (getline(ifs, line)) {
        cout << line << endl;
    }
    ifs.close();
    return 0;
}

int main_5() {
    ifstream ifs("data.txt");
    ifs.clear();
    // attempting to read something and couldn't causes some flags to be set. These flags prevent from reading anything else from the file
    // Say wanted to to keep reading in, will need to "clear" those flags
    ifs.seekg(0); // reset the file position to the beginning
    // jump to a location in the file
    return 0;
}

#include <vector>
// vectors
int main_6() {
    vector<int> vecOfInts;
    // cout << vecOfInts[16];
    vecOfInts.push_back(5);
    vecOfInts.push_back(8);
    cout << vecOfInts[0] << ' ' << vecOfInts[1] << endl;
    // looping over a vector
    for (size_t i = 0; i < vecOfInts.size(); ++i) {
        cout << vecOfInts[i] << endl;
    }
    // ranged for
    for (int x : vecOfInts) {
        cout << x << endl;
    }
    // initialize vector, specifying size
    vector<int> vec(28, 17); // initialized to hold 28 17s
    vector<int> vec1(28); // initialized to 28 default values (0)
    // if you specify size of 28, then push_back would push a 29th element
    return 0;
}

int main_7(const vector<int>& aVec) {
    // const = constant
    // vector<int>& means pass by reference
    // otherwise, would be a copy
    // if not changing contents of the vector, then pass it by constant reference (don't waste time and space making a copy of the vector)
    for (size_t i = 0; i < aVec.size(); ++i) {
        cout << aVec[i] << endl;
    }
    // useful vector methods
    // push_back
    // pop_back
    // -- returns nothing, removes last item and decreases size by one
    // size
    // -- returns a size_t
    // clear 
    // -- no arguments, sets the size of the vector to 0
    // back
    // -- no args, returns reference to last element in vector
    return 0;
}

int main_8() {
    // Strings
    // Like vectors
    // can be used as if a vector of characters
    string s = "abc";
    s.push_back('z');
    s = "HAL";
    for(size_t i = 0; i < s.size(); ++i) {
        s[i] = s[i] + 1;
    }
    cout << s << endl;
    // + and +=
    string a  = "The";
    string b  = "Cat";
    cout << a << " " + b << endl;
    a += ' ';
    a += b;
    cout << a << endl;
    // + operator only works with string objects, not literals
    // cout << "The" + " " + "Cat" << endl; would not work
    return 0;
}

// default values
struct Cat {
    string color = "black";
    string name = "Felix";
    double weight = 0;
};

int main() {
    Cat myCat;
    myCat.name = "Felix";
    myCat.color = "grey";
    myCat.weight = 3.14;
    cout << myCat.name << '\t' << myCat.color << '\t' << myCat.weight << endl;
    Cat b;
    b = myCat;
    // test if 2 objects are equal
    // if (b == myCat) {cout << "pew" << endl;} compilation error
    // have to test if fields have the same value, unless implement the == operator for Cats
    // printing an object requires operator overloading
    // vector of structs

}