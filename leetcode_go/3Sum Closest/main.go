package main

import (
	"log"
	"math"
	"sort"
)

func threeSumClosest(nums []int, target int) int {
	if len(nums) <= 3 {
		sum := 0
		for _, v := range nums {
			sum += v
		}
		return sum
	}

	sort.Ints(nums)
	min := math.MaxInt32
	sum := target
	for i := 0; i < len(nums); i++ {
		j := i + 1
		k := len(nums) - 1
		tmp := target - nums[i]
		for j < k {
			if min > int(math.Abs(float64(nums[j]+nums[k]-tmp))) {
				min = int(math.Abs(float64(nums[j] + nums[k] - tmp)))
				sum = nums[i] + nums[j] + nums[k]
			}
			if nums[j]+nums[k] > tmp {
				k--
			} else if nums[j]+nums[k] < tmp {
				j++
			} else {
				return target
			}
		}

	}
	return sum
}

func main() {
	log.SetFlags(log.Lshortfile | log.Flags())
	log.Println(threeSumClosest([]int{1, 1, 1, 1}, 0))
}
