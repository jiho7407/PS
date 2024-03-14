a = int(input())
m, n = map(int, input().split())

print(min(max(m/a, n),
      max(m, n/a),
      2*m/a,
      2*n/a))
