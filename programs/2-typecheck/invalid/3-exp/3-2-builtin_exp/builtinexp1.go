package main

//Error: (line 4) capacity builtin expects slice or array type as argument [received string]
func main() {
	var x int = cap("hello world")
}
