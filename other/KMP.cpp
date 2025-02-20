#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string str = s2 + '#' + s1;
    vector<int> pi(str.size(), 0);
    for (int i = 1; i < str.size(); i++) {
        int len = pi[i - 1];
        while (len != 0 && str[i] != str[len]) {
            len = pi[len - 1];
        }
        if (str[i] == str[len]) {
            pi[i] = len + 1;
            if (pi[i] == s2.size()) cout << i + 1 - 2 * s2.size() << endl;
        }
    }
    for (int i = 0; i < s2.size(); i++) cout << pi[i] << " ";
    cout << endl;
    return 0;
}