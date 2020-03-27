package main

//(spec 2.3) x redeclared in this block
func foo(x int) {
	var x float64 = 'c'
}

func main() {
	
}