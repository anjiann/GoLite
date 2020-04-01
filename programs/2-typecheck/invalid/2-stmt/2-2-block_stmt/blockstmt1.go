package main

//Error: (line 7) x is not declared
func main() {
	{
		var x string = "x declared in this block"
	}
	x = "outside block, x not declared in this scope"
}
