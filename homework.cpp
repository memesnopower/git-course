#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cstring>

using namespace std;

// есть маска которая генерируется с помощью программироваемого рандома где нужен ключ

void encryption(int key, char *words) {
    for (int i = 0; i < strlen(words); i++) {
        words[i] ^= key;
    }
    cout << "Encryption message: " << words;
}

void decryption(int key, char *words) {
    for (int i = 0; i < strlen(words); i++) {
        words[i] ^= key;
    }
    cout << "Decryption message: " << words;

}
/*
int shift_left(int left, int bytes = 4) {


}
*/

int main(int argc, char *argv[]) {
/*
    if (argc != 3) {
        cerr << "Use three parameters!";

        return 5;
    }
*/
    const string MODE = argv[1];
    const string FILE_NAME = argv[2];


/*
    if (FILE_NAME.is_open() == false) {
        cerr << "Program can not open file";
        return -1;
    }
*/

    if (MODE == "encryption") {
        encryption(50, "dsnnddn");
    } else if (MODE == "decryption") {
            //decryption();
    } else {
        cerr << "Use encryption or decryption only!";
        return 5;
    }

    return 0;
}
