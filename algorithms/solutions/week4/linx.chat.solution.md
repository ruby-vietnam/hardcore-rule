
Với bài này thì đầu tiên em liên tưởng ngay tới việc từ 1 ô ta tô màu một loạt các ô mà nó nhảy đến. Rõ ràng để tới được những ô này thì từ số step chỉ tăng lên 1 mà thôi, và nó là minimum

Vậy nếu nhảy tới 1 trong những ô này thì bước thứ 2 sẽ có thể đạt được là những ô nào

vậy bước 1 ta nhảy được từ a --> b là max

bươc 2 cho ta chọn thêm từ b tới đâu đó nữa

vậy muốn tối ưu bước 2 cần chọn ô nào đó mà ta nhảy được xa nhất, việc xa nhất tăng khả năng lựa chọn cho chúng ta

chẳng hạn ta nhảy tới ô c hoặc ô d ở bước 1

vậy chọn c hay là chọn d

chọn cái nào mà bước 2 cho ta `xa b` nhất rõ ràng là có lợi hơn

với 2 range là b tới c1 hoặc từ b tới d1, thì 1 trong 2 sẽ là tập con của cái còn lại => cứ xa nhất là ngon

em simulate thế

rồi prove nó

giống như đánh cờ, anh simulate 2 step or more để tìm tính chất

em đặt mình vào vị trí jump, thể hiện qua variable i

rõ ràng từ vị trí 1 đến vị trí 0 + nums[0] thì mất 1 bước là minimum


vậy những ô nào chỉ mất 2 step là đến

gọi D = 0 + nums[0]

=> ô có thể tới bằng 2 step là từ 1 -> nums[1] + 1, 2 -> nums[2] + 2, ..., D -> nums[D] + D

nó tạo thành các miền range, có giao nhau với 0 --> D

=> vậy những ô có thể chỉ mất 2 step đến là từ


D -> nums[1] + 1

D -> nums[2] + 2

...

D -> nums[D] + D

rõ ràng nếu ta chọn ô nào đó cho ta nhảy xa nhất thì ta có thể tiếp cận hàng loạt các ô mới, và các ô mới này chỉ mất 2 bước jump

và cứ như vậy khi jump tới chính ô mà giúp ta nhảy xa nhất có thể, ta có hàng loạt cac lựa chọn tiếp theo, quay lại bước phía trên
