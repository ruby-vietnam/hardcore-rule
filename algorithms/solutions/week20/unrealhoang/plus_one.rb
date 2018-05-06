# @param {Integer[]} digits
# @return {Integer[]}
def plus_one(digits)
    carry = 1
    idx = digits.length - 1
    loop do
        break if idx < 0
        cur_num = digits[idx] + carry
        if cur_num > 9
            digits[idx] = cur_num - 10
            carry = 1
        else
            digits[idx] = cur_num
            carry = 0
            break
        end
        idx -= 1
    end
    if carry > 0
        digits.unshift(1)
    end
    digits
end
