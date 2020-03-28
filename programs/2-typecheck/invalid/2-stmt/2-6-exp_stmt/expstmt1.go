package main

// Error: (line 6) expression statement must be a function call
// typecast is not an expression statement
func main() {
	type foo int
	foo(5)
}
