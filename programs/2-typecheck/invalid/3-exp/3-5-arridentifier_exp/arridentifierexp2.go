package main 

// Error: (line 6) index must be an int [received rune]
func main() {
	var y [1]int
	y['c'] = 0
}
