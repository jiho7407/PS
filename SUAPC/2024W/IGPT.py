from collections import Counter
from math import gcd
from functools import lru_cache

@lru_cache(maxsize=None)
def can_win(X, cards_tuple):
    cards_counter = Counter(dict(cards_tuple))
    for card, count in cards_counter.items():
        if count > 0 and gcd(X, card) > 1:
            next_X = gcd(X, card)
            next_cards_counter = cards_counter.copy()
            next_cards_counter[card] -= 1
            if next_cards_counter[card] == 0:
                del next_cards_counter[card]
            
            # 해시 가능한 튜플 형태로 변환
            next_cards_tuple = tuple(sorted(next_cards_counter.items()))
            if not can_win(next_X, next_cards_tuple):
                return True
    return False

cards_tuple_example = ((2, 1), (3, 2), (4, 1), (5, 1))  # 카드와 빈도수를 나타내는 튜플

N, X_example = map(int, input().split())
cards = [*map(int, input().split())]
cards_list = []
for cmd in set(cards):
    cards_list.append((cmd, cards.count(cmd)))
    
cards_counter_example = tuple(cards_list)

result = can_win(X_example, cards_counter_example)
if result:
    print("First")
else:
    print("Second")