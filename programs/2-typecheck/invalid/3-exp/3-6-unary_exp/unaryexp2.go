package main

// Error: (line 4) incompatible type in unary op ! [received string, expected bool]
func main() {
	var x = !("hello" + "world")
}
