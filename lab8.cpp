#include <iostream>

using namespace std;

struct Bank {
    string name;
    int summa;
    string typeOfMoney;
    int percents;
};

struct ListItem {
    Bank Bank;
    ListItem *pNext, *pPred;
};

struct List
{
    ListItem *pFirst;
};

void addInList(List & list, ListItem *p, bool flag = true)
        {
                if (list.pFirst == 0)
                {
                    list.pFirst = p->pNext = p->pPred = p;
                }
                else
                {
                    p->pNext = list.pFirst;
                    p->pPred = list.pFirst->pPred;
                    list.pFirst->pPred->pNext = p;
                    list.pFirst->pPred = p;
                    if (flag) list.pFirst = p;
                }
        }
void addAfterZad(ListItem *pZad, ListItem *p)
{
    p->pNext = pZad->pNext;
    p->pPred = pZad;
    pZad->pNext->pPred = p;
    pZad->pNext = p;
}
ListItem * myremove(List & list, ListItem *p)
{
    if (list.pFirst == 0 || p == 0) return 0;
    if (list.pFirst->pNext == list.pFirst)
    {
        if (p == list.pFirst)
        {
            list.pFirst = 0;
            return p;
        }
        else return 0;
    }
    if (p == list.pFirst)
        list.pFirst = list.pFirst->pNext;
    p->pPred->pNext = p->pNext;
    p->pNext->pPred = p->pPred;
    return p;
}
void print(List list)
{
    ListItem *p = list.pFirst;
    do
    {
        cout << endl << p->Bank.name << ' ' << p->Bank.summa << ' ' << p->Bank.typeOfMoney << ' ' << p->Bank.percents;
        p = p->pNext;
    } while (p != list.pFirst);
}
/*
string str[] = {"USA Bank", "Russian Bank", "England Bank", "Spanish Bank"};
string typeOfMoneys[] = {"dollars", "rub", "eur"};
*/
int main() {
    int percents, summa;
    List x;
    x.pFirst = 0;
    ListItem *p;
    char ch;
    do {
        p = new ListItem;
        cout << endl << "Name: ";
        getline(cin, p->Bank.name);
        cout <<"Summa: ";
        cin >> summa;
        p->Bank.summa = summa;
        cin.ignore();
        cout <<"Type of Money: ";
        getline(cin, p->Bank.typeOfMoney);
        cout << "Percents: ";
        cin >> percents;
        p->Bank.percents = percents;
        cin.ignore();
        addInList(x, p, false);
        cin >> ch;
        cin.ignore();
    } while (ch == 'Y');

    cout << endl <<"Do sort" << endl;
    print(x);


    bool zamena;
    do {
        zamena = false;
        ListItem *p1 = x.pFirst, *p2=x.pFirst->pNext;
        do {
            if (p1->Bank.summa<p2->Bank.summa) {
                p1 = myremove(x, p1);
                if (p1 == 0)
                {
                    cout<<endl<<"List Error!!!!";
                    system("pause");
                    return 0;
                }
                addAfterZad(p2, p1);
                p2 = p1->pNext;
                zamena = true;
            } else {
                p1 = p2;
                p2 = p2->pNext;
            }
        } while (p2 != x.pFirst);

    }while (zamena);

    cout << endl << "Posle sortirovki";
    print(x);

    return 0;
}
