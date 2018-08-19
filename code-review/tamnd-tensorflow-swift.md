# tensorflow/swift

Github repo: https://github.com/tensorflow/swift

## About
Hôm nay mềnh sẽ review Swift for Tensorflow, dùng Swift cho tensorflow sẽ khác hẳn những language binding khác như là C, C++, Java hay Go, chỉ là wrapper trên API của tensorflow, nhưng Swift được integrate chặt chẽ với Tensorflow ở một mức độ cao hơn những ngôn ngữ trên rất nhiều.

## Why?
https://github.com/tensorflow/swift/blob/master/docs/WhySwiftForTensorFlow.md

Link trên chém gió nhiều thứ rất chi lằng nhằng, nhưng lý do thực sự thì chẳng qua lead của Tensorflow và Swift cùng là bác Chris Lattner, [mềnh thích thì mềnh làm thôi](https://news.ycombinator.com/item?id=16720731).

## Design overview
https://github.com/tensorflow/swift/blob/master/docs/DesignOverview.md

Điểm thú vị đầu tiên là [https://github.com/tensorflow/swift/blob/master/docs/DesignOverview.md#graph-program-extraction](Graph Program Extraction), 

![](https://raw.githubusercontent.com/tensorflow/swift/master/docs/images/DesignOverview-Pipeline.png)

Nó hoạt động như là 1 stage của compiler, tìm tất cả các tensor operators bên trong code, và tách ra thành Tensorflow Graph riêng để execute. Thậm chí, nó có thể desugar những abstraction như struct, tuples, functions, variables để biến nó thành các toán tử tensor (tensor op). Sau khi các toán tử này dc desugar, sẽ có 1 phép biến đổi để extract những operation này và build 1 hàm SIL (Swift Intermediate Language) để biểu diễn code tensor. Các bạn có thể xem thêm code ở file [TFPartition.cpp](https://github.com/apple/swift/blob/tensorflow/lib/SILOptimizer/Mandatory/TFPartition.cpp).
