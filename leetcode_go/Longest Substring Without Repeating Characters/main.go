package main

import "log"

func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	indexMap := make(map[int]int)
	beginIndex := 0
	max := 0
	for k, v := range s {
		index, ok := indexMap[int(v)]
		if ok && index >= beginIndex {
			if max < k-beginIndex {
				max = k - beginIndex
			}
			beginIndex = index + 1
		}
		indexMap[int(v)] = k
	}
	if max < len(s)-beginIndex {
		max = len(s) - beginIndex
	}
	return max
}
func main() {
	max := lengthOfLongestSubstring("acc")
	log.Println(max)
}
