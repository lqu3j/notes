package main

import "log"

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil && l2 == nil {
		return nil
	}
	carry := 0
	head := &ListNode{}
	p := head

	for {
		if l1 != nil && l2 != nil {
			sum := l1.Val + l2.Val + carry
			p.Val = sum % 10
			carry = sum / 10
			if l1.Next != nil || l2.Next != nil {
				p.Next = &ListNode{}
				p = p.Next
			}
			l1 = l1.Next
			l2 = l2.Next
		} else if l1 != nil {
			sum := l1.Val + carry
			p.Val = sum % 10
			carry = sum / 10
			if l1.Next != nil {
				p.Next = &ListNode{}
				p = p.Next
			}
			l1 = l1.Next
		} else if l2 != nil {
			sum := l2.Val + carry
			p.Val = sum % 10
			carry = sum / 10
			if l2.Next != nil {
				p.Next = &ListNode{}
				p = p.Next
			}
			l2 = l2.Next
		} else {
			break
		}
	}
	if carry != 0 {
		p.Next = &ListNode{carry, nil}
	}
	return head
}

func main() {
	p := addTwoNumbers(&ListNode{1, &ListNode{8, nil}}, &ListNode{0, nil})
	for p != nil {
		log.Printf("%v->", p.Val)
		p = p.Next
	}
}
