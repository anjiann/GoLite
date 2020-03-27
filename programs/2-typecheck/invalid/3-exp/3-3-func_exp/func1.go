package main

//line 9: cannot call non-function foo (type int)
//declaration of foo() is shadowed by the symtable of foo int in main
func foo(){
}

func main() {
	var foo int = 0
	foo()
}
