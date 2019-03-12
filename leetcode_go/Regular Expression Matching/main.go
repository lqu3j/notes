package main

import "log"

func isMatch(s string, p string) bool {
	pEnd := len(p)
	pIndex := 0

	sEnd := len(s)
	sIndex := 0

	for {
		if pIndex >= pEnd || sIndex >= sEnd {
			break
		}

		if p[pIndex] == '.' {
			sIndex++
			pIndex++
			if sIndex >= sEnd || pIndex >= pEnd {
				break
			}

			if p[pIndex] != '*' {
				continue
			}
			if pIndex+1 >= pEnd {
				sIndex = sEnd
				pIndex = pEnd
				break
			}
			log.Println("1", s[sIndex:], p[pIndex+1:])
			for sIndex <= sEnd {
				if isMatch(s[sIndex:], p[pIndex+1:]) {
					sIndex = sEnd
					pIndex = pEnd
					break
				}
				sIndex++
			}
			continue
		}

		next := pIndex + 1
		if next < pEnd {
			if p[next] == '*' {
				pIndex++
				sIndex++
			} else if p[pIndex] != s[sIndex] {
				break
			} else {
				pIndex++
				sIndex++
				continue
			}
		} else if p[pIndex] == s[sIndex] {
			pIndex++
			sIndex++
		} else {
			break
		}
		if sIndex >= sEnd || pIndex >= pEnd {
			break
		}
		log.Println(s[sIndex:], p[pIndex+1:])
		for s[sIndex] == p[pIndex-1] {
			if isMatch(s[sIndex:], p[pIndex+1:]) {
				sIndex = sEnd
				pIndex = pEnd
				break
			}
			sIndex++
		}
	}

	if sIndex == sEnd && pIndex == pEnd {
		return true
	}
	return false
}
func main() {
	result := isMatch("mississippi", "mis*is*p*.")
	log.Println(result)
}
