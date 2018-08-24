Why Functional Programming Matters
===

https://academic.oup.com/comjnl/article/32/2/98/543535

## Review

Đây là một trong số những paper mà bất cứ ai quan tâm đến computer science đều phải đọc ít nhất một lần trong đời, và khá là dễ đọc, trừ vụ code minh họa được viết bằng Miranda (a.k.a daed lang :kappa:), trông khá giống với Haskell.

Quan điểm mà tác giả John Huges đưa ra trong bài là: **Một dự án phần mềm cần phải được tổ chức một cách tốt nhất có thể, để dễ viết hơn, dễ debug hơn, reuse code tốt hơn.** Và yếu tố quan trọng nhất để có một cấu trúc project tốt là **Modularity** (chia project thành nhiều module nhỏ).

Tác giả viết:

> Modular design brings with it great productivity improvements. First of all, **small modules can be coded quickly and easily**. Secondly, **general purpose modules can be re-used**, leading to **faster development** of subsequent programs. Thirdly, **the modules of a program can be tested independently**, helping to **reduce the time spent debugging**.

Vậy modularize là làm gì? Là chia nhỏ nó ra thành nhiều bài toán con, giải từng bài con đó rồi tổng hợp chúng lại:

> When writing a modular program to solve a problem, one first **divides the problem into sub- problems**, then **solves the sub-problems** and **combines the solutions**.

Và các functional programming languages cung cấp cho chúng ta 2 features quan trọng để phục vụ cho việc modularize, đó là:

- Higher-order Function
- Lazy Evaluation

Đối với **higher-order function**, tác giả đưa ra một loạt ví dụ minh họa, như là xây dựng một hàm `reduce`, nhận vào một hàm bất kỳ (thể hiện đặc tính của higher-order function) để thực hiện tính toán trên một list, từ đó thực hiện việc tính toán các phép toán bất kỳ chỉ bằng việc kết hợp các chương trình nhỏ hơn (module) với hàm `reduce`:

```haskell
reduce :: (a -> a -> a) -> a -> [a] -> a
reduce f a [] = a
reduce f a (x:xs) = f x (reduce f a xs)

-- tính tổng một list
add a b = a + b
sum = reduce add 0
sum [1, 2, 3, 4] == 10

-- tính tích một list
multiply a b = a * b
product = reduce multiply 1
product [1, 2, 3, 4] == 24
```

Về **lazy evaluation**...
(Còn nữa)

## Kết luận
