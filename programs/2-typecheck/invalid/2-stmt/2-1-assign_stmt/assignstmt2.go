package main

// Error: (line 7) string is not assignment compatible with int in assign statement
func main() {
	var a string = "hello"
	var b int
	b = a
}