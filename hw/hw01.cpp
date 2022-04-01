#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

char decrypt(const char& encrypted, int rotation);
void decrypt_string(string& str, int rotation);

int main() {
    ifstream encrypted_file("encrypted.txt");
    if (!encrypted_file) {
        cerr << "Error opening file" << endl;
        exit(1);
    } 
    string line;
    getline(encrypted_file, line);
    int rotation = stoi(line);
    vector<string> decrypted_lines;
    while (getline(encrypted_file, line)) {
        decrypt_string(line, rotation);
        decrypted_lines.push_back(line);
    }
    for (int i = decrypted_lines.size() - 1; i > -1; --i) {
        cout << decrypted_lines[i] << endl;
    }
    encrypted_file.close();
    return 0;
}

char decrypt(const char& encrypted, int rotation) {
    char decrypted = encrypted;
    if(encrypted < 'a' || encrypted > 'z') {
        return decrypted;
    }
    decrypted -= rotation;
    if (decrypted < 'a') { 
        decrypted += 26;
    }
    return decrypted;
}

void decrypt_string(string& str, int rotation) {
    for(int i = 0; i < str.size(); ++i) {
        str[i] = decrypt(str[i], rotation);
    }
}