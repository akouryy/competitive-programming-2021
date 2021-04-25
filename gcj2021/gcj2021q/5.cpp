///// AC1-WA1 (11/31)


#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

constexpr int nP = 100, nQ = 10000;

int P;

void solve(int gcj_case_id) {
  if(gcj_case_id == 0) cin >> P;
  // 100("A")
  /* <foxy.memo-area> */
  VS A(nP);times(nP,Ri_0){cin>>A[Ri_0];}
  /* </foxy.memo-area> */

  // ids in ascending difficulty
  VI idsD(nQ);
  times(nQ, i) idsD[i] = i;

  VI correctCounts(nQ);
  times(nP, h) times(nQ, i) correctCounts[i] += A[h][i] - '0';
  sort(iter(idsD), [&](int i, int j) { return correctCounts[i] > correctCounts[j]; });

  vector<LD> dls(nQ);
  // times(nQ, i) dls[idsD[i]] = 6.0 * i / nQ - 3.0;
  times(nQ, i) dls[i] = 6.0 * correctCounts[i] / nQ - 3.0;
  // dd dls;

  LD pMin = numeric_limits<LD>::max();
  int ans;
  times(nP, h) {
    LD p = 0; // numeric_limits<LD>::max() - numeric_limits<LD>::min();
    LD sl = 6.0 * count(iter(A[h]), '1') / nQ - 3.0;
    times(nQ, i) {
      LD x = sl - dls[i];
      LD wrongRateLog = -log(1 + exp(+x));
      LD correctRateLog = wrongRateLog + x;
      p += A[h][i] == '1' ? correctRateLog : wrongRateLog;
      // LD correctRate = 1 / (1 + exp(-x));
      // p += log(A[h][i] == '1' ? correctRate : 1 - correctRate);
      // if(correctRate >= 0.5) {
      //   if(A[h][i] == '0') p *= (1 - correctRate) / correctRate;
      // } else {
      //   if(A[h][i] == '1') p *= correctRate / (1 - correctRate);
      // }
    }
    if(amin(pMin, p)) ans = h;
    dd ans; pMin; p;
  }

  cout << ans + 1 ln;
}
