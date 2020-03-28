package main

//Error: (line 4) incompatible type in unary op ^ [received float64, expected integer (int, rune)]
func main() {
	var x = ^1.1
}
