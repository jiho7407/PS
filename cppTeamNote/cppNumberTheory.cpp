// 나머지 연산

lll addmod(lll a, lll b, lll mod){
    return (a%mod + b%mod)%mod;
}

lll mulmod(lll a, lll b, lll mod){
    return (a%mod * b%mod)%mod;
}

lll powmod(lll a, lll b, lll mod){
    lll res = 1;
    while(b){
        if(b&1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

// 유클리드 호제법

ll gcd(ll a, ll b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b){
    return a/gcd(a, b)*b;
}

// 확장 유클리드 호제법



// 밀러라빈 소수 판별

bool miller_rabin(lll n, lll a){
    lll d = n-1, s = 0;
    while(d%2==0){
        d >>= 1;
        s++;
    }
    if(powmod(a, d, n) == 1) return true;
    rep(i, 0, s){
        if(powmod(a, (1LL<<i)*d, n) == n-1) return true;
    }
    return false;
}

bool isprime(lll n){
    if(n<2) return false;
    else if(n<=10000){
        for(lll i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
    }
    else{
        vector<lll> v;
        if(n < 1'373'653) v = {2, 3};
        else if(n < 9'080'191) v = {31, 73};
        else if(n < 4'759'123'141) v = {2, 7, 61};
        else if(n < 1'122'004'669'633) v = {2, 13, 23, 1662803};
        else if(n < 2'152'302'898'747) v = {2, 3, 5, 7, 11};
        else if(n < 3'474'749'660'383) v = {2, 3, 5, 7, 11, 13};
        else if(n < 341'550'071'728'321) v = {2, 3, 5, 7, 11, 13, 17};
        else v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for(lll a:v){
            if(!miller_rabin(n, a)) return false;
        }
    }
    return true;
}

void pollard_rho(lll n, vector<lll> &primes){
    if(n == 1) return;
    if(n%2 == 0){
        primes.push_back(2);
        pollard_rho(n/2, primes);
        return;
    }
    if(isprime(n)){
        primes.push_back(n);
        return;
    }
    lll fast, slow, c, g;
    g = n;
    do{
        if(g == n){
            fast = slow = rand()%(n-1)+1;
            c = rand() % 20 + 1;
        }
        fast = (mulmod(fast, fast, n) + c)%n;
        fast = (mulmod(fast, fast, n) + c)%n;
        slow = (mulmod(slow, slow, n) + c)%n;        
        g = gcd(abs(fast-slow), n);
    }while(g == 1);
    pollard_rho(g, primes);
    pollard_rho(n/g, primes);
    return;
}