## Problem 1 - [K-based Numbers](http://acm.timus.ru/problem.aspx?space=1&num=1009)

```pascal
var n,k         : byte;
    a           : array[1..20,0..10]of qword;
    h,i,j       : byte;
    tong        :longint;
begin
  read(n,k);
  for j:=0 to k-1 do a[1,j]:=1;
  for i:=2 to n do
    for j:=0 to k-1 do
      begin
        a[i,j]:=0;
        if j=0 then
          begin
            for h:=1 to k-1 do a[i,j]:=a[i,j]+a[i-1,h];
          end else
          begin
            for h:=0 to k-1 do a[i,j]:=a[i,j]+a[i-1,h];
          end;
      end;
  tong:=0;
  for j:=1 to k-1 do tong:=tong+a[n,j];
  write(tong);
end.
```

## Problem 3 - [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/description/)

```go
func possibleBipartition(N int, dislikes [][]int) bool {
    // store group
    group := make([]byte, N + 1)
    
    // temporary store bfs
    bfs := make([]int, N)
    
    // build edges
    edges := make([][]int, N + 1)
    for i := 1; i <= N; i++ {
        edges[i] = make([]int, 0, 10)
    }
    var u, v int
    for _, edge := range dislikes {
        u, v = edge[0], edge[1]
        edges[u] = append(edges[u], v)
        edges[v] = append(edges[v], u)
    }
    
    // try to partitioning
    for i := 1; i <= N; i++ {
        if group[i] == 0 && !partition(i, group, edges, bfs) { // 
            return false
        }
    }
    
    return true
}

func partition(u int, group []byte, edges [][]int, bfs []int) bool {
    start, end := 0, 0
    bfs[0] = u
    group[u] = 1
    
    e := end
    for start <= end {
        for i := start; i <= end; i++ {
            u = bfs[i]
            for _, v := range edges[u] {
                if group[u] == group[v] {
                    return false
                } else if group[v] == 0 {
                    e++
                    bfs[e], group[v] = v, 3 - group[u]
                }
            }
        }
        
        start, end = end + 1, e
    }
    
    return true
}
```