#define GCJ_CASE
#line 1 "base.hpp"//2
#ifndef __clang__
#pragma GCC optimize ("O3")
#endif
void solve(
#ifdef GCJ_CASE
long long case_id
#endif
);
#if defined(EBUG) && !defined(ONLINE_JUDGE)
#define debug true
#define _GLIBCXX_DEBUG
// #define _LIBCPP_DEBUG 0
#define _LIBCPP_DEBUG2 0
#else
#define NDEBUG 1
#define debug false
#endif
#include<algorithm>
#include<bitset>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<type_traits>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define int LL
#define CS const
#define CX constexpr
#define IL inline
#define OP operator
#define RT return
#define TL template
#define TN typename
#define lambda [&]
#define rep(f,t,i,c,u)for(int Rb_=(t),i=(f);i c Rb_;u(i))
#define upto(f,t,i)rep(f,t,i,<=,++)
#define uptil(f,t,i)rep(f,t,i,<,++)
#define downto(f,t,i)rep(f,t,i,>=,--)
#define downtil(f,t,i)rep(f,t,i,>,--)
#define times(n,i)uptil(0,n,i)
#define rtimes(n,i)downto((n)-1,0,i)
#define iter(v)begin(v),end(v)
#define citer(v)cbegin(v),cend(v)
#define riter(v)rbegin(v),rend(v)
#define criter(v)crbegin(v),crend(v)
#define IF(a,b,c)((a)?(b):(c))
#if debug
#define ln <<endl
#else
#define ln <<'\n'
#endif
#define tb <<'\t'
#define sp <<' '
#line 1 "base_util.hpp"//2b
#define BINOPa(t,u,op)t OP op(CS u&o)CS{RT t(*this)op##=o;}
#define CMPOP(t,op,f1,f2,x)bool OP op(CS t&x)CS{RT f1 op f2;}
#define CMPOPS(t,f1,f2,x)CMPOP(t,==,f1,f2,x)CMPOP(t,!=,f1,f2,x)\
CMPOP(t,<,f1,f2,x)CMPOP(t,<=,f1,f2,x)CMPOP(t,>,f1,f2,x)CMPOP(t,>=,f1,f2,x)

