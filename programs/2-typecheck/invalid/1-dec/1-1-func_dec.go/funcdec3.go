package main

func main() {
}

//(spec 2.3) bar redeclared in this block; function overload not supported
func bar(x string) int {
	return 0
}

func bar() int {
	return 0
}
