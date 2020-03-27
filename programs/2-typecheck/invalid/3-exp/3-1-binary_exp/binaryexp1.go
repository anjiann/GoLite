package main

// Error: (line 4) assigment lhs type is incompatible with rhs type [string != bool]
func main() {
	var c = "hello" || true
}