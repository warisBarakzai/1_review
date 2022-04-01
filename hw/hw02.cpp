#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Warrior;
void read_line(const string& line, vector<Warrior>& warriors);
void evaluate(const vector<string>& split, vector<Warrior>& warriors);

int main() {
    ifstream warriors_file("warriors.txt");
    if(!warriors_file) {
        cerr << "File failed to open" << endl;
        exit(1);
    }
    string line;
    vector<Warrior> warriors;
    while(getline(warriors_file, line)) {
        read_line(line, warriors);
    }
}

struct Warrior {
    string name;
    int strength;
};

void read_line(const string& line, vector<Warrior>& warriors) {
    string token = "";
    vector<string> split;
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
}

void evaluate(const vector<string>& split, vector<Warrior>& warriors) {
    string function = split[0];
    if(function == "Warrior") {
        string name = split[1];
        int strength = stoi(split[2]);
        Warrior w;
        w.name = name;
        w.strength = strength;
        warriors.push_back(w);
    } else if (function == "Battle") {
        string name1 = split[1];
        string name2 = split[2];
        Warrior w1;
        Warrior w2;
        int w1i;
        int w2i;
        for(size_t i = 0; i < warriors.size(); ++i) {
            if(warriors[i].name == name1) {
                w1 = warriors[i];
                w1i = i;
            } else if(warriors[i].name == name2) {
                w2 = warriors[i];
                w2i = i;
            }
            if (w1.name == name1 && w2.name == name2) {
                cout << w1.name << " battles " << w2.name << endl;
                if(w1.strength == 0 && w2.strength == 0) {
                    cout << "Oh, NO! They're both dead! Yuck!" << endl; 
                } else if (w2.strength == 0) {
                    cout << "He's dead, " << w1.name << endl;
                } else if (w1.strength == 0) {
                    cout << "He's dead, " << w2.name << endl;
                } else {
                    int s1 = w1.strength;
                    int s2 = w2.strength;
                    if (s1 > s2) {
                        cout << w1.name << " defeats " << w2.name << endl;
                        int rem = s1 - s2;
                        w1.strength = rem;
                        w2.strength = 0;
                    } else if (s2 > s1) {
                        cout << w2.name << " defeats " << w1.name << endl;
                        int rem = s2 - s1;
                        w2.strength = rem;
                        w1.strength = 0;
                    } else {
                        cout << "Mutual Annihilation: " << w1.name << " and " << w2.name << " die at each other's hands" << endl;
                        w1.strength = 0;
                        w2.strength = 0;
                    }
                }
                warriors[w1i] = w1;
                warriors[w2i] = w2;
                break;
            }
        }
    } else if (function == "Status") {
        cout << "There are: " << warriors.size() << " warriors" << endl;
        for (Warrior& warrior : warriors) {
            cout << "Warrior: " << warrior.name << ", strength: " << warrior.strength << endl;
        }
    }        
}