#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"
#include "graph.hpp"
#include "fact.hpp"

PIM dp(int i, Graph<int>& g, Fact<>& facter) {
  int sum_a = 0;
  mint prod_afactinv = 1_m;
  mint prod_b = 1_m;
  for(auto edge : g.edges[i]) {
    int a; mint b; tie(a, b) = dp(edge.to, g, facter);
    sum_a += a;
    prod_afactinv *= facter.finv(a);
    prod_b *= b;
  }
  mint zp = prod_b * prod_afactinv * facter[sum_a];
  dd i; zp;
  return {sum_a + 1, zp};
}

void solve(int gcj_case_id) {
  /* wt.ten
    N NV
  */
  int N;cin>>N;VI V(N);times(N,i0){cin>>V[i0];}

  if(V[0] != 1) {
    cout << 0 ln;
    return;
  }
  times(N-1, i) if(V[i+1] >= V[i]+2) {
    cout << 0 ln;
    return;
  }

  Graph<int> g(N);
  int root;
  {
    VI current;
    times(N, i) {
      int s = size(current);
      if(s >= V[i]) {
        downto(s, V[i]+1, t) {
          int j = current.back(); current.pop_back();
          g.add_dedge(current.back(), j, 0);
        }
        g.add_dedge(i, current.back(), 0); current.pop_back();
      }
      current.PB(i);
    }
    times(size(current)-1, t) {
      g.add_dedge(current[t], current[t+1], 0);
    }
    root = current[0];
  }
  dd g.edges;

  Inver<> inver(N);
  Fact<> facter(N, &inver);

  cout << dp(root, g, facter).second ln;
}
