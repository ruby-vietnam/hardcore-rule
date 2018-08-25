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

Đối với **higher-order function**, tác giả đưa ra một loạt ví dụ minh họa, như là xây dựng một hàm `reduce`, nhận vào một hàm bất kỳ (thể hiện đặc tính của higher-order function) để thực hiện tính toán trên một list, từ đó thực hiện việc tính toán các phép toán bất kỳ chỉ bằng việc kết hợp (compose) các chương trình nhỏ hơn (module) với hàm `reduce`:

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

Về **lazy evaluation**, tác giả giải thích bằng cách đưa ra một ví dụ hết sức đơn giản nhưng mà đọc lâu thiệt lâu mới hiểu: Giả sử có hai chương trình con (hoặc là hàm) `f` và `g`, chúng ta có thể compose chúng như sau:

```haskell
(g . f) input
-- tương đương với
g (f input)
```

Có nghĩa là, ta sẽ gọi hàm `f` với tham số là `input`, đồng thời lấy kết quả trả về để làm tham số cho câu lệnh gọi hàm `g`.

Đặc tính **laziness** của Haskell và các functional programming languages nằm ở chỗ, việc thực thi `f` và `g` diễn ra một cách đồng bộ và chặt chẽ (ai dịch chữ strict synchronisation cho tui với), `f` chỉ được thực thi và trả về giá trị khi `g` thực hiện đọc tham số đầu vào của nó, và `f` cũng sẽ bị dừng khi `g` dừng lại.

> The two programs f and g are run together in strict synchronisation. F is only started once g tries to read some input, and only runs for long enough to deliver the output g is trying to read. Then f is suspended and g is run until it tries to read another input. As an added bonus, if g terminates without reading all of f’s output then f is aborted.

Và trong trường hợp `f` là một hàm sinh ra một tập giá trị có số lượng cực kì lớn, nếu implement trên các ngôn ngữ thông thường (thực thi xong `f`, lấy kết quả, truyền vào `g`) thì có thể sẽ cần một lượng bộ nhớ cực kì lớn, mà có khi là không đủ, ví dụ:

```haskell
-- trả về danh sách các số từ input đến +∞
f input = [input..]
```

Như thế, nhờ vào đặc tính **lazy evaluation**, chúng ta có thể dễ dàng phân tách chương trình thành nhiều module nhỏ mà không cần quá bận tâm đến time và space complexity. Có thể thấy rõ qua ví dụ tính căn bậc 2 dùng phương pháp Newton-Raphson.

Tác giả kết thúc phần kĩ thuật bằng ví dụ ở mục 5: thuật toán Alpha-beta để implement trò chơi tic-tac-toe, minh họa một cách đầy đủ cả hai ứng dụng của **higher-order function** và **lazy evaluation** để định nghĩa `gametree` và sinh ra các nước đi cho cây trò chơi (vốn là một thao tác cực kì tốn kém).

## TL;DR

- **Modularity** là yếu tố quan trọng để phát triển một phần mềm tốt.
- **Higher-order function** và **lazy evaluation** là hai feature quan trọng của các functional programming languages giúp cho việc **modularize** hiệu quả hơn, giúp cho việc phát triển được productive hơn.
- Suy ra Functional Programming đóng vai trò quan trọng trong việc bảo đảm chất lượng và productivity của các dự án phần mềm.

