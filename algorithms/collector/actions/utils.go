package actions

func ptrStr(s string) *string {
	return &s
}

func getStrFromPtr(s *string) string {
	if s == nil {
		return ""
	}
	return *s
}

func getIntFromPtr(i *int) int {
	if i == nil {
		return 0
	}
	return *i
}
