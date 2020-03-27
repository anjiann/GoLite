package main

//Error: (line 4) incompatible type in unary op + [received string, expected numeric (int, rune, float64)]
func main() {
	var x = +"hello"
}