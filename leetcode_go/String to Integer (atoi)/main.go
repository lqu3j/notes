package main

import (
	"log"
	"math"
)

func myAtoi(str string) int {
	beginIndex := 0
	endIndex := len(str) - 1

	for beginIndex <= endIndex && str[beginIndex] == ' ' {
		beginIndex++
	}
	for endIndex >= beginIndex && str[endIndex] == ' ' {
		endIndex--
	}
	flag := true
	if beginIndex <= endIndex && str[beginIndex] == '-' {
		flag = false
		beginIndex++
	} else if beginIndex <= endIndex && str[beginIndex] == '+' {
		flag = true
		beginIndex++
	}

	sum := 0
	for beginIndex <= endIndex && str[beginIndex] >= '0' && str[beginIndex] <= '9' {
		sum = sum*10 + int(str[beginIndex]-'0')
		if flag == true && sum > math.MaxInt32 {
			return math.MaxInt32
		}
		if flag == false && sum > -math.MinInt32 {
			return math.MinInt32
		}
		beginIndex++
	}
	if flag == true {
		return sum
	} else {
		return -sum
	}
}

func main() {
	a := myAtoi("9223372036854775808")
	log.Println(a)
}
