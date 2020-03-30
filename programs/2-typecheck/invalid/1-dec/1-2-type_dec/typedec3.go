package main

type num int

func main() {
	var num int = 0
	type foo num // Error: (line 7) num is not a type
}
