# Trà đá 2^2 note

### Regulation in Deep Learning

- Competitive Data Science Contest (Kaggle)
  - Usually divided into 2 type:
    - Have a lot of data => require **heavy computing resource**
    - Have little data => require **lots of time for cleaning and feature engineering**
- Numer.ai: might be difference kind of competition
  - Data is obfuscated => difficult to feature engineering => need to based on distribution and data attribute
  - Last only 1 week per contest => cannot training and testing for a long time
  - Top 100 on-the-money
- Deep Learning:
  - Multi layer neuron network. -Usually- 1 hidden layer is enough to approx any function
  - More prone to overfitting (compare to SVM, Linear Regression, …)
  - Possible to change only 1 pixel and the also will predict totally difference
  - 1 approach for overfitting:
    - Add noise to every hidden layer weight

### How to learn Math

- Toán là gì:
  - Hệ thống logic bắt nguồn từ mệnh đề, tiên đề.
  - Toàn bộ công thức, định lý đều có thể chứng minh dc 1 cách logic
  - Mọi công thức, định lý có thể apply cho bất kì môi trường, không gian nào miễn là thoả những mệnh đề, tiên đề gốc
  - Khác với computer science: quá nhiều blackbox (gopher stated)
  - Toán chia làm 2 mảng lớn: Pure Math (chỉ phục vụ cho toán) + Applied Math (đã được đem ra áp dụng cho thực tế) (ref [this image](https://c1.staticflickr.com/1/272/32264483720-c51bdde679-b.jpg))
- Học toán để làm gì:
  - Tập thói quen hiểu mọi thứ từ gốc rễ
  - Rèn luyện suy nghĩ logic
    - Anh thaidn: học toán giống như tập thể dục => giúp đầu óc minh mẫn
- Học những gì:
  - Bắt đầu từ: Linear Algeb
  - Foundation (Set theory, logic, ….)
  - Xác suất thống kê > Foundation
  - Sau đó học lĩnh vực cần thiết (tuỳ theo nhu cầu mỗi người)
- Học thế nào:
  - Textbook: nên mua 2-3 cuốn cùng 1 lĩnh vực
    - Thấy dc góc nhìn khác nhau của các tác giả
    - Tuỳ mỗi cá nhân: có người đọc tác giả này sẽ dễ vào hơn đọc của tác giả kia
  - Video lecturer:
    - Đỡ nhàm chán hơn textbook
    - Dc lecturer nhấn mạnh vào những điểm quan trọng
  - Course của các đại học lớn (Standford, MIT, …)
  - Mail cho tác giả để hỏi

### Video Streaming

- Những thành phần cơ bản
  - Streaming Client: Web || Mobile || TV
  - API Server
    - Nhận video và forward vào những module sau
    - Lưu danh sách video và description, ….
  - Encoder
    - Chuẩn hoá video về 1 format chung
    - Encode video Theo nhiều bitrate khác nhau (360p, 1080p, 4k, …)
  - Storage: Lưu trữ video
  - CDN network
- Những protocol thông dụng:
  - RTSP (support Flash): dính lỗi bảo mật man in middle
  - HLS (của apple): thông dụng nhất hiện nay
    - Apple device chỉ support HLS => dùng HLS sẽ giảm chi phí maintain thêm 1 protocol thứ 2 cho các device ngoài Apple
  - MPEG Dash
  - WebRTC
- Challenge:
  - Chủ yếu về cost: storage, CDN, bandwidth, latency, ...
  - Protocol chưa đủ tốt: vẫn còn bị package lost
  - Security: cần ngăn chặn người dùng download lậu video có bản quyền
    - Split video thành từng chunk
    - Encode từng chunk và send xuống client (chỉ client mới có key để decode)
    - Bảo mật key ở client: với những high level device (android, ios) => key dc lưu vào device (key chain, …) => bảo mật tốt hơn (vẫn có thể cheat dc nếu jailbreak, root)
    - Bảo mật key ở client: với những low level device => chỉ là làm khó khăn chứ ko thể ngăn chặn triệt để
    - Làm tăng complexity của hệ thống

### Anh thaidn

- Tink là gì:
  - Là thư viện giúp hỗ trợ mã hoá 1 cách đơn giản (minimal API, phần lớn những tham số đã được team Tink lựa chọn trước) => giúp hạn chế dùng sai
  - Xây dựng on-top những ngôn ngữ và lib phổ biến (OpenSSL, Java, C++, ….). Gồm 3 layer:
    - API
    - Fixing bugs (sửa lỗi bảo mật của những lib/ngôn ngữ bên dưới)
    - Lib / ngôn ngữ
  - Hiện tại hỗ trợ Java C++ ObjecC => tương lai sẽ support Go/JS
- Deterministic:
  - Cùng 1 input nhưng mỗi lần encrypt phải ra 1 chuỗi khác nhau
  - Vd: khi đánh trận, bộ tư lệnh có thể send cho tướng 1 trong 2 lệnh: ĐÁNH || LUI
    - Nếu mỗi lần đều encrypt ra giống nhau => team địch có thể đoán dc nội dung dù không giải mã ra dc
- AAD params:
  - Dùng để protect những data không muốn encrypt
  - Data không bị encrypt (bất cứ ai vẫn có thể thấy nội dung) nhưng attacker sẽ không thể sửa dc nội dung (nếu sửa sẽ lưu lại vết)
- HTTP vs HTTPS caching
  - Network Path: Phone => ISP => Middle router => Middle router => … => server
  - HTTP ko encrypt nội dung (cần phải biết url path) => middle router có thể cache dc data => không cần phải travel all the way to original server => faster
  - HTTPS encrypt nội dung (không biết dc url path) => chỉ có thể cache dc ở browser và original server
- QUIC protocol:
  - Vấn đề: TCP cần giữ connection giữa client và server => khi chuyển vùng phải thiết lập lại connection (việc duy trì connection khi chuyển vùng là expensive)
  - Zero roundtrip: reduce 3-ways handshake of TCP
  - Build on top of UDP: tự implement lại Traffic congestion và SYNC/ACK
  - Yêu cầu 1 mạng lưới network lớn: những cty khác ngoài google rất khó triển khai
- Blockchain:
  - **Chốt favourite coin là bitcoin** :))
  - Mặc dù là decentralize nhưng do chênh lệch về computing power nên phần lớn resource vẫn do 1 nhóm nhỏ chiếm giữ
  - Không phải lúc nào dùng Blockchain cũng là tốt (bản chất blockchain là 1 distributed database)
    - Nếu có thể sử dụng DB thì nên sử dụng DB
    - Có 1 cấu trúc dữ liệu là MERKLE TREE cũng mang tính chất là **append only**, nếu data bị sửa sẽ lưu lại vết
- Làm thế nào để biết cryptography là an toàn:
  - Xây dựng trên xác suất và các. bài toán dc công nhận là khó (NP problem)
    - Vd AES dc xây dựng trên bài toán phân tích 1 số thành tích của 2 số nguyên tố
  - Khi thiết kế algorithm, độ phức tạp chỉ là 1 nhân tố, cần xem xét đến tốc độ, khả năng triển khai, …
    - Vd: Nếu algorithm chạy quá lâu thì cũng khó triển khai sử dụng
  - Có thể dùng ML để tìm key của cryptography hay ko?
    - Chưa có câu trả lời những đã có những nhóm nghiên cứu
