#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Warrior;
void read_line(const string& line);
void evaluate(const vector<string>& split, vector<Warrior>& warriors);

int main() {
    ifstream warriors_file("warriors.txt");
    if(!warriors_file) {
        cerr << "File failed to open" << endl;
        exit(1);
    }
    string line;
    while(getline(warriors_file, line)) {
        read_line(line);
    }
}

class Warrior {
    private: 
        string name;
        int strength;
    public:
        Warrior(const string& name, int strength) : name(name), strength(strength) {}
        void setStrength(int strength) {
            this->strength = strength;
        }
        const string& getName() {
            return this->name;
        }
        const int getStrength() {
            return this->strength;
        }
};

void read_line(const string& line) {
    string token = "";
    vector<string> split;
    vector<Warrior> warriors;
    for(size_t i = 0; i < line.size(); ++i) {
        if(line[i] == ' ') {
            split.push_back(token);
            token = "";
        } else {
            token += line[i];
        }
        if(i == line.size() - 1) {
            split.push_back(token);
            token = "";
        }
    }
    evaluate(split, warriors);
    // for(const string& token : split) {
    //     cout << token <<  ' ';
    // }
    // cout << endl;
}

void evaluate(const vector<string>& split, vector<Warrior>& warriors) {
    string function = split[0];
    if(function == "Warrior") {
        string name = split[1];
        int strength = stoi(split[2]);
        warriors.push_back(Warrior(name, strength));
    } else if (function == "Battle") {
        string name1 = split[1];
        string name2 = split[2];
        Warrior* w1;
        Warrior* w2;
        for(Warrior& warrior : warriors)
            if(warrior.getName() == name1) {
                w1 = &warrior;
            } else if(warrior.getName() == name2) {
                w2 = &warrior;
            }
        } 
        if(w1 == NULL && w2 == NULL) {
            int s1 = w1->getStrength();
            int s2 = w2->getStrength();
            if (s1 > s2) {
                
            }
        }
        
}