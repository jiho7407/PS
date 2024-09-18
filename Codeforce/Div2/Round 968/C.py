from itertools import permutations


def generate_permutations(s):
    # 모든 순열을 생성하고 중복을 제거
    unique_permutations = set(permutations(s))

    # 결과를 리스트로 변환하여 문자열로 출력
    result = [''.join(p) for p in unique_permutations]
    return result


# 예시 사용
s = input()
permutations_list = generate_permutations(s)


def calc(S):
    n = len(S)
    ret = 0

    for i in range(n):
        for j in range(i + 1, n):
            if S[i] == S[j]:
                ret += 1
                continue

            for k in range(i, j):
                if S[k] != S[k + 1] and (S[k] != S[i] or S[k + 1] != S[j]):
                    ret += 1
                    break

    return ret


mx = 0
# 모든 순열 출력
for perm in permutations_list:
    mx = max(mx, calc(perm))

T = input()

if calc(T) != mx:
    print("NO")
    exit()
else:
    print("YES")
    print(T)
    exit()

# for perm in permutations_list:
#     if calc(perm) == mx:
#         print(perm)
