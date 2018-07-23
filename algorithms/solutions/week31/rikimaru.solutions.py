#!/usr/bin/env python3.7

YES = 'YES'
NO = 'NO'

def solution_1(input):
    """
    Problem 1 : http://codeforces.com/contest/550/problem/A
    """
    length = len(input)
    if length < 4:
        return NO

    location = {
        'sab': -1,
        'sba': -1,
        'eab': -1,
        'eba': -1,
    }
    i = 1
    while i < length:
        s = input[i]
        if s == 'A':
            # BA case
            if input[i - 1] == 'B':
                if location['sba'] == -1:
                    location['sba'] = i - 1
                location['eba'] = i - 1
            # AB case
            if (i < length - 1) and (input[i + 1] == 'B'):
                if location['sab'] == -1:
                    location['sab'] = i
                location['eab'] = i
        elif s == 'B':
            # AB case
            if input[i - 1] == 'A':
                if location['sab'] == -1:
                    location['sab'] = i - 1
                location['eab'] = i - 1
            # BA case
            if (i < length - 1) and (input[i + 1] == 'A'):
                if location['sba'] == -1:
                    location['sba'] = i
                location['eba'] = i
        i = i + 2

    if (location['sab'] > -1) and (location['eba'] - location['sab'] > 1):
        return YES
    elif (location['sba'] > -1) and (location['eab'] - location['sba'] > 1):
        return YES
    return NO


SOLUTION_1_TESTCASES = {
    'A': NO,
    'AB': NO,
    'ABA': NO,
    'ABBA': YES,
    'BAAB': YES,
    'BAAAB': YES,
    'BABAB': YES,
    'AAAAAAAAAAAAAB': NO,
    'AAAAAAAAAAAAABA': NO,
    'AAAAAAAAAAAAABAB': NO,
    'AAAAAAAAAAAAABBA': YES,
    'ABABBBBBBBBBBBBBBBBBBBAB': YES,
}


if __name__ == '__main__':
    # Test case for problem 1
    for testcase in SOLUTION_1_TESTCASES:
        if SOLUTION_1_TESTCASES[testcase] == solution_1(testcase):
            print('Testcase "{0}" passed!..'.format(testcase))
        else:
            raise Exception('Oop! Testcase "{0}" had failed!..'.format(testcase))
    print('Solution 1 passed all testcase')