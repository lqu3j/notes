package main

// 暴力O(n^2)

/*
func twoSum(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return nil
}
*/

// 两次遍历
/*
func twoSum(nums []int, target int) []int {
	tmp := make(map[int]int)
	for k, v := range nums {
		tmp[v] = k
	}

	for i := 0; i < len(nums); i++ {
		if j, ok := tmp[target-nums[i]]; ok && i != j {
			return []int{i, j}
		}
	}
	return nil
}
*/

// 一次遍历
func twoSum(nums []int, target int) []int {
	tmp := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		if j, ok := tmp[target-nums[i]]; ok {
			return []int{j, i}
		}
		tmp[nums[i]] = i
	}
	return nil
}

func main() {
	twoSum([]int{2, 7, 11, 15}, 9)
}
