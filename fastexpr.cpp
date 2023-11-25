#include <bits/stdc++.h>
using namespace std;

class Eval {
private:
    stack<int> saved;
    stack<char> op;
    int precedence(char op) {
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }
    string removeSpace(const string& s) {
        string res = "";
        int size = s.size();
        for (int c = 0; c < size; ++c) {
            if (s[c] != ' ') res += s[c];
        }
        return res;
    }
    string fix(string s) {
        int n = s.size(); s = removeSpace(s);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '-' && !isdigit(s[i - 1])) s.insert(i, 1, '0');
        }
        return s;
    }
    int calc(int a, int b, char op) {
        switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            break;
        }
        return -1;
    }

public:
    int solve(string s) {
        s = fix(s);
        int n = s.size();
        stack<int> saved; stack<char> op;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            else if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0'); i++;
                }
                saved.push(num);
                i--;
            }
            else if (s[i] == '(') {
                op.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!op.empty() && op.top() != '(') {
                    int b = saved.top(); saved.pop();
                    int a = saved.top(); saved.pop();
                    char o = op.top(); op.pop();
                    saved.push(calc(a, b, o));
                }
                if (!op.empty()) op.pop();
            }
            else if (s.substr(i, 3) == "abs") {
                i += 3;
                int start = i + 1;
                int count = 0;
                while (i < n && (s[i] != ')' || count != 0)) {
                    if (s[i] == '(') ++count;
                    else if (s[i] == ')') --count;
                    ++i;
                }
                int num = solve(s.substr(start, i - start));
                saved.push(abs(num));
                --i;
            }
            else {
                while (!op.empty() && precedence(op.top()) >= precedence(s[i])) {
                    int b = saved.top(); saved.pop();
                    int a = saved.top(); saved.pop();
                    char o = op.top(); op.pop();
                    saved.push(calc(a, b, o));
                }
                op.push(s[i]);
            }
        }
        while (!op.empty()) {
            int b = saved.top(); saved.pop();
            int a = saved.top(); saved.pop();
            char o = op.top(); op.pop();
            saved.push(calc(a, b, o));
        }
        return saved.top();
    }
};

int main() {
    string s;
    getline(cin, s);
    Eval eval;
    cout << eval.solve(s);
    return 0;
}
