#
# Produce counter examples for @lpvcpp's trick solution
#
# ➜ python counter_example.py
# Length = 1. Considering 64 possibilies...
# Length = 2. Considering 4096 possibilies...
# Length = 3. Considering 262144 possibilies...
# Length = 4. Considering 16777216 possibilies...
# Counter example: adeh bbgg
#
# took 7s
#
import itertools

def correct_anagram(s, t):
    if len(s) != len(t):
        return False

    count_s = [0] * 26
    count_t = [0] * 26
    for s_i, t_i in zip(s, t):
        count_s[ord(s_i) - ord('a')] += 1
        count_t[ord(t_i) - ord('a')] += 1

    for i in range(26):
        if(count_s[i] != count_t[i]):
            return False
    return True

def mock_anagram(s, t):
    if len(s) != len(t):
        return False

    diff_1, diff_2, diff_3 = 0, 0, 0
    for s_i, t_i in zip(s, t):
        a, b = ord(s_i), ord(t_i)
        diff_1 += a - b
        diff_2 += a*a - b*b
        diff_3 += a*a*a - b*b*b

    if diff_1 == 0 and diff_2 == 0 and diff_3 == 0:
        return True
    return False

def generate(length):
    return [''.join(x) for x in itertools.product('abcdefgh', repeat=length)]

for i in range(1, 10):
    all_strings = generate(i)
    print("Length = %d. Considering %d possibilies..." % (i, len(all_strings) ** 2))
    for s in all_strings:
        for t in all_strings:
            if correct_anagram(s, t) != mock_anagram(s, t):
                print("Counter example:", s, t)
                exit(0)