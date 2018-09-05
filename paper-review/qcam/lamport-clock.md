Time, Clocks, and the Ordering of Events in a Distributed System
===

https://lamport.azurewebsites.net/pubs/time-clocks.pdf

## Review

Ở trong một hệ thống phân tán, đôi khi khá khó để ta xác định sự kiện nào xảy ra trước, bởi vì bạn không thể dựa vào đồng hồ vật lý.

Paper này giới thiệu khái niệm **đồng hồ logic**.

Trước tiên paper định nghĩa ra một thứ tự cục bộ với đồng hồ logic. Điều này có thể được hiện thực dễ dàng với một counter trên mỗi máy, và luôn tăng.

Ta gọi `->` là quan hệ "xảy ra trước", giả sử `C` là đồng hồ với a và b là hai sự kiện lần lượt của process i và j, nếu a -> b thì C<sub>i</sub>(a) < C<sub>j</sub>(b). Chú ý a -> b có causal effect.

Một ví dụ đơn giản cho dễ hiểu.

1. Tí gửi tin mua chứng khoán A.
2. Tí đồng thời nhắn cho Tèo cũng nên mua chứng khoán A.
3. Nhận được tin của Tí, Tèo cũng mua chứng khoán A.

Lúc này đồng hồ logic đảm bảo rằng, Tí mua chứng khoán trước Tèo.

Từ đó ta có thứ tự toàn cục cho toàn hệ thống, vì ta có thể đảm bảo được những sự kiện có causal effect luôn được sắp xếp đúng.

## Ứng dụng

Lamport clock là tiền đề cho nhiều ứng dụng trong hệ thống phân tán, ví dụ như Vector Clock trong Riak.

Bạn có thể tham khảo thêm về vector clock qua các bài viết của Basho tại:

1. http://basho.com/posts/technical/why-vector-clocks-are-easy/
2. http://basho.com/posts/technical/why-vector-clocks-are-hard/

