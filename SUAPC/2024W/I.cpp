#include <iostream>
#include <map>
#include <vector>
#include <numeric> // gcd
#include <tuple>

using namespace std;

bool canWin(int X, map<int, int>& cards, map<int, map<int, int>> &memo) {
    // 메모이제이션 체크
    if (memo[X].find(cards.size()) != memo[X].end()) {
        return false; // 이전에 같은 상황이 발생했다면, 승리 불가능한 상황으로 간주
    }

    for (auto it = cards.begin(); it != cards.end(); ++it) {
        int card = it->first;
        int count = it->second;
        if (count > 0 && gcd(X, card) > 1) {
            int next_X = gcd(X, card);
            map<int, int> next_cards = cards;
            next_cards[card]--;
            if (next_cards[card] == 0) {
                next_cards.erase(card);
            }

            if (!canWin(next_X, next_cards, memo)) {
                return true;
            }
        }
    }

    // 실패 시 현재 상태 메모이제이션
    memo[X][cards.size()] = true;
    return false;
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> cards(N);
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }

    map<int, int> cards_map;
    for (int card : cards) {
        cards_map[card]++;
    }

    map<int, map<int, int>> memo;

    if (canWin(X, cards_map, memo)) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}
