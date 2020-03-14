package main

//invalid type assignment, type(myInt) != type(int)
func main() {
    type myInt int
    var a myInt = 1;
}
