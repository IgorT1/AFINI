#include <iostream>
#include <string>

using namespace std;

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

string affineDecrypt(string ciphertext, int a, int b) {
    string plaintext = "";
    int a_inv = modInverse(a, 26);
    for (char c : ciphertext) {
        if (c >= 'a' && c <= 'z') {  
            int x = (a_inv * (c - 'a' - b + 26)) % 26; 
            plaintext += (char)(x + 'a');
        }
        else {
            tolower(c); 
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    setlocale(LC_ALL, "ru");
    string ciphertext = "jzq kuudncrejqg ut jzq jedwai jus tumd qlqpqr";
    string target = "target";

    for (int a = 3; a < 5; a++) { // êëþ÷è ïîë áàéêà (4)
        int a_inv = modInverse(a, 26);
        for (int b = 3; b < 5; b++) {//òàêæå 
            string plaintext = affineDecrypt(ciphertext, a, b);
            cout << "ключи : a = " << a << ", b = " << b << endl;
            cout << "результат: " << plaintext << endl;

        }
    }

    return 0;
}