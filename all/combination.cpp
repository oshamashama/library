struct COMB{
    long long MOD = 1e9 + 7;
//    long long MOD = 1e9 + 7;
    vl fact, fact_inv, inv;
    void init_nCk(long long SIZE) {
        fact.resize(SIZE + 5);
        fact_inv.resize(SIZE + 5);
        inv.resize(SIZE + 5);
        fact.at(0) = fact.at(1) = fact_inv.at(0) = fact_inv.at(1) = inv.at(1) = 1;
        for(long long i = 2; i < SIZE + 5; i++) {
            fact.at(i) = fact.at(i - 1)*i%MOD;
            inv.at(i) = MOD - inv.at(MOD%i)*(MOD/i)%MOD;
            fact_inv.at(i) = fact_inv.at(i - 1)*inv.at(i)%MOD;
        }
    }
    long long nCk (long long n, long long k) {
        assert(!(n < k));
        assert(!(n < 0 || k < 0));
        return fact.at(n)*(fact_inv.at(k)*fact_inv.at(n - k)%MOD)%MOD;
    }
};