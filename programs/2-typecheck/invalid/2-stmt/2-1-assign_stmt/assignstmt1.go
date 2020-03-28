package main

//Error: (line 6) int is not assignment compatible with myInt in variable declaration
func main() {
    type myInt int
    var a myInt = 1;
}
