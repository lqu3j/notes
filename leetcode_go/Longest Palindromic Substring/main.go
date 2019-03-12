package main

import "log"

func longestPalindrome(s string) string {
	if len(s) == 0 {
		return ""
	}
	var maxBegin, maxEnd int
	var begin int
	for i := 1; i < len(s); i++ {
		if begin-1 >= 0 && s[begin-1] == s[i] {
			begin = begin - 1
		} else {
			for j := begin; j <= i; j++ {
				if !isPalindrome(s[j : i+1]) {
					continue
				}
				begin = j
				break
			}
		}

		if maxEnd-maxBegin < i-begin {
			maxBegin = begin
			maxEnd = i
		}
	}
	return s[maxBegin : maxEnd+1]
}
func isPalindrome(s string) bool {
	i := 0
	j := len(s) - 1
	for i <= j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}
func main() {
	result := longestPalindrome("abcb")
	log.Println(result)
}
