#include "ll-stack.cpp"
#include "ll-queue.cpp"
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
    if (s[0] == '+' || s[0] == '-')
        return 0;
    else if (s[0] == '*' || s[0] == '/')
        return 1;
    else if (s[0] == 'I' || s[0] == 'N' || s[0] == 'M')
        return 2;
    else if (is_bracket(s))
        return 3;
    else
        return -1;
}

bool is_operator(const String s) {
    if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == 'N')
        return true;
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Stack<String> s;
    Stack<int> cS;

    int inputNum;
    long long int last_is_m = 0;
    scanf("%i", &inputNum);
    for (int i = 0; i < inputNum; i++) {
        Queue<String> onp;
        char f[BUF_SIZE];
        String c;
        while (true) {
            // Read the token
            scanf("%s", f);
            if (!strcmp(f, ".")) // end algorithm
                break;

            c = String(f);

            // If token ...
            if (is_number(c)) {
                onp.enqueue(c);
            } else if (is_func(c)) {
                if (c[0] == 'M') {
                    last_is_m = (last_is_m << 1) + 1;
                    cS.push(1);
                } else
                    last_is_m = last_is_m << 1;
                s.push(c);
            } else if (is_operator(c)) {
                while (!s.isEmpty() && s.peek() != "(") {
                    if (get_priority(s.peek()) >= get_priority(c)) {
                        if (!cS.isEmpty() && s.peek()[0] == 'M') {
                            onp.enqueue(s.peek() + cS.peek());
                            cS.pop();
                        } else
                            onp.enqueue(s.peek());
                        s.pop();
                    } else
                        break;
                }
                s.push(c);
            } else if (c == ",") {
                while (!s.isEmpty() && s.peek() != "(") {
                    if (!cS.isEmpty() && s.peek()[0] == 'M') {
                        onp.enqueue(s.peek() + cS.peek());
                        cS.pop();
                    } else
                        onp.enqueue(s.peek());
                    s.pop();
                }
                if ((last_is_m & 1) && !cS.isEmpty()) {
                    int cInc = cS.peek() + 1;
                    cS.pop();
                    cS.push(cInc);
                }
            } else if (c == "(")
                s.push(c);

            else if (c == ")") {
                while (!s.isEmpty() && s.peek() != "(") {
                    if (!cS.isEmpty() && s.peek()[0] == 'M') {
                        onp.enqueue(s.peek() + cS.peek());
                        cS.pop();
                    } else
                        onp.enqueue(s.peek());
                    s.pop();
                }
                if (s.peek() == "(") {
                    if (last_is_m && is_func(s.peek_next()))
                        last_is_m = last_is_m >> 1;
                    s.pop();
                }
            }
        }
        while (!s.isEmpty()) {
            if (!cS.isEmpty() && s.peek()[0] == 'M') {
                onp.enqueue(s.peek() + cS.peek());
                cS.pop();
            } else
                onp.enqueue(s.peek());
            s.pop();
        }
        onp.display();
        cout << endl;
    }


    return 0;
}
