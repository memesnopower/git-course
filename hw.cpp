#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

unsigned int left_shift(unsigned int x, int bytes = 4) {
    return (x << 3) | (x >> (bytes*8-3));
}

unsigned int right_shift(unsigned int x, int bytes = 4) {
    return ((x >> 3) | (x << (bytes*8-3)));
}
unsigned int gamma;


void encryption(string &source_string, string &encrypted_string) {
    unsigned int result = 0;
    int size = 4;
    int incomplete_blocks = source_string.size() % 4;
    int blocks = source_string.size() / 4;
    char sentences[source_string.size() + 1];

    for (int i = 0; i <= source_string.size(); i++) {
        sentences[i] = source_string[i];
    }

    for (int i = 0; i <= blocks; i++) {
        if (i < blocks) {
            memcpy(&result, sentences + i * 4, size);
            result ^= gamma;
            result = left_shift(result);


            memcpy(sentences + i * 4, &result, size);
        } else {
            result = 0;
            memcpy(&result, sentences + i * 4, incomplete_blocks);

            result = left_shift(result ^ ((gamma >> 8 * (size - incomplete_blocks))), incomplete_blocks);
            memcpy(sentences + i * 4, &result, incomplete_blocks);
        }
    }
    encrypted_string = sentences;
    cout << encrypted_string;
}

void decryption(string &encrypted_string, string &decrypted_string) {
    unsigned int result = 0;
    int size = 4;
    int incomplete_blocks = encrypted_string.size() % 4;
    int blocks = encrypted_string.size() / 4;

    char sentences[encrypted_string.size() + 1];

    for (int i = 0; i <= encrypted_string.size(); i++) {
        sentences[i] = encrypted_string[i];
    }

    for (int i = 0; i <= blocks; i++) {
        if (i < blocks) {
            memcpy(&result, sentences + i * 4, size);

            result = right_shift(result);
            result ^= gamma;

            memcpy(sentences + i * 4, &result, size);

        } else {
            result = 0;
            memcpy(&result, sentences + i * 4, incomplete_blocks);

            result = right_shift(result, incomplete_blocks);
            result ^= (gamma >> (8 * (size - incomplete_blocks)));
            memcpy(sentences + i * 4, &result, incomplete_blocks);

        }
    }
    decrypted_string = sentences;
    cout << decrypted_string;
}

int main(int argv, char *argc[]) {
    const string MODE = argc[1];
    const string FILE_NAME = argc[2];
    int key;
    cout << "Please enter the key";
    cin >> key;
    srand(key);
    gamma = rand();
    string source_string, decrypted_string, encrypted_string;
    encryption(source_string, encrypted_string);
    cout << endl;
    decryption(encrypted_string, decrypted_string);
    
    if (argv != 3) {
        cerr << "Use three parameters!";

        return 7;
    }


    char words;


    ifstream file;
    file.open(FILE_NAME);

    if (!file) {
        cerr << "Can not open the file!";

        return 5;
    } else {
        while (!file.eof()) {
            file.get(words);
            source_string += words;
        }
        file.close();
    }

    if (MODE == "encryption") {
        encryption(source_string, encrypted_string);
        ofstream new_file;
        new_file.open(FILE_NAME);

        if (!new_file) {
            cerr << "Can not open the file!";

            return 5;
        } else {
            new_file << encrypted_string;
            new_file.close();

        }
    } else if (MODE == "decryption") {

        decryption(encrypted_string, decrypted_string);
        ofstream new_file;
        new_file.open(FILE_NAME);

        if (!new_file) {
            cerr << "Can not open the file!";

            return 5;
        } else {
            new_file << decrypted_string;
            new_file.close();
        }
    } else {
        cerr << "Use encryption or decryption modes!";

        return 4;
    }

    return 0;
}
