#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <random>

using namespace std;

int left_shift(int x, int bytes = 4) {
    return (x << 3) | (x >> (bytes*8-3));
}

int right_shift(int x, int bytes = 4) {
    return (x >> 3) | (x << (bytes*8-3));
}
int gamma, gamma2;
void init(){

    srand(12331);
    gamma = rand();


}


void encryption(string &str, string &decrypt) {
    int result = 0;
    int size = 4;
    int incomplete_blocks = str.size() % 4;
    int blocks = str.size() / 4;
    int maska;
    char sentences[str.size() + 1];

    for (int i = 0; i < str.size(); i++) {
        sentences[i] = str[i];
    }

    for (int i = 0; i <= str.size(); i++) {
        if (i < blocks) {
            memcpy(&result, sentences + i * 4, size);

            result = left_shift(result ^ gamma);


            memcpy(sentences + i * 4, &result, size);
        } else {
            memcpy(&result, sentences + i * 4, incomplete_blocks);

            result = left_shift(result, incomplete_blocks);
            result ^= (gamma >> (8 * (4 - incomplete_blocks)));
            memcpy(sentences + i * 4, &result, incomplete_blocks);
        }
    }
    decrypt = sentences;
    cout << decrypt;
}

void decryption(string &decrypt, string &str) {
    int result = 0;
    int size = 4;
    int incomplete_blocks = decrypt.size() % 4;
    int blocks = decrypt.size() / 4;
    int maska;

    char sentences[decrypt.size() + 1];

    for (int i = 0; i < decrypt.size(); i++) {
        sentences[i] = decrypt[i];
    }

    for (int i = 0; i <= decrypt.size(); i++) {
        if (i < blocks) {
            memcpy(&result, sentences + i * 4, size);

            result = right_shift(result);
            result ^= gamma;

            memcpy(sentences + i * 4, &result, size);

        } else {
            memcpy(&result, sentences + i * 4, incomplete_blocks);

            result = right_shift(result, incomplete_blocks);
            result ^= (gamma >> (8 * (4 - incomplete_blocks)));
            memcpy(sentences + i * 4, &result, incomplete_blocks);

        }
    }
    str = sentences;
    cout << str;
}

int main(int argv, char *argc[]) {
    init();
    /*
    if (argv != 3) {
        cerr << "Use three parameters!";

        return 7;
    }
    */
    string str = "hey, how are you", decrypt = "╤└╦cУк{╗УтУ+У\"{л";
    /*
    const string MODE = argc[1];
    const string FILE_NAME = argc[2];
    ifstream file;
    file.open(FILE_NAME);
    */
    encryption(str, decrypt); cout << endl;
    decryption(decrypt, str);

    return 0;
}
