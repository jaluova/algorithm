// P5734 【深基6.例6】文字处理软件
#include <bits/stdc++.h>

using namespace std;

int q;
char str[500];

void stringMaster(int x, char *str) {
    int len = strlen(str);
    int l;
    int i = 0, j = 0;
    char s[20];
    int a, b;

    switch (x) {
    case 1:
        cin >> s;
        for (j = 0; s[j]; j++) {
            str[j + len] = s[j];
        }
        str[j + len] = 0;
        cout << str << endl;
        break;
    case 2:
        cin >> a >> b;
        for (; j < b; ++j) {
            str[j] = str[j + a];
        }
        str[b] = 0;
        cout << str << endl;
        break;
    case 3:
        cin >> a >> s;
        l = strlen(s);
        for (j = len; j >= a; j--) {
            str[j + l] = str[j];
        }
        for (j = 0; j < l; ++j) {
            str[a + j] = s[j];
        }
        cout << str << endl;
        break;
    case 4:
        cin >> s;
        l = strlen(s);
        while (1) {
            if (j == l) {
                cout << i << endl;
                return;
            }

            if (str[i + j] == 0) {
                cout << -1 << endl;
                return;
            }

            if (s[j] == str[i + j]) {
                j++;
            } else {
                j = 0;
                i++;
            }
        }
        break;
    }
}

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    cin >> q;
    cin >> str;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        stringMaster(x, str);
    }

    return 0;
}
