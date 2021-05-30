#line 1 "base.hpp"//3
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
#ifndef INT_IS_SIGNED
#define int LL
#endif
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
#line 1 "base_util.hpp"//3b
#define BINOPa(t,u,op)t OP op(CS u&o)CS{RT t(*this)op##=o;}
#define CMPOP(t,op,f1,f2,x)bool OP op(CS t&x)CS{RT f1 op f2;}
#define CMPOPS(t,f1,f2,x)CMPOP(t,==,f1,f2,x)CMPOP(t,!=,f1,f2,x)\
CMPOP(t,<,f1,f2,x)CMPOP(t,<=,f1,f2,x)CMPOP(t,>,f1,f2,x)CMPOP(t,>=,f1,f2,x)

#define TLA TL<TN A>
#define TLB TL<TN A,TN B>
#line 1 "mod.hpp"//3b
#ifndef MOD
#define MOD 1000000007
#endif
#if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
#error mod
#endif
#line 1 "power.hpp"//3bm
TL<TN T>IL T power(T x,int n){T r(1);for(;n;n/=2){if(n%2)r*=x;x*=x;}RT r;}IL int pow_mod(int x,int n,int m){int r=1;
for(;n;n/=2){if(n%2)r=r*x%m;x=x*x%m;}RT r;}
#line 2001 "mod.hpp"//3b
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
#line 1 "typedefs.hpp"//3b
using unit = tuple<>;using LD=long double;TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;TL<TN T>using vvvec=vec<vvec<T>>;TL<TN T>using vvvvec=vec<vvvec<T>>;
TL<TN T>using pq_gt=priority_queue<T,vec<T>,greater<T>>;
using VI=vec<int>;
#line 1 "alias.hpp"//3b
#define EB emplace_back
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
#line 1 "util.hpp"//3b
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
#line 1 "debug.hpp"//3b
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
#line 6001 "base.hpp"//3
#ifndef CUSTOM_MAIN
signed main(){if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#endif
#line 1001 "3.cpp"//
//#include "consts.hpp"

int N, ansSize; VI P, ans;

void query(int i) {
  // dd i;
  assert((ansSize % 2 == i % 2));
  /*if(ansSize % 2 != i % 2) {
    bool found = false;
    times(N-1, j) if(ansSize % 2 == j % 2 && P[j] > P[j+1]) {
      found = true;
      query(j, fallback_begin);
    }
    if(!found) {
      assert(fallback_begin >= 0);
      query(fallback_begin + (fallback_begin + ansSize) % 2, -1);
    }

    // int cand = N - 2 - (N + ansSize) % 2;
    // if(i < N - 3) {
    //   query(cand);
    // } else if(i == N-1 && cand == N-3) {
    //   query(cand);
    // } else {
    //   query(ansSize % 2);
    // }
  }*/
  ans.PB(i);
  ++ansSize;
  swap(P[i], P[i+1]);
  {if(debug)cerr<<'#'<<__LINE__ ln<<"  P:       "<<(P)ln<<"  ans:     "<<(ans)ln<<"  ansSize: "<<(ansSize)ln;}
}

void solve() {
  /* wt.ten
    T
  */
  int T;cin>>T;

  times(T, t) {
    /* wt.ten
      N NP
    */
    cin>>N;P.resize(N);times(N,i0){cin>>P[i0];}
    {if(debug)cerr<<"P: "<<(P)ln;}
    ans.clear();
    ansSize = 0;
    VI goal(N); times(N, i) goal[i] = i+1;

    while(goal != P) {
      bool found = false;
      times(N-1, j) if(ansSize % 2 == j % 2 && P[j] > P[j+1]) {
        found = true;
        query(j);
        break;
      }
      if(!found) {
        int m = 0, mj = 0;
        times(N-1, j) if(ansSize % 2 == j % 2 && amax(m, P[j])) {
          mj = j;
        }
        query(mj);
      }
    }

    // times(N, x) {
    //   int zp; times(N, i) if(P[i] == x+1) zp = i;
    //   downto(zp-1, x, i) query(i, i+2 <= N-2 ? i+2 : 0);

    //   if(1 <= x && x <= N-2) while(P[0] != 1 || P[1] != 2) query(ansSize % 2, -1);
    //   if(1 <= x && x <= N-2) while(P[x-1] != x || P[x] != x+1) query(x-1 + (x-1 + ansSize) % 2, -1);
    // }

    // while(P[0] != 1 || P[1] != 2 || N>=3 && P[2] != 3) query(ansSize % 2, -1);


    // while(P[N-1] != N || P[N-2] != N-1 || N>=3 && P[N-3] != N-2) query(N - 2 - (N + ansSize) % 2);

    // int first; times(N, i) if(P[i] == 1) first = i;
    // downto(first-1, 1, i) query(i);
    // if(first >= 1) {
    //   if(size(ans) % 2 == 1) {
    //     query(N-2);
    //   }
    //   query(0);
    // }

    // uptil(1, N-1, i) {
    //   downto(N-1, i+1, j) {
    //     if(P[j-1] > P[j]) query(j-1);
    //   }
    // }

    cout << size(ans) ln;
    times(size(ans), i) {
      cout << (i ? " " : "") << ans[i]+1;
    }
    cout ln;
  }


}
