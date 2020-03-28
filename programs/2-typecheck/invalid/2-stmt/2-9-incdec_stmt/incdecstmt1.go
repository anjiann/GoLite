package main

// Error: (line 5) incompatible type in increment [received bool, expected numeric (int, rune, float64)]
func main() {
	var x bool
	x++
}