/**
* Description: Answers queries offline in (N+Q)sqrt(N)
    * Also see Mo's on trees
* Source: Codeforces
* Verification: ?
*/

int N, A[MX];
int ans[MX], oc[MX], BLOCK;
vector<array<int,3>> todo; // store left, right, index of ans

bool cmp(array<int,3> a, array<int,3> b) { // sort queries
    if (a[0]/BLOCK != b[0]/BLOCK) return a[0] < b[0];
    return a[1] < b[1];
}

int l = 0, r = -1, cans = 0;

void ad(int x, int y = 1) {
    x = A[x];
    // if condition: cans --;
    oc[x] += y;
    // if condition: cans ++;
}

int answer(int L, int R) { // adjust interval
    while (l > L) ad(--l);
    while (r < R) ad(++r);
    while (l < L) ad(l++,-1);
    while (r > R) ad(r--,-1);
    return cans;
}

void solve() {
    BLOCK = sqrt(N); sort(all(todo),cmp);
    trav(x,todo) {
        answer(x[0],x[1]);
        ans[x[2]] = cans;
    }
}
