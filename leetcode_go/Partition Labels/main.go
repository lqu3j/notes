package main

import (
	"log"
)

func partitionLabels(S string) []int {
	if len(S) == 0 {
		return []int{0}
	}
	tmp := make(map[int]int)
	for k, v := range S {
		tmp[int(v)] = k
	}

	begin := 0
	result := []int{}
	for begin < len(S) {
		lastIndex := tmp[int(S[begin])]
		for i := begin; i < lastIndex; i++ {
			if tmp[int(S[i])] > lastIndex {
				lastIndex = tmp[int(S[i])]
			}
		}
		result = append(result, lastIndex-begin+1)
		lastIndex++
		begin = lastIndex
	}
	return result
}

func main() {
	result := partitionLabels("ababcbacadefegdehijhklij")
	log.Println(result)
}
