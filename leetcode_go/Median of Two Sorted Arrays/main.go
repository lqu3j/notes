package main

import "log"

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	length := len(nums1) + len(nums2)
	tmp := make([]int, 0, length)

	var i, j int

	for i < len(nums1) && j < len(nums2) {
		if nums1[i] < nums2[j] {
			tmp = append(tmp, nums1[i])
			i++
		} else {
			tmp = append(tmp, nums2[j])
			j++
		}
	}

	for i < len(nums1) {
		tmp = append(tmp, nums1[i])
		i++
	}
	for j < len(nums2) {
		tmp = append(tmp, nums2[j])
		j++
	}
	if length%2 == 0 {
		return float64(tmp[length/2]+tmp[length/2-1]) / 2
	}
	return float64(tmp[length/2])
}

func main() {
	b := findMedianSortedArrays([]int{1, 3}, []int{2})
	log.Println(b)
}
