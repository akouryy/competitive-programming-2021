// #define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

// [l, r)
int query(int l, int r) {
  if(l+1 != r) {
    cout << 'M' sp << l+1 sp << r << endl;
    int m;
    cin >> m;
    return m-1;
  } else {
    return l;
  }
}

void swap(int i, int j) {
  if(i != j) {
    cout << 'S' sp << i+1 sp << j+1 << endl;
    int ignore;
    cin >> ignore;
  }
}

void submit() {
  cout << 'D' << endl;
  int ignore;
  cin >> ignore;
}

void solve() {
  int T, N; cin>>T>>N;

  times(T, o) {
    times(N, i) {
      swap(i, query(i, N));
    }
    submit();
  }
}
