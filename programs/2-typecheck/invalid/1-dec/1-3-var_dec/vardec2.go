package main

// Error: (line 5) string is not assignment compatible with int in variable declaration
func main() {
	var a, b int = 0, "hello"
}
