#include "ll-stack.cpp"
#include "ll-stack.h"
#include <cstdio>
#include <cstring>

using namespace std;

#define BUF_SIZE 16

bool is_word(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        if (!(s[i] >= 'A' && s[i] <= 'Z'))
            return false;
        i++;
    }
    return true;
}

bool is_operand(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        if (!isdigit(s[i]))
            return false;
        i++;
    }
    return true;
}

bool is_bracket(const char s[]) {
    if (s[0] == '(' || s[0] == ')')
        return true;
    return false;
}

int get_priority(const char s[]) {
    if (is_operand(s))
        return -1;
    if (s[0] == '+' || s[0] == '-')
        return 0;
    if (s[0] == '*' || s[0] == '/')
        return 1;
    if (strcmp(s, "IF") || strcmp(s, "N") || strncmp(s, "MIN", 3) || strncmp(s, "MAX", 3))
        return 2;
    if (is_bracket(s))
        return 3;
}

bool is_operator(const char s[]) {
    if (get_priority(s) != -1)
        return true;
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Stack<char *> s;

    int inputNum;
    scanf("%i", &inputNum);
    for (int i = 0; i < inputNum; i++) {
        char c[BUF_SIZE];
        do {
            scanf("%s", c);
            if (is_operand(c))
                cout << c;
            else if (is_bracket(c)) {
                if (strcmp(c, "("))
                    s.push(c);
                else if (strcmp(c, ")")) {
                    while (!s.isEmpty()) {
                        if (strcmp(s.peek(), "(")) {
                            s.pop();
                            break;
                        } else {
                            cout << s.peek();
                            s.pop();
                        }
                    }
                }
            }
            else {
                int c_prior = get_priority(c);
                while (!s.isEmpty()) {
                    char top[BUF_SIZE];
                    strcpy(top, s.peek());
                    s.pop();
                    if (strcmp(top, "(") || get_priority(top) < c_prior) {
                        s.push(top);
                        break;
                    }
                    cout << top;
                }
                s.push(c);
            }
        } while (strcmp(c, "."));
        while (!s.isEmpty()) {
            cout << s.peek();
            s.pop();
        }
        cout << endl;
    }
}
