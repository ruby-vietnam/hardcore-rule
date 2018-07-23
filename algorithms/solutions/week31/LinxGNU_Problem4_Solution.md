##### Idea:
Công thức khá kinh điển của Subarray sum là:
- Gọi Si = sum(0 -> i). 
- Vậy subarray [j; i) sẽ có sum là: Si - Sj

##### Approach:
Nói cách khác mình cần tìm i và j sao cho Si - Sj >= K và i-j là min.

##### Solution 1 với Fenwick tree:
- Từ công thức trên, tại mỗi i, ta cần tìm j < i sao cho Si - Sj >= K 
hay nói cách khác Si - K >= Sj và j là max.
j là max là vì để i - j là min.

- Nói gọn lại thì tại mỗi điểm i, ta có một hằng số là T = Si - K
cần tìm j lớn nhất mà Sj <= T

- Đây chính là hướng xử lý dành cho Fenwick Tree. 
Hiểu nôm na Fenwick Tree là cấu trúc dữ liệu đặc biệt, 
present một tính chất nào đó cho một đoạn từ
1 -> x nào đó (chẳng hạn tính toán tổng từ 1-->x hoặc max trong khoảng từ 1->x)
có thể cập nhật hoặc tính toán trong log N.

- Nhưng ở đây Fenwick chỉ hoạt động trên index. Vậy trước tiên ta cần invert index
Si, Si - K ta cần map nó với index trên cây.
Quá trình này gọi là rời rạc hoá. Hình dung cụ thể như sau:
giả sử ta có 3 số nguyên là 1 19 13
sắp xếp 3 số này ta có: 2 13 19
và thứ tự sau khi sắp xếp: 1 2 3
=> ta thu được map như sau:
giá trị 2 có index là 1
giá trị 13 có index là 2
giá trị 19 có index là 3

- Sau khi rời rạc hoá, ta có: 
a. index của Si - K trên cây fenwick.
b. giá trị node của cây fenwick lại bằng index trên mảng ban đầu (inverted index)

Chính cái giá trị này như đã nói:
Fenwick (idx) 
= giá trị lớn nhất của các node trong khoảng từ 1 tới idx
Vậy ta tìm thấy j = Fenwick(index(Si - K)), j lớn nhất nên i - j là nhỏ nhất

##### Solution 2 với Stack:
Để ý là Si - Sj >= K và j là max, i > j
Nếu có một cái Sx nào đó mà Sx >= Sj và 0 <= x < j thì rõ ràng ta chọn j
chứ không dại gì mà chọn x vì i - x > i - j và Si - Sj >= Si - Sx
Nói cách khác, sự xuất hiện của Sj sẽ loại hết những value nào lớn
hơn Sj trong khoảng từ 0 -> j.
Vậy ta có thể build một cái stack tăng dần, khi một phần
tử mới xuất hiện, ta kiểm tra dần trên stack từ đỉnh stack, và loại hết những phần 
tử nào trên stack lớn hơn phần tử mới.

Chú ý là việc thêm và loại bớt này, tổng cả quá trình chỉ là O(N)
vì đã loại rồi là khỏi xét, đã thêm vào rồi thì chỉ lượt qua 1 lần.

Ta chạy từ đầu tới cuối, lần lượt đưa Si vào stack.

Và câu hỏi đặt ra là với một giá trị mới là Si ta cần tìm một Sj nào đó
trên stack mà Si - Sj >= K và j max là được.

Để ý là do stack tăng dần nên:
a. Có thể binary search dễ dàng
b. Nếu không muốn binary search thì để ý thêm:
giả sử tại bước xét trước đó, ta tìm được cặp i-1 j
vậy tại bước khi thêm Si vào, ta chỉ việc dịch chuyển j để tìm cặp ghép tiếp theo

Toàn bộ quá trình dịch chuyển này chỉ là O(N) do tính chất về số lượng của stack
và tính tăng giảm của dãy số