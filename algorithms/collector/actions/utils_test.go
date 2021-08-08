package actions

import "testing"

func Test_ptrStr(t *testing.T) {
	str := "Test str"
	strAddr := ptrStr(str)
	if strAddr == nil {
		t.Errorf("ptrStr() returns wrong ptr string (nil)")
	}
}

func Test_isAlgorithmPR(t *testing.T) {
	type Test struct {
		input  string
		output bool
	}

	tests := []Test{
		{input: "This is a non-algorithm PR\nIt has multiple lines", output: false},
		{input: "This is a correct one\n- [ ] Problem 1\n- [ ] Problem 2", output: true},
		{input: "This is also a correct one\n- [ ] Problem 1\n- [x] Problem 2", output: true},
	}

	for _, test := range tests {
		actual := isAlgorithmPR(test.input)
		if actual != test.output {
			t.Errorf("isAlgorithmPR() returns wrong result for string: '%s'", test.input)
		}
	}
}
