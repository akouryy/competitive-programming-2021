///// AC2-WA1 (14/39)


#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

#define int128 __int128_t
#include "math_rational.hpp"
#include "nck.hpp"

int128 myNCK(int n, int k) {
  if(k < 0 || n < k) return 0;
  int128 ans = 1;
  times(k, i) {
    ans *= n - i;
    ans /= i + 1;
  }
  return ans;
}


void solve(int gcj_case_id) {
  // NQN("A"S)
  /* <foxy.memo-area> */
  int N;int Q;cin>>N;cin>>Q;VS A(N);VI S(N);times(N,Ri_0){cin>>A[Ri_0];cin>>S[Ri_0
  ];}
  /* </foxy.memo-area> */

  if(N == 1) {
    if(amax(S[0], Q - S[0])) {
      for(auto& c : A[0]) c = 'F' + 'T' - c;
    }
    cout << A[0] sp << S[0] << "/1" ln;
  } else if(N == 2) {
    int nDiff = 0;
    times(Q, j) nDiff += A[0][j] != A[1][j];
    int sameCorrect = (S[0] + S[1] - nDiff) / 2;
    int sameWrong = Q - nDiff - sameCorrect;
    string ans;
    int exp = 0;

    exp += max(sameCorrect, sameWrong);
    exp += (nDiff + abs(S[0] - S[1])) / 2;

    dd sameCorrect; sameWrong; (nDiff + abs(S[0] - S[1])) / 2;
    
    times(Q, j) {
      if(A[0][j] == A[1][j]) {
        if(sameCorrect > sameWrong) {
          ans.PB(A[0][j]);
        } else {
          ans.PB('F' + 'T' - A[0][j]);
        }
      } else {
        if(S[0] > S[1]) {
          ans.PB(A[0][j]);
        } else {
          ans.PB(A[1][j]);
        }
      }
    }

    cout << ans sp << exp << "/1" ln;
  } else if(N == 3) {
    int a = 0;
    VI b = {0, 0, 0};
    times(Q, j) {
      if(A[0][j] == A[1][j]) {
        if(A[0][j] == A[2][j]) {
          ++a;
        } else {
          ++b[2];
        }
      } else {
        if(A[0][j] == A[2][j]) {
          ++b[1];
        } else {
          ++b[0];
        }
      }
    }
    VI f(3);
    times(3, i) f[i] = ((b[0] + b[1] + b[2] + b[i]) - (S[0] + S[1] + S[2] - S[i])) / 2;
    const auto q = [&](int c) {
      return myNCK(a, c) * myNCK(b[0], f[0] + c) * myNCK(b[1], f[1] + c) * myNCK(b[2], f[2] + c);
    };
    dd f[0]; b[0]; f[1]; b[1]; f[2]; b[2]; min({ a, b[0] - f[0], b[1] - f[1], b[2] - f[2] });
    vec<Rational> p(1 + min({ a, b[0] - f[0], b[1] - f[1], b[2] - f[2] }));
    int128 qSum = 0;
    times(size(p), c) qSum += q(c);
    times(size(p), c) p[c] = Rational(q(c), qSum);

    Rational po(0);
    vec<Rational> pp(3);
    times(size(p), c) {
      po = po + p[c] * Rational(c, a);
      times(3, i) pp[i] = pp[i] + p[c] * Rational(f[i] - c, b[i]);
    }
    dd po; pp;

    string ans;
    Rational exp = 0;
    times(Q, j) {
      #define pyon(x, y) \
        exp = exp + (x >= Rational(1, 2) ? x : Rational(1, 1) - x); \
        ans.PB(x >= Rational(1, 2) ? A[y][j] : 'F' + 'T' - A[y][j]);

      if(A[0][j] == A[1][j]) {
        if(A[0][j] == A[2][j]) {
          pyon(po, 0);
        } else {
          pyon(pp[2], 2);
        }
      } else {
        if(A[0][j] == A[2][j]) {
          pyon(pp[1], 1);
        } else {
          pyon(pp[0], 0);
        }
      }
    }
    cout << ans sp << exp.si << "/" << exp.bo ln;
  }

  cout << Rational(((int128)1) << 128);
}
