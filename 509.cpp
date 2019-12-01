class Solution {
public:
    int fib(int N) {
        if (!N) return 0;
        if (N==1) return 1;
        int t1 = 0, t2 = 1;
        for (int i=2; i<N; ++i) {
            t2 = t1 + t2;
            t1 = t2 - t1;
        }
        return t1 + t2;
    }
};