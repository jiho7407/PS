S = input()
st = set()
for i in range(len(S)):
    for j in range(i, len(S)):
        st.add(S[i:j+1])
print(len(st))
