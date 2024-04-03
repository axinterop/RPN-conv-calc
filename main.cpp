#include "ll-stack.cpp"
#include "ll-stack.h"
#include "String.h"
#include <cstdio>
#include <cstring>

using namespace std;

#define BUF_SIZE 16

bool is_func(const String s) {
    int i = 0, max = 3;
    if (s.length() < 3)
        max = s.length();
    while (i != max) {
        if (!(s[i] >= 'A' && s[i] <= 'Z'))
            return false;
        i++;
    }
    return true;
}

bool is_number(const String s) {
    int i = 0;
    while (i != s.length()) {
        if (!isdigit(s[i]))
            return false;
        i++;
    }
    return true;
}

bool is_bracket(const String s) {
    if (s[0] == '(' || s[0] == ')')
        return true;
    return false;
}

int get_priority(const String s) {
    if (s == '+' || s == '-')
        return 0;
    else if (s == '*' || s == '/')
        return 1;
    else if (s == "IF" || s == "N" || s == "MIN" || s == "MAX")
        return 2;
    else if (is_bracket(s))
        return 3;
    else
        return -1;
}

bool is_operator(const String s) {
    if (s == '+' || s == '-' || s == '*' || s == '/' || s == "N")
        return true;
    return false;
}

void output_token(const String s) {
    cout << s << "  ";
}

void output_token(const String s, int i) {
    if (s == "MIN" || s == "MAX")
        cout << s << i << "  ";
    else
        output_token(s);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Stack<String> s;
    Stack<int> cS;

    int inputNum;
    scanf("%i", &inputNum);
    for (int i = 0; i < inputNum; i++) {
        char f[BUF_SIZE];
        String c;
        while (true) {
            // Read the token
            scanf("%s", f);
            if (!strcmp(f, ".")) // end algorithm
                break;

            c = String(f);

            // If token ...
            if (is_number(c))
                output_token(c);

            else if (is_func(c)) {
                if (c == "MAX" || c == "MIN")
                    cS.push(1);
                s.push(c);
            } else if (is_operator(c)) {
                while (!s.isEmpty() && s.peek() != "(") {
                    if (get_priority(s.peek()) >= get_priority(c)) {
                        if (!cS.isEmpty()) {
                            output_token(s.peek(), cS.peek());
                            cS.pop();
                        } else
                            output_token(s.peek());
                        s.pop();
                    } else
                        break;
                }
                s.push(c);
            } else if (c == ",") {
                while (!s.isEmpty() && s.peek() != "(") {
                    if (!cS.isEmpty()) {
                        output_token(s.peek(), cS.peek());
                        cS.pop();
                    } else
                        output_token(s.peek());
                    s.pop();
                }
                if (!cS.isEmpty()) {
                    int cInc = cS.peek() + 1;
                    cS.pop();
                    cS.push(cInc);
                }
            } else if (c == "(")
                s.push(c);

            else if (c == ")") {
                while (!s.isEmpty() && s.peek() != "(") {
                    if (!cS.isEmpty()) {
                        output_token(s.peek(), cS.peek());
                        cS.pop();
                    } else
                        output_token(s.peek());
                    s.pop();
                }
                if (s.peek() == "(")
                    s.pop();
            }
        }
        while (!s.isEmpty()) {
            if (!cS.isEmpty()) {
                output_token(s.peek(), cS.peek());
                cS.pop();
            } else
                output_token(s.peek());
            s.pop();
        }
        cout << endl;
    }
}
