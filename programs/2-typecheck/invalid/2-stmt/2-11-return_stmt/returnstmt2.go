package main

func main() {
}

// Error: (line 8) int is not assignment compatible with float64 in return statement
func foo() int {
	return 3.14
}