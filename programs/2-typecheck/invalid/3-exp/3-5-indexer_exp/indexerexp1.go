package main

// Error: (line 5) indexing target expects list target (slice, array) [received string]
func main() {
	var x string
	x[0] = 'c'
}
