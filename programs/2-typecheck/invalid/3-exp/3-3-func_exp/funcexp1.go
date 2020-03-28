package main

//Error: (line 10) foo is not a function type
//declaration of foo() is shadowed by the symtable of foo int in main
func foo(){
}

func main() {
	var foo int = 0
	foo()
}
