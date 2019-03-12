package main

import (
	"fmt"
	"log"
	"sort"
)

// 暴力, 超时
/*
func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	result := [][]int{}
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			for k := j + 1; k < len(nums); k++ {
				if nums[i]+nums[j]+nums[k] != 0 {
					continue
				}
				appendFlag := true
				for _, v := range result {
					if nums[i] == v[0] && nums[j] == v[1] {
						appendFlag = false
					}
				}
				if appendFlag {
					result = append(result, []int{nums[i], nums[j], nums[k]})
				}

			}
		}
	}
	return result
}
*/

func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	result := [][]int{}
	for i := 0; i < len(nums); i++ {
		if nums[i] > 0 {
			break
		}
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		j := i + 1
		k := len(nums) - 1
		target := -nums[i]

		for j < k {
			if nums[j]+nums[k] == target {
				for j < k && nums[j] == nums[j+1] {
					j++
				}
				for j < k && nums[k] == nums[k-1] {
					k--
				}
				result = append(result, []int{nums[i], nums[j], nums[k]})
				j++
				k--
			} else if nums[j]+nums[k] < target {
				j++
			} else {
				k--
			}
		}

	}
	return result
}

func main() {
	log.SetFlags(log.Lshortfile | log.Flags())
	result := threeSum([]int{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6})
	for _, v := range result {
		fmt.Println(v)
	}
}
