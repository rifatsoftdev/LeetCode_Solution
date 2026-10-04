package main

import "fmt"

func compress(chars []byte) int {
	write := 0
	count := 1

	for read := 1; read <= len(chars); read++ {
		if read < len(chars) && chars[read] == chars[read-1] {
			count++
		} else {
			chars[write] = chars[read-1]
			write++
			if count > 1 {
				for _, digit := range []byte(fmt.Sprintf("%d", count)) {
					chars[write] = digit
					write++
				}
			}
			count = 1
		}
	}

	return write
}

func main() {
	// test cases 1
	chars1 := []byte{'a', 'a', 'b', 'b', 'c', 'c', 'c'}
	length1 := compress(chars1)
	fmt.Println("Compressed length:", length1)

	// test cases 2
	chars2 := []byte{'a'}
	length2 := compress(chars2)
	fmt.Println("Compressed length:", length2)

	// test cases 3
	chars3 := []byte{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}
	length3 := compress(chars3)
	fmt.Println("Compressed length:", length3)
}
