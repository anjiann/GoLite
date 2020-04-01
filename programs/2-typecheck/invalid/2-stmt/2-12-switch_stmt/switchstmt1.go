package main

// Error: (line 6) switch statement expresion type is incompatible with case type [string != int]
func main() {
	var x int
	switch(x) {
		case "hello":
	}
}
