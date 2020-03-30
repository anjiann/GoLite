package main

func main() {

}

func getInt() int {
	return 1
}
func indexer_exp() {
	var x, y [1]int
	var z [1][1]int
	var index int = 0
	x = y
	x[index] = 0
	x[getInt()] = 0
	x[z[0][0]] = 0

	z[0][0] = 0
}
