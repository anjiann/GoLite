package main

//invalid type assignment, type(myInt) != type(int)
func main() {
    type myInt int
    myInt = 1;
}
