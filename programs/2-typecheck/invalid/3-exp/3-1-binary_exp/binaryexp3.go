package main

//Error: (line 4) incompatible type in relational op < [received bool, expected ordered (int, rune, float64, string)]
func main() {
	var x = true < false
}