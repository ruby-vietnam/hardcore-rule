### Problems 1 [Count and say](https://leetcode.com/problems/count-and-say/description/)

```scala
object Solution {
  def countAndSay(n: Int): String = {
    Stream.from(1).take(n - 1).foldLeft("1") { case (acc, _) =>
      (acc + '$').foldLeft(("", '_', 0)) { case ((res, currentChar, count), c) =>
        if (currentChar == c) {
          (res, currentChar, count + 1)
        } else {
          val newStr = if (currentChar == '_') {
            res
          } else {
            res + count.toString + currentChar
          }
          (newStr, c, 1)
        }
      }._1
    }
  }
}
```

### Problems 2 [Elevator Trouble](https://www.spoj.com/problems/ELEVTRBL/)
```C++
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define PII pair<int, int>
int visited[1000001]; 
queue<PII> q;

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	q.push(PII(s, 0));
	visited[s] = 1;
	while (q.size() > 0) {
		PII current = q.front(); q.pop();
		int floor = current.first;
		int steps = current.second;
		if (floor == g) {
			cout << steps << endl;
			return 0;
		}
		int up = floor + u;
		if (up <= f && !visited[up]) {
			visited[up] = 1;
			q.push(PII(up, steps + 1));
		}
		int down = floor - d;
		if (down > 0 && !visited[down]) {
			visited[down] = 1;
			q.push(PII(down, steps + 1));
		}
		if (up == g || down == g) {
			cout << steps + 1 << endl;
			return 0;
		}
 	}
 	cout << "use the stairs" << endl;
	return 0;
}
```

### Problem 3 [Mimimize the errors](http://codeforces.com/problemset/problem/960/B)
```scala
import java.util.Scanner

object MinimizeErrors extends App {

  val input = scala.io.StdIn.readLine()
  val inputScanner = new Scanner(input)
  val n = inputScanner.nextInt()
  val k1 = inputScanner.nextLong()
  val k2 = inputScanner.nextLong()

  val array1Input = scala.io.StdIn.readLine()
  val array1InputScanner = new Scanner(array1Input)
  val array1 = (1 to n).map { _ =>
    array1InputScanner.nextLong()
  }

  val array2Input = scala.io.StdIn.readLine()
  val array2InputScanner = new Scanner(array2Input)
  val array2 = (1 to n).map { _ =>
    array2InputScanner.nextLong()
  }

  val (_, _, remain, error) = array1.zip(array2)
    .map { case (a, b) => Math.abs(a - b) }
    .sorted
    .reverse
    .:+(0.toLong)
    .foldLeft((-1.toLong, 0.toLong, k1 + k2, 0.toLong)) { case ((last, cnt, remain, error), current) =>
      if (current == last) {
        (last, cnt + 1, remain, error)
      } else {
        val diff = last - current
        if (diff * cnt <= remain) {
          (current, cnt + 1, remain - diff * cnt, error)
        } else {
          val height = remain / cnt
          val r = remain % cnt
          val newError = error + r * (last - height - 1)*(last - height - 1) + (cnt - r) * (last - height)*(last - height)
          (current, 1.toLong, 0.toLong, newError)
        }
      }
    }

    println(error + remain % 2)
}
```
