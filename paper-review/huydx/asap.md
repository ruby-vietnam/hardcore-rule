# Paper

http://www.bailis.org/papers/asap-vldb2017.pdf

# Vấn đề:
- Dữ liệu time series data raw sẽ khó để nhìn trend, đặc biệt với data mà thay đổi nhanh trong thời gian ngắn
- Ví dụ với dữ liệu taxi của NW
https://gyazo.com/8dd618fb6e3f53a1ee66e794ed524621
- Với phương pháp smoothing thông thường thì thường dẫn đến oversmooth
- Oversmooth dẫn đến sai trend


# Giải quyết:
- Định nghĩa Roughness (độ thô) của dữ liệu == độ lệch chuẩn (standard dev) của first difference (hình dung là delta của dữ liệu)
- Mục đích của smoothing phải đảm bảo giữ roughness nhiều nhất có thể —> giúp không oversmoothing
- Để giữ roughness, định nghĩa phân bố Kurtoris :
    Kurt[X] = E[(X -μ)2]2 / E[(X - μ)4] 
- Phân bố Kurtoris là (forth standard moment) của X (chính là time series data), và trung bình μ của X
- Để smooth dữ liệu thì sử dụng cách truyền thống là average moving (lấy trung bình dữ liệu trên 1 window (w)
- Vậy vấn đề là : làm thế nào để tìm được window (w) mà đảm bảo Kurtoris của dữ liệu “trước” và “sau” khi smooth không chênh nhau quá nhiều
- Nếu dùng naive search (tìm tất cả các w có thể, hay còn gọi là Strawman Solution) thì sẽ tốn O(N^2) với N là số lượng point đầu vào.
- Cách cải thiện là dùng observation (sau một hồi chứng minh loằng ngoằng) là kurt và window length (w) sẽ tăng linear với nhau với kurt > 3, và ngược lại với kurt <= 3.
- Dựa vào observation đó thì chúng ta có thể sử dụng binary search.
- Tuy nhiên bin search thì sẽ đúng với một số dạng data nhất định (gọi là IID (identically independently distributed))). Tuy nhiên với data khác thì tác giả nhận xét là thường có tính chu kỳ (lặp đi lặp lại)
- Do đó chúng ta chỉ cần chạy ASAP trên đoạn data “không lặp lại”.
- Để tìm ra đoạn data không lặp lại, định nghĩa hàm ACF (autocorrelation function) (https://gyazo.com/0312d884f094b0d075c5e8d36a6cc8e6)
- Ngoài ra để optimize thì áp dụng thêm FFT (Fast Fourier Transform) để pruning cho nhanh


