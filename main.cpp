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


void ONPCalculate(Queue<String> &onp) {
    cout << endl;
    String c;
    Stack<int> ops;
    bool err = false;
    while (!onp.isEmpty()) {
        int o3, o2, o1;
        c = onp.peek();
        onp.dequeue();
        if (is_number(c)) {
            ops.push(c.to_int());
        } else {
            cout << c << " ";
            ops.display(false);
            if (c[0] == '+') {
                o2 = ops.peek();
                ops.pop();
                o1 = ops.peek();
                ops.pop();
                ops.push(o1 + o2);
            } else if (c[0] == '-') {
                o2 = ops.peek();
                ops.pop();
                o1 = ops.peek();
                ops.pop();
                ops.push(o1 - o2);
            } else if (c[0] == '*') {
                o2 = ops.peek();
                ops.pop();
                o1 = ops.peek();
                ops.pop();
                ops.push(o1 * o2);
            } else if (c[0] == '/') {
                o2 = ops.peek();
                ops.pop();
                o1 = ops.peek();
                ops.pop();
                if (o2 != 0)
                    ops.push(o1 / o2);
                else {
                    cout << "ERROR\n";
                    err = true;
                    break;
                }
            } else if (c[0] == 'N') {
                o1 = ops.peek();
                ops.pop();
                ops.push(-o1);
            } else if (c[0] == 'I') {
                o3 = ops.peek();
                ops.pop();
                o2 = ops.peek();
                ops.pop();
                o1 = ops.peek();
                ops.pop();
                if (o1 > 0)
                    ops.push(o2);
                else
                    ops.push(o3);
            } else if (c[0] == 'M') {
                int len = c.length() - 3;
                int args = c.substr(3, len).to_int(); // TODO: Maybe dequeue next token as it was the part of max or min?

                int r = ops.peek();;
                for (int i = 0; i < args; i++) {
                    o1 = ops.peek();
                    ops.pop();
                    if (c[1] == 'A' && o1 > r)
                        r = o1;
                    else if (c[1] == 'I' && o1 < r)
                        r = o1;
                }
                ops.push(r);
            }
        }
    }
    if (!err) {
        ops.display(false);
        ops.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int inputNum;
    scanf("%i", &inputNum);
    for (int i = 0; i < inputNum; i++) {
        Stack<String> s;
        Stack<int> cS;
        long long int last_is_m = 0;
        cout << endl;
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
                } else if (c[0] != 'N')
                    last_is_m = last_is_m << 1;
                s.push(c);
            } else if (is_operator(c)) {
                while (!s.isEmpty() && s.peek() != "(") {
                    if (get_priority(s.peek()) >= get_priority(c)) {
                        if (!cS.isEmpty() && s.peek()[0] == 'M') {
                            onp.enqueue(s.peek() + cS.peek()); // TODO: Replace concatenation [str + int] by making cS.peek().to_str()?
                            cS.pop();                               /* TODO: Replace concatenation [str + int] by adding cS.peek() to onp queue as as str, and during calculation and output handle it properly?
                                                                    */
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
                    if (last_is_m && is_func(s.peek_next()) && s.peek_next()[0] != 'N')
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
        onp.display(true);
        ONPCalculate(onp);
    }


    return 0;
}
