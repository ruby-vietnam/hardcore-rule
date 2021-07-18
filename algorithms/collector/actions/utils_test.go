package actions

import "testing"

func Test_ptrStr(t *testing.T) {
	str := "Test str"
	strAddr := ptrStr(str)
	if strAddr == nil {
		t.Errorf("ptrStr() returns wrong ptr string (nil)")
	}
}
