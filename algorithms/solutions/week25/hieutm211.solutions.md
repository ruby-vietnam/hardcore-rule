## Problem 1

//beats 100.00 % of cpp submissions

```cpp
class Solution {
public:
    
    vector<string> findWords(vector<string>& words) {
        int row[3] = {0, 0, 0};
        int p;
        bool isRow[3];
        vector<string> ans;
        
        //init row[]
        
        row[0] |= (1 << ('Q' - 'A'));
        row[0] |= (1 << ('W' - 'A'));
        row[0] |= (1 << ('E' - 'A'));
        row[0] |= (1 << ('R' - 'A'));
        row[0] |= (1 << ('T' - 'A'));
        row[0] |= (1 << ('Y' - 'A'));
        row[0] |= (1 << ('U' - 'A'));
        row[0] |= (1 << ('I' - 'A'));
        row[0] |= (1 << ('O' - 'A'));
        row[0] |= (1 << ('P' - 'A'));
        
        row[1] |= (1 << ('A' - 'A'));
        row[1] |= (1 << ('S' - 'A'));
        row[1] |= (1 << ('D' - 'A'));
        row[1] |= (1 << ('F' - 'A'));
        row[1] |= (1 << ('G' - 'A'));
        row[1] |= (1 << ('H' - 'A'));
        row[1] |= (1 << ('J' - 'A'));
        row[1] |= (1 << ('K' - 'A'));
        row[1] |= (1 << ('L' - 'A'));
        
        row[2] |= (1 << ('Z' - 'A'));
        row[2] |= (1 << ('X' - 'A'));
        row[2] |= (1 << ('C' - 'A'));
        row[2] |= (1 << ('V' - 'A'));
        row[2] |= (1 << ('B' - 'A'));
        row[2] |= (1 << ('N' - 'A'));
        row[2] |= (1 << ('M' - 'A'));
        
        //Solve
        
        for (auto &str : words){
            if (str == "") continue;
            for (int i = 0; i < 3; ++i) isRow[i] = 1;
            for (auto &c : str){
                p = ('a' <= c && c <= 'z' ? c - 'a' : c - 'A');
                for (int i = 0; i < 3; ++i)
                    if (((1 << p) & row[i]) == 0) isRow[i] = 0;
            }
            if (!isRow[0] && !isRow[1] && !isRow[2]) continue;
            ans.push_back(str);            
        }
        return ans;
    }
};
```

## Problem 3

```cpp

#include <bits/stdc++.h>
using namespace std;

int n, a[2005], cnt1;

int gcd(int a, int b){
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  cin >> n;
  for (int i = 1; i <= n; ++i){
    cin >> a[i];
    cnt1 += (a[i] == 1);
  }

  if (cnt1 != 0) cout << n-cnt1 << endl;
  else{
    int L, R;
    L = -1; R = n+1;
    for (int i = 1; i <= n-1; ++i){
      int x = a[i];
      for (int j = i+1; j <= n; ++j){
        x = gcd(x, a[j]);
        if (x == 1 && R-L > j-i){
          L = i; R = j; 
          break;
        }
      }
    }
    if (L == -1) cout << -1 << endl;
    else cout << (R-L) + n-1 << endl;
  }

  return 0;
}
```

## Problems 4

```pascal
uses math;
const
  inp = 'input.txt';
  out = 'output.txt';
  maxn = 50005;
  oo = maxlongint;
var
  n, m, i : Longint;
  a, t : array[0..4*maxn] of longint;
 
procedure update(k, l, r, i, v : longint);
  var mid : longint;
  begin
    if (i < l) or (i > r) then exit;
    if (l = r) then
      begin
        t[k] := v;
        exit;
      end;
    mid := (l + r) div 2;
    update(k*2, l, mid, i, v);
    update(k*2+1, mid + 1, r, i, v);
    t[k] := max(t[2*k], t[2*k+1]);
  end;
 
function  get(i, l, r, u, v : longint) : longint;
  var mid, get1, get2 : Longint;
  begin
    if (l >= u) and (v >= r) then exit(t[i]);
    if (v < l) or (r < u) then exit(-oo);
    mid := (l + r) div 2;
    get1 := get(i*2, l, mid, u, v);
    get2 := get(i*2+1, mid + 1, r, u, v);
    exit(max(get1, get2));
  end;
 
procedure init;
  var i, u, v, k : Longint;
  begin
    readln(n, m);
    for i := 1 to m do
      begin
        readln(u, v, k);
        inc(a[u], k);
        dec(a[v+1], k);
      end;
    for i := 1 to n do a[i] := a[i] + a[i-1];
    for i := 1 to n do update(1, 1, n, i, a[i]);
  end;
 
procedure solve;
  var q, u, v : longint;
  begin
    readln(q);
    for i := 1 to q do
      begin
        readln(u, v);
        writeln(get(1, 1, n,u, v));
      end;
  end;
 
begin
  init;
  solve;
end.
```
