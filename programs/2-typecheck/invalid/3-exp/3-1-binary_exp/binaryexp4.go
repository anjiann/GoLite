package main

//Error: (line 4) incomatible type in arithmetic op + [received bool, expected numeric (int, rune, float64) or string]
func main() {
	var x = true + true
}

// Error: (line 5) assigment lhs type is incompatible with rhs type [float64 != int]
func foo() {
	var x = 1.1 + 1
}