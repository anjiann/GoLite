package main

//invalid assignment, lhs must be a lvalue
//line 7: cannot assign to 3 + 2
func main() {
	var a int;
	(3 + 2) = a
}
