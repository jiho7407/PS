#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxL = 1000100;
long long N, L;
vector<long long> A[mxL];
long long DPA[mxL], DPB[mxL];

vector<pair<int, int>> lines;
vector<int> As, Bs;
map<int, int> Adct, Bdct;

int main(){
    fastio();
    cin >> N >> L;
    for(int i = 0; i<N; i++){
        int t, d;
        cin >> t >> d;
        lines.push_back({t, d});
        As.push_back(t);
        Bs.push_back(d);
        // A[t].push_back(d);
    }

    sort(As.begin(), As.end());
    sort(Bs.begin(), Bs.end());

    auto last = unique(As.begin(), As.end());
    As.erase(last, As.end());
    last = unique(Bs.begin(), Bs.end());
    Bs.erase(last, Bs.end());

    for(int i = 0; i<As.size(); i++) Adct[As[i]] = i;
    for(int i = 0; i<Bs.size(); i++) Bdct[Bs[i]] = i;

    // for(const auto& pair : Adct) {
    //     cout << "{" << pair.first << ": " << pair.second << "}, ";
    // }

    // for(int i = 0; i<N; i++) A[lines[i].first].push_back(lines[i].second);
    for(int i = 0; i<N; i++) A[Adct[lines[i].first]].push_back(Bdct[lines[i].second]);

    fill(DPA, DPA+mxL, 0);
    fill(DPB, DPB+mxL, 0);

    for(int i = 0; i<mxL; i++){
        sort(A[i].begin(), A[i].end());
        for(long long g: A[i]){
            long long temp = DPB[g];
            DPB[g] = max(DPB[g], DPA[i] + abs(Bs[g]-As[i]) + L);
            DPA[i] = max(DPA[i], temp + abs(Bs[g]-As[i]) + L);
        }
    }

    long long ans = 0;
    for(int i = 0; i<mxL; i++) ans = max(ans, max(DPA[i], DPB[i]));

    // for(int i = 0; i<mxL; i++) cout << DPA[i] << " ";
    // cout << "\n";
    // for(int i = 0; i<mxL; i++) cout << DPB[i] << " ";
    cout << ans;
    return 0;
}