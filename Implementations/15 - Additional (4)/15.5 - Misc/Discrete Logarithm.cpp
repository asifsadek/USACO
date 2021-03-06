/**
 * Description: find k such that root^k%mod=x
 	* mod is prime, root is primitive
 	* meet in the middle: O(sqrt(mod))
 * Source: Own
 * Verification: PA 2006 - Professor Laugh's Numbers
 */

using namespace modOp;

struct DiscreteLog {
	int mod, root, block;
	vi invy;
	unordered_map<int,int> u;

	int query(int x) {
		F0R(i,block) {
			int X = mul(x,invy[i],mod);
			if (u.count(X)) return i*block+u[X];
		}
		return -1;
	}

	void gen(int _mod, int _root) {
		mod = _mod, root = _root, u.clear();

		block = sqrt(mod)+1;
		int cur = 1;
		F0R(i,block) u[cur] = i, MUL(cur,root,mod);
		cur = inv(cur,mod);

		invy.resz(block);
		invy[0] = 1; FOR(i,1,block) invy[i] = mul(cur,invy[i-1],mod);
	} 
};
