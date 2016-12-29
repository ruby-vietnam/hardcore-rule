# Hash calculate server

## Introduction
Đây là một cuộc thi nhân dịp năm mới của nhóm #hardcore, nhằm mục đích "giải trí lành mạnh" cho nhóm. Qua đó cũng để phân định lại vai vế thấp cao trong nhóm (không có người lại bảo @huydx độc tài). Ngoài mục đích tranh tài cao thấp thì cuộc thi cũng có thêm mục đích phụ là xem làm thế nào để tận dụng hết công suất của ngôn ngữ mà mình yêu thích, qua đó hy vọng mọi người sẽ học được thêm ít 

## Rule
Output của cuộc thi là 1 http server làm nhiệm vụ tính FNV hash của 1 số bất kì với 1 số lần nest bất kì (đầu vào sẽ có 2 biến số là X: số cần hash và N: số lần hash).

![](https://i.gyazo.com/c5e194cfbcf553f5e399d48d9f7a6489.png)
- Tất cả http server của những người tham dự sẽ chạy trên một máy tính cùng cấu hình 
- FNV phải tự implement theo spec của FNV 1A (https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function)
- Request có thể là http hoặc http2 tuỳ thuộc vào hứng của người viết test suite 
- Người chơi có thể dùng thêm bất kì middleware nào để tăng tốc (database, cache...)

## Evaluation
Để đánh giá performance thì con số chủ yếu được dùng sẽ là **throughput**.Tức là càng có nhiều request giải quyết xong trong một khoảng thời gian (3 minutes) thì sẽ càng được điểm cao.
Tuy nhiên các yếu tố sau sẽ bị tính điểm trừ:
- Request serve quá chậm (vượt quá time out của ban tổ chức)
- Kết quả tính sai (trừ cực nặng)
- Hình thức gian lận như hối lộ người viết test suite.

## Award
Người thắng sẽ được toàn quyền quyết định sử dụng số tiền nộp phạt tính cho tới thời điểm hiện tại (~40$)
