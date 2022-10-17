#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Discipline {
    string name;
    int mark;
};
struct Student {
    string fio;
    Discipline y[4];
};


int main() {

    int n, m, count = 0;
    double a[100];
    cout << "Enter number of students:\n";
    cin >> n;
    cout << "Enter number of disciplines:\n";
    cin >> m;
    vector <Student> x(n);
    for (int i = 0; i < n; i++) {
        cout << "FIO:\n";
        cin.ignore();
        getline(cin, x[i].fio);
        for (int j = 0; j < m; j++) {
            cout << "Discipline:\n";
            getline(cin, x[i].y[j].name);
            cout << "Mark:\n";
            cin >> x[i].y[j].mark;
            cin.ignore();
        }
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            a[i] += (double) x[i].y[j].mark;
        }
        if (a[i] > 2) {
            count++;
        }
    }
    cout << "Total:" << count;
    return 0;
}
