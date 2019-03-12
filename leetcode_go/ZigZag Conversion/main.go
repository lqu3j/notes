package main

import "log"

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	cycle := 2*numRows - 2
	numColumn := len(s) / cycle
	if len(s)%cycle != 0 {
		numColumn++
	}
	result := make([]byte, 0, len(s))
	for j := 0; j < numRows; j++ {
		for i := 0; i < numColumn; i++ {
			if i*cycle+j < len(s) {
				result = append(result, s[i*cycle+j])
			}
			if j != 0 && j != numRows-1 && i*cycle+j+2*(numRows-j-1) < len(s) {
				result = append(result, s[i*cycle+j+2*(numRows-j-1)])
			}
		}
	}
	return string(result)
}

func main() {
	a := convert("PAYPALISHIRING", 4)
	log.Println(a)
}
