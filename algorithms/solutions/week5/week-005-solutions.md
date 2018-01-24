Week 5 summary

## Summary
### Solved 4 problems
- linxgnu

### Solved 3 problems
- nguyenquangminh
- anhduy
- unrealhoang

### Solved 2 problems
- hieuk09
- huydx
- ledongthuc
- lephongvu
- nhantruong
- HQC
- triet
- vietthang

### Solved 1 problem
- snacky (Problem 1 100%, Problem 2 80%, Problem 3 40%)
- lephongvu
- runi
- toanha

### Solved 0 problem
- manhdv
- tle
- rikimaru (update later)


## Some solutions

### Problem 2
inxGnu:
idea là chỉ cần khử ( và )
việc 1 là khử )
đi theo stack để khử, đi từ trái qua phải, cứ gặp ( thì push vào stack, gặp * thì count là xong (push vô stack cũng ok), gặp ) thì lôi đống stack hoặc * ra để khử, ưu tiên là lấy ( ra để khử ), nếu hết ( rồi thì mới lấy * ra để khử (edited)
sau khi khử ) thì nhiệm vụ tiếp theo là khử ( nếu phát sinh
ta có stack những cái ( còn sót lại
giờ chỉ cần match nó với * tương ứng

longkt90:
cứ gặp ( bỏ vô stack, ) lấy ra khỏi stack, nếu có ) mà stack hết thì coi có  * hay ko.
đến cuối còn bao nhiêu * và ( thì ghép với nhau, mỗi ( và * có cái index, nếu * xuất hiện trước ( thì ko ghép dc => sai

### Problem 3
1. Nếu coi w, h của E là một điểm có tọa độ (w, h), bài toán sẽ trở thành các hình chữ nhật bao nhau, mọi người có thể nghĩ theo hướng này cũng được. Tuy nhiên nó có đặc điểm là hình chữ nhật W2 H2 bao hình W1 H1 thì suy ra
W2 > W1 --> nếu ta có một solution nào đó thỏa mãn đề bài thì nó luôn có dạng Wk > Wk-1 > .. > W1
2. Sau khi sort mọi thứ trong E theo W, một Envelop i nào đó, gọi là Ei, nó có thể bao trọn gói những E nào. Vì ta sort xong rồi => nó có thể bao mọi E trong khoảng từ 1 đến i-1, nói cách khác, nó có thể  bao Ej, với j < i.

Với mọi m mà m > i => Wm >= Wi => Ei không bao giờ bao được Em cả, vậy Ei chỉ có thể bao trọn những Ej như trên mà thôi. Nó củng cố cho idea 1.

==> ta có thể nhìn thấy ra ngay quy hoạch động:
gọi F[i] là maximum mà thằng Ei có thể bao => F[i] = Max(F[j] + 1) với mọi 1 <= j < i - 1 và Hj < Hi, Wj < Wi
=> Chúng ta đã có công thức quy hoạch động với độ phức tạp N^2
3. Mỗi lần ta tính được xong F[i], cái ta mong muốn là làm sao notify được cho mọi Fk mà k > i để báo là: Fk có thể bao trọn gọi Fi, Fi mới được cập nhật. Làm sao để thực hiện trong log, rồi tới lượt Fk lấy ra tập con mà nó có thể bao được trong log.
Đây là bài toán Binary Index Tree kinh điển

