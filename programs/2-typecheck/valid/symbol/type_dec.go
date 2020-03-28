package main

func main() {
	type num int
	type natural num

	type floats [5]float64
	type naturals [5]natural
	type naturals2D [5]naturals
	type naturals5D [1][2][3][4]naturals

	type intAlias int
	type floatAlias float64
	type boolAlias bool
	type char rune
	type stringAlias string	
}