#define TLA TL<TN A>
#define TLB TL<TN A,TN B>
#line 1 "mod.hpp"//2b
#ifndef MOD
#define MOD 1000000007
#endif
#if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
#error mod
#endif
#line 1 "power.hpp"//2bm
TL<TN T>IL T power(T x,int n){T r(1);for(;n;n/=2){if(n%2)r*=x;x*=x;}RT r;}IL int pow_mod(int x,int n,int m){int r=1;
for(;n;n/=2){if(n%2)r=r*x%m;x=x*x%m;}RT r;}
#line 2001 "mod.hpp"//2b
IL CX int modulo(int a,int b){a%=b;RT a&&(a>0)!=(b>0)?a+b:a;}IL CX int divide(int a,int b){RT(a-modulo(a,b))/b;}
TL<int d=MOD>struct MInt{
/*!https://ei1333.github.io/luzhiled/snippets/other/mod-int.html*/
int v;CX MInt():v(0){}explicit CX MInt(int i):v(modulo(i,d)){}MInt&OP+=(CS MInt&m){v+=m.v;if(v>=d)v-=d;RT*this;}
MInt&OP-=(CS MInt&m){v-=m.v;if(v<0)v+=d;RT*this;}MInt&OP*=(CS MInt&m){v=v*m.v%d;RT*this;}MInt&OP/=(CS MInt&m){
RT*this*=m.inv();}BINOPa(MInt,MInt,+)BINOPa(MInt,MInt,-)BINOPa(MInt,MInt,*)BINOPa(MInt,MInt,/)MInt OP-()CS{
RT MInt()-=*this;}CMPOP(MInt,==,v,m.v,m)CMPOP(MInt,!=,v,m.v,m)MInt pow(int n)CS{RT power(*this,n);}MInt inv()CS{
int a=v,b=d,x=1,y=0;while(b){swap(y,x-=a/b*y);swap(b,a%=b);}RT(MInt)x;}
friend ostream&OP<<(ostream&o,CS MInt&m){RT o<<m.v;}friend istream&OP>>(istream&i,MInt&m){i>>m.v;m.v%=d;RT i;}};
using mint=MInt<>;CX mint OP"" _m(ULL n){RT mint(n);}CX MInt<998244353>OP"" _m998244353(ULL n){RT MInt<998244353>(n);}
CX MInt<1000000007>OP"" _m1e9_7(ULL n){RT MInt<1000000007>(n);}
CX MInt<1000000009>OP"" _m1e9_9(ULL n){RT MInt<1000000009>(n);}
#line 1 "typedefs.hpp"//2b
using unit = tuple<>;using LD=long double;TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;TL<TN T>using vvvec=vec<vvec<T>>;TL<TN T>using vvvvec=vec<vvvec<T>>;
TL<TN T>using pq_gt=priority_queue<T,vec<T>,greater<T>>;
using VI=vec<int>;using VB=vec<bool>;using HII=map<int, int>;using WI=vvec<int>;
#line 1 "alias.hpp"//2b
#define EB emplace_back
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
#line 1 "util.hpp"//2b
TL<TN T>IL bool amax(T&v,CS T&a){RT v<a&&(v=a,1);}TL<TN T>IL bool amin(T&v,CS T&a){RT v>a&&(v=a,1);}
TL<TN T>IL int sizeRAB(T t){RT t.size();}
#define size sizeRAB
#define clamp clampRAB
TL<TN T>IL CX CS T&clamp(CS T&a,CS T&l,CS T&r){RT a<l?l:r<a?r:a;}TL<TN V>IL void uniq2(V&v){
v.erase(unique(iter(v)),v.end());}TL<TN V>IL void uniq(V&v){sort(iter(v));uniq2(v);}
#define leftmost_ge lower_bound
#define leftmost_gt upper_bound
TL<TN C,TN D>IL decltype(end(C()))rightmost_le(CS C&set,CS D&d){auto l=set.leftmost_gt(d);
RT l==begin(set)?end(set):--l;}TL<TN C,TN D>IL decltype(end(C()))rightmost_lt(CS C&set,CS D&d){
auto l=set.leftmost_ge(d);RT l==begin(set)?end(set):--l;}TL<TN C,TN D>IL C rightmost_le(CS C&from,CS C&to,CS D&d){
auto l=leftmost_gt(from,to,d);RT l==from?to:--l;}TL<TN C,TN D>IL C rightmost_lt(CS C&from,CS C&to,CS D&d){
auto l=leftmost_ge(from,to,d);RT l==from?to:--l;}namespace rab{TL<TN I>IL bool is_in(I x,I l,I r){RT l<=x&&x<r;}
TL<TN T>IL T fetch(CS T&d,CS vec<T>&v,int i){RT 0<=i&&i<size(v)?v[i]:d;}}
#line 1 "debug.hpp"//2b
TL<TN T,TN S>IL ostream&OP<<(ostream&s,CS pair<T,S>&p);TL<TN T,TN U,TN V>IL ostream&OP<<(ostream&s,CS tuple<T,U,V>&p);
TL<TN T>IL ostream&OP<<(ostream&s,CS vec<T>&p);TL<TN T>IL ostream&OP<<(ostream&s,CS set<T>&p);TL<TN T,TN S>
IL ostream&OP<<(ostream&s,CS map<T,S>&p);TL<TN T>IL ostream&OP<<(ostream&s,CS vvec<T>&p);TL<TN T,TN S>
IL ostream&OP<<(ostream&s,CS vec<map<T,S>>&p);TL<TN T>IL istream&OP>>(istream&s,vec<T>&v){for(auto&&p:v)s>>p;RT s;}
TL<TN T,TN S>IL ostream&OP<<(ostream&s,CS pair<T,S>&p){RT s<<"("<<p.first<<","<<p.second<<")";}TL<TN T,TN U,TN V>
IL ostream&OP<<(ostream&s,CS tuple<T,U,V>&p){RT s<<"("<<get<0>(p)<<","<<get<1>(p)<<","<<get<2>(p)<<")";}
#define Rdebug1(sep, ...)IL ostream& OP<<(ostream&s,CS __VA_ARGS__&v){\
int i=0;for(CS auto&e:v){i++&&s<<sep;s<<e;}RT s;}
TL<TN T>Rdebug1(' ',vec<T>)TL<TN T>Rdebug1(' ',set<T>)TL<TN T>Rdebug1(' ',deque<T>)TL<TN T,TN S>Rdebug1(' ',map<T,S>)
TL<TN T>Rdebug1('\n',vvec<T>)TL<TN T>Rdebug1('\n',vec<set<T>>)TL<TN T,TN S>Rdebug1('\n',vec<map<T,S>>)
TL<TN T>Rdebug1('\n',set<vec<T>>)TL<TN T>Rdebug1('\n',set<set<T>>)TL<TN T,TN S>Rdebug1('\n',set<map<T,S>>)
#line 6001 "base.hpp"//2
signed main(){if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#line 1001 "2.cpp"//
//#include "consts.hpp"
#line 1 "power_128.hpp"//2p
using int128=__int128;
int128 pow_mod128(int128 x,int n,int m){int128 rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
#line 2001 "prime.hpp"//2
/*!
  https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
  http://joisino.hatenablog.com/entry/2017/08/03/210000
  https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95
*/
VI rab_prime_mr_as = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
bool is_prime(int n) {
  assert(n >= 0);
  if(n <= 3) return n >= 2;
  if(n % 2 == 0 || n % 3 == 0) return false;
  if(n < (1<<28)) {
    for(int i = 5; i * i <= n; i += 6) {
      if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
  } else {
    int d = n - 1, s1 = -1;
    while(d % 2 == 0) { d /= 2; ++s1; }
    for(int a : rab_prime_mr_as) {
      if(n == a) return true;
      int128 f = pow_mod128(a, d, n);
      if(f == 1 || f == n - 1) continue;
      times(s1, r) {
        f = f * f % n;
        if(f == n - 1) goto next_a;
      }
      return false;
      next_a:;
    }
    return true;
  }
}

/* O(NloglogN) */
VB are_primes(int n) {
  assert(n >= 0);
  VB ret(n + 1, true);
  for(int j = 0; j <= n; j += 2) ret[j] = false;
  if(n > 0) ret[1] = false;
  for(int i = 3; i * i <= n; i += 2)
    if(ret[i])
      for(int j = i * i; j <= n; j += i * 2)
        ret[j] = false;
  return ret;
}
HII prime_factor(int n) {
  HII ret;
  if(n <= 1) return ret;

  #define rab_prime_factor_loop_body(x) \
    while(n % (x) == 0) { ++ret[(x)]; n /= (x); }

  rab_prime_factor_loop_body(2);
  rab_prime_factor_loop_body(3);

  for(int i = 5; i * i <= n; i += 6) {
    rab_prime_factor_loop_body(i);
    rab_prime_factor_loop_body(i + 2);
  }
  if(n > 1) ++ret[n];
  return ret;
}
#line 2001 "2.cpp"//

void solve(int gcj_case_id) {
  /* wt.ten
    N
  */
  signed N;cin>>N;

  vec<signed> dp(N + 1, INT_MIN/2);
  dp[N] = 0;
  downto(N, 1, j) if(dp[j] >= 0) {
    for(signed k = 1; k * k <= j; ++k) if(j % k == 0) {
      if(k >= (j == N ? 3 : 2))     amax(dp[j / k - 1], dp[j] + 1);
      if(j / k >= (j == N ? 3 : 2)) amax(dp[k - 1], dp[j] + 1);
    }
  }
  cout << dp[0] ln;

  /*
  WI dp(N + 1);
  {if(debug)cerr<<"dp[0]: "<<(dp[0])ln;}
  upto(1, N, i) dp[i] = VI(N / i + 1, LLONG_MIN/2);
  dp[1][N] = 0;

  upto(1, N, i) {
    if(!(i&255)) cerr<<i ln;
    times(N / i + 1, j) {
      upto(2, j, k) if(j % k == 0) {
        amax(dp[i * k][j / k - 1], dp[i][j] + 1);
      }
    }
    // dd dp;
  }

  // dd dp;

  int ans = 0;
  upto(1, N, i) amax(ans, dp[i][0]);
  cout << ans ln;
  */

  /*
  int ans = 0, before = 1;
  while(N > before * 2) {
    ++ans;
    HII k = prime_factor(N / before);
    {if(debug)cerr<<'#'<<__LINE__ ln<<"  N / before: "<<(N / before)ln<<"  k:          "<<(k)ln;}
    if(ans == 1) { // 
      if(k.count(2)) {
        // dd k.count(2)&&k[2]; k.count(3)&&k[3]; *begin(k);
        if(k.count(3)) {
          before = 3;
        } else if(k[2] >= 2) {
          before = 4;
        } else {
          auto it = begin(k);
          ++it;
          before = it->first;
        }
      } else {
        {if(debug)cerr<<"*begin(k): "<<(*begin(k))ln;}
        before = begin(k)->first;
      }
    } else {
      before *= begin(k)->first;
    }
    N -= before;

    {if(debug)cerr<<'#'<<__LINE__ ln<<"  ans:    "<<(ans)ln<<"  before: "<<(before)ln<<"  N:      "<<(N)ln;}
  }
  cout << ans ln;
  */

}
