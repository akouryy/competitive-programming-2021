#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N N(X Y)
  */
  int N;cin>>N;VI X(N),Y(N);times(N,i0){cin>>X[i0]>>Y[i0];}

  VTIII entries;
  times(2, h) {
    VPII z(N);
    times(N, i) z[i] = { (h ? Y : X)[i], i };
    sort(iter(z));
    entries.PB({z[N-1].first - z[0].first, z[0].second, z[N-1].second });
    entries.PB({z[N-1].first - z[1].first, z[1].second, z[N-1].second });
    entries.PB({z[N-2].first - z[0].first, z[0].second, z[N-2].second });
  }

  sort(iter(entries));
  dd entries;

  int ai = get<1>(entries[5]), aj = get<2>(entries[5]);

  downto(4, 3, h) {
    int bi = get<1>(entries[h]), bj = get<2>(entries[h]);
    if((ai != bi || aj != bj) && (ai != bj || aj != bi)) {
      cout << get<0>(entries[h]) ln;
      return;
    }
  }

}
