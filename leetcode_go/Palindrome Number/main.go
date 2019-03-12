package main

import (
	"fmt"
)

func isPalindrome(x int) bool {
	// 负数全为假
	if x < 0 {
		return false
	}
	sum := 0
	for {
		sum = sum*10 + (x % 10)
		if x == sum {
			return true
		}
		if sum == 0 {
			return false
		}
		x = x / 10
		if x == sum {
			return true
		}
		if sum > x {
			return false
		}
	}
	return false
}

func main() {
	fmt.Println(isPalindrome(121))
}
