#include <iostream>
#include <stack>

using namespace std;

struct forStack {
    char type; //если число, то 0, если мат операция то (+,-,*,/)
    double value; //для чисел
};

int priorityOfMathOper (char symbol) {
    if (symbol == '*' || symbol == '/') {
        return 5;
    } else if (symbol == '-' || symbol == '+') {
        return 4;
    } else {
        return 0;
    }
}

bool calculator (stack <forStack> &numbers, stack <forStack> &operators, forStack variable) {
    double first_number, second_number, answer;
    first_number = numbers.top().value;
    numbers.pop();
    switch (operators.top().type) {
        case '+':
            second_number = numbers.top().value;
            numbers.pop();
            answer = first_number + second_number;
            variable.type = '0';
            variable.value = answer;
            numbers.push(variable);
            operators.pop();
            break;
        case '-':
            second_number = numbers.top().value;
            numbers.pop();
            answer = first_number - second_number;
            variable.type = '0';
            variable.value = answer*(-1);
            numbers.push(variable);
            operators.pop();
            break;
        case '*':
            second_number = numbers.top().value;
            numbers.pop();
            answer = first_number * second_number;
            variable.type = '0';
            variable.value = answer;
            numbers.push(variable);
            operators.pop();
            break;
        case '/':
            second_number = numbers.top().value;
            if (first_number == 0) {
                cerr << "Dont use 0!";
                return false;
            } else {
                numbers.pop();
                answer = second_number / first_number;
                variable.type = '0';
                variable.value = answer;
                numbers.push(variable);
                operators.pop();
                break;
            }
        default:
            cerr << "Error";
            return false;
    }
    return true;
}

int main() {
    stack <forStack> numbers;
    stack <forStack> operators;
    forStack variable;
    double value = 0; //для того, чтобы туда записать считанное число
    char symbol;


    while (true) {
        symbol = cin.peek();

        if (symbol >= '0' && symbol <= '9') {
            cin >> value;
            variable.type = '0';
            variable.value = value;
            numbers.push(variable);
            continue;
        }
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            if (operators.size() == 0) {
                variable.type = symbol;
                variable.value = 0;
                operators.push(variable);
                cin.ignore();
                continue;
            } else if ((operators.size() != 0) && (priorityOfMathOper(symbol) > priorityOfMathOper(operators.top().type))) {
                variable.type = symbol;
                variable.value = 0;
                operators.push(variable);
                cin.ignore();
                continue;
            } else if ((operators.size() != 0) && (priorityOfMathOper(symbol) <= priorityOfMathOper(operators.top().type))) {
                if (calculator(numbers, operators, variable) == false) {
                    return 0;
                } else {
                    continue;
                }
            }
        } else if (symbol == '(') {
            variable.type = symbol;
            variable.value = 0;
            operators.push(variable);
            cin.ignore();
            continue;
        } else if (symbol == ')') {
            while(operators.top().type != '(') {
                if (calculator(numbers, operators, variable) == false) {
                    cerr << "Something wrong!";
                    return 5;
                } else {
                    continue;
                }
            }
            operators.pop();
            cin.ignore();
            continue;
        } else if (symbol == '\n') {
            break;
        }
    }

    while(operators.size() != 0) {
        if (calculator(numbers, operators, variable) == false) {
            cerr << "Something wrong!";
            return 5;
        } else {
            continue;
        }
    }



    cout << numbers.top().value << '\n';
}
