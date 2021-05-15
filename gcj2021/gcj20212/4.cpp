#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int gcj_case_id) {
  /* wt.ten
    R C F S R"P R"Q
  */
  int R,C,F,S;cin>>R>>C>>F>>S;VS P(R);times(R,i0){cin>>P[i0];}VS Q(R);times(R,i0){cin>>Q[i0];}

  VWI dp(R+1, WI(C+1, VI(1<<C, LLONG_MAX/2)));
  dp[0][0][0] = 0;

  #define MYP(i,j) ((P[i][j]=='M') ^ ((h >> (j)) & 1))
  #define MYQ(i,j) (Q[i][j]=='M')

  times(R, i) {
    times(C, j) {
      times(1<<C, h) {
        if(MYP(i,j) == MYQ(i,j)) {
          amin(dp[i][j+1][h & ~(1<<j)], dp[i][j][h]);
        } else {
          amin(dp[i][j+1][h & ~(1<<j)], dp[i][j][h] + F);
          // if(j+1 < C && MYP(i,j) != MYP(i,j+1) && MYP(i,j+1) != MYQ(i,j+1)) {
          //   amin(dp[i][j+2][h & ~(1<<j) & ~(1<<j+1)], dp[i][j][h] + S);
          // }
          // if(i+1 < R && MYP(i,j) != MYP(i+1,j) && MYP(i+1,j) != MYQ(i+1,j)) {
          //   amin(dp[i][j+1][h | (1<<j)], dp[i][j][h] + S);
          // }

          if(j+1 < C && (MYP(i,j) != MYP(i,j+1)) == (MYP(i,j+1) != MYQ(i,j+1))) {
            amin(dp[i][j+1][h & ~(1<<j) ^ (1<<j+1)], dp[i][j][h] + S);
          }
          if(i+1 < R && MYP(i,j) != MYP(i+1,j) /*&& MYP(i+1,j) != MYQ(i+1,j)*/) {
            amin(dp[i][j+1][h | (1<<j)], dp[i][j][h] + S);
          }
        }
      }
    }
    dp[i+1][0] = dp[i][C];
  }
  dd dp;

  cout << dp[R][0][0] ln;
}
