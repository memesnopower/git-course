#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cstddef>
#include <cstring>
#include <bitset>


using namespace std;

// есть маска которая генерируется с помощью программироваемого рандома где нужен ключ

/*void encryption(int key) {

}

void decryption(int key) {



}
*/
/*
int shift_left(int left, int bytes = 4) {

    return

}

int shift_right(int right, int bytes = 4) {

    return
}
*/

int main(int argc, char *argv[]) {

    ifstream file ("D:/text/homework.txt");
    string str;
    getline(file, str);
    file.close();
    int block = str.size() / 4;
    int incomplete_block = str.size() % 4;
    string bits = to_string(block*8)+ to_string(incomplete_block*8);
    int integer_bits = stoi(bits);
    srand(1224);
    char key = 'F';
    int gamma = rand();
    string MODE = "encryption";
    if (MODE == "encryption") {
        ofstream x ("D:/text/homework.txt");
        for (int i = 0; i < str.length(); i++) {
            str[i] ^= key;
            x << str[i];
        }
        x.close();
    } else if (MODE == "decryption") {
        ofstream x ("D:/text/homework.txt");
        for (int i = 0; i < str.length(); i++) {
            str[i] ^= key;
            x << str[i];
        }
        x.close();
    }

/*
    if (argc != 3) {
        cerr << "Use three parameters!";

        return 5;
    }
*/
 //  const string MODE = "encryption";
//    const string FILE_NAME = argv[2];


/*
    if (FILE_NAME.is_open() == false) {
        cerr << "Program can not open file";

        return -1;
    }
*/

 /*   if (MODE == "encryption") {
        //encryption();
    } else if (MODE == "decryption") {
            //decryption();
    } else {
        cerr << "Use encryption or decryption only!";
        return 5;
    }
*/
    return 0;
}
