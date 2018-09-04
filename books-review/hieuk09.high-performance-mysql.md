# Book review - High Performance MySQL

## Info

> - Author: Baron Schwartz, Peter Zaitsev, Vadim Tkachenko
> - Epub: 2025 pages
> - Publisher: O'Reilly
> - Language: English

![High performance mysql](http://hieuk09.github.io/assets/high_performance_mysql.png)

## Review

Cuốn sách này viết rất đầy đủ về database nói chung và MySQL nói riêng,
  không chỉ về cách sử dụng mà còn về kiến trúc, các khái niệm trong database
  (như isolation level, locks, recovery, ...). Sách viết cực kỳ chi tiết (số
      trang nói lên tất cả), và cực kỳ rõ ràng. Tác giả đã dành nhiều thời gian
  để mô tả các khái niệm cơ bản, rồi từ đó mới đi đến các phương pháp tối ưu
  hoá, khiến cho việc hiểu được tại sao lại có cách tối ưu đó rất dễ dàng.

  Nhìn chung, đây là một cuốn sách tốt dành cho những ai bắt đầu tìm hiểu về
  kiến trúc cũng như cách một database (như MySQL) hoạt động, và cách để sử dụng chúng tối
  ưu nhất.

## Table of contents

> Ghi chú: độ quan trọng của các chương
> - text bình thường: có thể bỏ qua
> - *text in nghiêng*: nên đọc lướt qua (đọc kỹ nếu có thể)
> - **text in đậm**: nên đọc kỹ

- Preface: Tổng quan về cuốn sách, cũng như cách cuốn sách này được sắp xếp.

- **Chapter 1** - MySQL architecture: Chương này nói về kiến trúc của MySQL cũng nhưn
các khái niêm cơ bản của MySQL như concurrency, locks, transaction, isolation
level và storage engine. Những thông tin này có thể áp dụng cho cả những
database khác.

- *Chapter 2* - Finding Bottlenecks: Benchmarking and Profiling:
nói về chiến lược và cách thức để Benchmark và Profile một database system.
Những kiến thức này khá tổng quát nên có thể áp dụng cho cả những hệ thống thông
thường (không phải database) hay những database khác.

- **Chapter 3** - Schema Optimization and Indexing: nói về chủ đề quan trọng
nhất khi tối ưu DB: indexing. Chương này mô tả cách MySQL implement các loại
index khác nhau và cách tận dụng chúng cho những yêu cầu khác nhau của ứng dụng.

- **Chapter 4** - Query Performance Optimization: mô tả cách query optimizer
hoạt động. Ngoài ra, chương này còn mô tả cách MySQL implement join. Từ đây, các
tác giả đề xuất một loạt các phương pháp để tái cấu trúc schema và query sao cho
query optimizer có thể hiểu và hoạt động tốt hơn cho ứng dụng.

- *Chapter 5* - Advance MySQL features: nói vè các tính năng advance trong MySQL
như Query Cache, Views, Charset, Full-text Search, Foreign Key, Store Procedure,
  ... và cách tối ưu chúng.

- *Chapter 6* - Optimizing Server Setting: chỉ ra rằng các settings của MySQL
cũng có thể ảnh hưởng đến performance của Qquery của bạn. Tuy nhiên, trước khi
thay đổi những setting này thì bạn nên có một benchmark tốt cho ứng dụng hiện
tại. Bạn có thể đọc lại chương 2 để biết thêm chi tiết.

- Chapter 7 - Operating System and Hardware Optimization: với việc Amazon RDS và
Aurora hỗ trợ khá tốt MySQL, chương này không giúp ích gì nhiều cho mình. Tuy
nhiên, các bạn Sys Admin hay Devops cần phải tự setup MySQL có thể có được nhiều
thông tin hữu ích cho việc lựa chọn cấu hình phù hợp cho db của mình.

- *Chapter 8* - Replication: hướng dẫn cách setup replication cho MySQL. Ngoài
replication bằng MySQL, cuốn sách còn hướng dẫn cách replicate toàn bộ
filesystem hoặc cả server.

- *Chapter 9* - Scaling and High Availability: nói về khá nhiều thứ liên quan
đến scale: tách các chức năng ra, sharding, load balance, ...

- *Chapter 10* - Application-level Optimization: mô tả rất kỹ về các kỹ thuật cache,
  cũng như nói sơ vè các kỹ thuật khác như compression, mở rộng MySQL, ... Ngoài ra cuốn sách còn đưa ra một số
  trường hợp cụ thể về các vấn đề performance liên quan đến ứng dụng

- *Chapter 11* - Backup and Recovery: mình chưa bao giờ phải quản lý database
system nào, nên trước giờ mình không quan tâm lắm đến recovery và backup. Chương
này nói về việc recovery và backup quan trọng nhu thế nào. Một điều rút ra: phải
luôn có backup và quy trình recovery, cũng như phải kiểm tra backup và quy trình
này thường xuyên.

- *Chapter 12* - Security: nói về cách MySQL quản lý user và permission. Chương
này cũng nói về các bad practice cũng như good practice khi setup permission
trong MySQL.

- *Chapter 13* - MySQL Server status: để tối ưu một hệ thống thì cần có thông
tin về hệ thống đó, chương này nói về cách để thu thập thông tin từ một MySQL
system.

- Chapter 14 - Tools for high performance: Chương này nói về các công cụ để quản
lý hay hỗ trợ quản lý MySQL. Theo mình thì nó khá outdate và danh sách các ứng
dụng tốt hơn có thể được tìm thấy trên internet.

- Apendix A - Transfering Large Files

- Apendix B - Using EXPLAIN

- Apendix C - Using Sphinx with MySQL

- Apendix D - Debugging Locks

