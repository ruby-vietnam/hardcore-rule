# tensorflow/swift

Github repo: https://github.com/tensorflow/swift

## About
Hôm nay mềnh sẽ review Swift for Tensorflow, dùng Swift cho tensorflow sẽ khác hẳn những language binding khác như là C, C++, Java hay Go, chỉ là wrapper trên API của tensorflow, nhưng Swift được integrate chặt chẽ với Tensorflow ở một mức độ cao hơn những ngôn ngữ trên rất nhiều.

## Why?
https://github.com/tensorflow/swift/blob/master/docs/WhySwiftForTensorFlow.md

Link trên chém gió nhiều thứ rất chi lằng nhằng, nhưng lý do thực sự thì chẳng qua lead của Tensorflow và Swift cùng là bác Chris Lattner, [mềnh thích thì mềnh làm thôi](https://news.ycombinator.com/item?id=16720731).

## Design overview
https://github.com/tensorflow/swift/blob/master/docs/DesignOverview.md

### Graph program extraction

Điểm thú vị đầu tiên là [https://github.com/tensorflow/swift/blob/master/docs/DesignOverview.md#graph-program-extraction](Graph Program Extraction), 

![](https://raw.githubusercontent.com/tensorflow/swift/master/docs/images/DesignOverview-Pipeline.png)

Nó hoạt động như là 1 stage của compiler, tìm tất cả các tensor operators bên trong code, và tách ra thành Tensorflow Graph riêng để execute. Thậm chí, nó có thể desugar những abstraction như struct, tuples, functions, variables để biến nó thành các toán tử tensor (tensor op). Sau khi các toán tử này dc desugar, sẽ có 1 phép biến đổi để extract những operation này và build 1 hàm SIL (Swift Intermediate Language) để biểu diễn code tensor. Các bạn có thể xem thêm code ở file [TFPartition.cpp](https://github.com/apple/swift/blob/tensorflow/lib/SILOptimizer/Mandatory/TFPartition.cpp).

Chi tiết cái Graph Program Extraction hoạt động như thế nào, có thể đọc thêm ở [đây](https://github.com/tensorflow/swift/blob/master/docs/GraphProgramExtraction.md).

### Automatic Differentiation
https://github.com/tensorflow/swift/blob/master/docs/DesignOverview.md#automatic-differentiation
https://github.com/tensorflow/swift/blob/master/docs/AutomaticDifferentiation.md

Điểm thú vị thứ 2 là tính toán vi phân của Swift for Tensorflow, phần này ít bạn làm ML với ko thích toán nên mềnh bỏ qua : )

### Python interoperability
https://github.com/tensorflow/swift/blob/master/docs/DesignOverview.md#python-interoperability
https://github.com/tensorflow/swift/blob/master/docs/PythonInteroperability.md

Phần thứ 3 thú vị nhất (về mặt engineering), là làm thế nào gọi code Python một cách hiệu quả?

Toàn bộ phần code sẽ nằm ở file [Python.swift](https://github.com/apple/swift/blob/tensorflow/stdlib/public/Python/Python.swift).

Ở đây, Swift for TF dùng 1 cách khá thú vị, thay vì thêm static type system vào Python như là mypy, pytype, etc, nó dùng luôn Python như là embedded language, thông qua [C interface API](https://oleb.net/blog/2017/12/importing-c-library-into-swift/).

Các thư viện mà thêm static type system vào Python, sẽ làm mất tính linh động của Python, và veiejc cố gắng gò ép Python vào static type sẽ làm mất đi những điểm mạnh nhất của Python.

Cách tiếp cận ở đây là vẫn giữ kiểu động cho Python, và nhúng thẳng vào Swift, dẫn đến việc viết code rất tự nhiên, code Swift mà ... nhìn như Python :))

```swift
// Python:
//    import numpy as np
//    a = np.arange(15).reshape(3, 5)
//    b = np.array([6, 7, 8])
let np = Python.import("numpy")
let a = np.arange(15).reshape(3, 5)
let b = np.array([6, 7, 8])

// Python:
//    import gzip as gzip
//    import pickle as pickle
let gzip = Python.import("gzip")
let pickle = Python.import("pickle")

// Python:
//    file = gzip.open("mnist.pkl.gz", "rb")
//    (images, labels) = pickle.load(file)
//    print(images.shape) // (50000, 784)
let file = gzip.open("mnist.pkl.gz", "rb")
let (images, labels) = pickle.load(file).tuple2
print(images.shape) // (50000, 784)
```

### How it works?
Thế thì trò magic gì đằng sau?

Toàn bộ hệ thống kiểu động của Python sẽ được map vào 1 kiểu static duy nhất của Swift, gọi là `PyValue`, và `PyValue` có thể lấy mọi giá trị của Python object tại runtime. Cái `PyValue` này sẽ tương ứng trực tiếp đến cái `PyObject*` của Python C binding. Nhưng mọi cái Python behavior chỉ ảnh hưởng đến những biểu thức nào mà có chứa cái `PyValue`, còn những code Swift bên ngoài khác vẫn tuân theo semantic của Swift.

```swift
var x: PyValue = 42  // x is an integer represented as a Python value.
print(x + 4)         // Does a Python addition, then prints 46.

x = "stringy now"    // Python values can hold strings, and dynamically change Python type!
print("super " + x)  // Does a Python addition, then prints "super stringy now".
```

Updated: Cái `PyValue` đã được đổi tên thành `PythonObject`, nhưng document bị outdated, lol :v 
https://github.com/apple/swift/commit/8714d386bebe78aaee8723100fce3941172bf33c#diff-9c35301a67943f9bf278c84a0f55f490

Chi tiết các bạn có thể đọc trong code, code mới là đáng tin, document chỉ là chém gió :v 

