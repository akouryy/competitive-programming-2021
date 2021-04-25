#define GCJ_CASE
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
#define NDEBUG
#define debug false
#endif
#include<algorithm>
#include<bitset>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits>
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
using VS=vec<string>;using VI=vec<int>;
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
TL<TN T>Rdebug1(' ',vec<T>)TL<TN T>Rdebug1(' ',set<T>)TL<TN T,TN S>Rdebug1(' ',map<T,S>)TL<TN T>Rdebug1('\n',vvec<T>)
TL<TN T>Rdebug1('\n',vec<set<T>>)TL<TN T,TN S>Rdebug1('\n',vec<map<T,S>>)TL<TN T>Rdebug1('\n',set<vec<T>>)
TL<TN T>Rdebug1('\n',set<set<T>>)TL<TN T,TN S>Rdebug1('\n',set<map<T,S>>)
#line 6001 "base.hpp"//3
signed main(){if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#line 1001 "3.cpp"//
//#include "consts.hpp"

#define int128 __int128_t
#line 1 "math.hpp"//mint(3)
IL int int_abs(int k){RT k>=0?k:-k;}IL int int_sign(int k){RT k>0?1:k==0?0:-1;}
int gcd(int a,int b){int t;while(b)t=b,b=a%b,a=t;RT int_abs(a);}
#line 2001 "math_rational.hpp"//3
std::ostream&OP<<(std::ostream&dest,__int128_t value){std::ostream::sentry s(dest);if(s){
__uint128_t tmp=value<0?-value:value;char buffer[128];char*d=std::end(buffer);do{--d;*d="0123456789"[tmp%10];tmp/=10;
}while(tmp!=0);if(value<0){--d;*d='-';}int len=std::end(buffer)-d;if(dest.rdbuf()->sputn(d,len)!=len){
dest.setstate(std::ios_base::badbit);}}RT dest;}struct Rational{int128 si,bo;
Rational(int128 s=0,int128 b=1,bool do_gcd=true){if(b==0){bo=b;si=int_sign(s);}else{
int128 g=IF(do_gcd&&b!=1,gcd(s,b),1);si=s/g*int_sign(b);bo=IF(si,int_abs(b)/g,1);}}Rational OP+(CS Rational&r)CS{
RT{si*r.bo+r.si*bo,bo*r.bo};}Rational OP-(CS Rational&r)CS{RT{si*r.bo-r.si*bo,bo*r.bo};}Rational OP*(CS Rational&r)CS{
RT{si*r.si,bo*r.bo};}Rational OP/(CS Rational&r)CS{RT{si*r.bo,bo*r.si};}
CMPOPS(Rational,(int128)si*r.bo,(int128)r.si*bo,r)explicit OP int()CS{RT floor();}int floor()CS{RT divide(si,bo);}
int ceil()CS{RT divide(si+bo-1,bo);}explicit OP LD()CS{RT(LD)si/bo;}friend ostream&OP<<(ostream&o,CS Rational&r){
RT o<<"("<<r.si<<"/"<<r.bo<<")";}};
#line 1 "math_inv.hpp"//3nf
/*!http://hos.ac/slides/20130319_enumeration.pdf*/
TL<int m=MOD>class Inver{using M=MInt<m>;int n;vec<M>inv;public:Inver(int k){n=0;extend(k);}void extend(int k){
assert(k>=1);if(n<k){inv.resize(k+1);inv[0]=M(0);inv[1]=M(1);upto(max(n,2LL),k,i)inv[i]=-M(m/i)*inv[m%i];n=k;}}
M OP[](int i)CS{assert(0<i&&i<=n);RT inv[i];}M OP[](M x)CS{RT*this[x.v];}};
#line 2001 "fact.hpp"//3n
/*!http://hos.ac/slides/20130319_enumeration.pdf*/
TL<int m=MOD>class Fact{using M=MInt<m>;Inver<m>*inver;int n;vec<M>f,v;public:Fact(int k,Inver<m>*inver):inver(inver){
n=0;extend(k);}void extend(int k){assert(0<=k&&k<m);if(n<k){inver->extend(k);f.resize(k+1);v.resize(k+1);
f[0]=v[0]=M(1);upto(max(n,1LL),k,i)f[i]=f[i-1]*M(i),v[i]=v[i-1]*(*inver)[i];n=k;}}M OP[](int i)CS{assert(0<=i&&i<=n);
RT f[i];}M finv(int i)CS{assert(0<=i&&i<=n);RT v[i];}};
#line 2001 "nck.hpp"//3
/*!https://twitter.com/meguru_comp/status/694547019885449216*/
TL<int m>IL MInt<m>nCk(int n,int k,CS Fact<m>&f){RT IF(0<=k&&k<=n,f[n]*f.finv(k)*f.finv(n-k),MInt<m>(0));}TL<int m>
IL MInt<m>nPk(int n,int k,CS Fact<m>&f){RT IF(0<=k&&k<=n,f[n]*f.finv(n-k),MInt<m>(0));}
#line 3001 "3.cpp"//

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

    {if(debug)cerr<<'#'<<__LINE__ ln<<"  sameCorrect:                    "<<(sameCorrect)ln<<"  sameWrong:                      "<<(sameWrong)ln<<"  (nDiff + abs(S[0] - S[1])) / 2: "<<((nDiff + abs(S[0] - S[1])) / 2)ln;}
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
    {if(debug)cerr<<'#'<<__LINE__ ln<<"  f[0]:                                              "<<(f[0])ln<<"  b[0]:                                              "<<(b[0])ln<<"  f[1]:                                              "<<(f[1])ln<<"  b[1]:                                              "<<(b[1])ln<<"  f[2]:                                              "<<(f[2])ln<<"  b[2]:                                              "<<(b[2])ln<<"  min({ a, b[0] - f[0], b[1] - f[1], b[2] - f[2] }): "<<(min({ a, b[0] - f[0], b[1] - f[1], b[2] - f[2] }))ln;}
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
    {if(debug)cerr<<'#'<<__LINE__ ln<<"  po: "<<(po)ln<<"  pp: "<<(pp)ln;}
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
