#include <iostream>
#include <vector>

using namespace std;

template <typename M, typename I, typename R, typename U>
void increaseEnumerate(int s, int e, const M& match, const I& insert,
                       const R& remove, const U& update) {
    for (int l = s, r = s; l <= e;) {
        if (l < r && match(l, r - 1)) {
            update(l, r - 2);
            remove(l++, r);
        } else if (r <= e) {
            insert(l, r++);
        } else {
            update(l, r - 1);
            remove(l++, r);
        }
    }
}

int main() {
    string s;
    cin >> s;
    int ans = 0;
    vector<int> cnt(128);
    bool same = false;
    increaseEnumerate(
        0, s.size() - 1, [&](int l, int r) { return same; },
        [&](int l, int r) {
            cnt[s[r]]++;
            if (cnt[s[r]] == 2) same = true;
        },
        [&](int l, int r) {
            cnt[s[l]]--;
            if (cnt[s[l]] == 1) same = false;
        },
        [&](int l, int r) { ans = max(ans, r - l + 1); });

    cout << ans << endl;

    return 0;
}