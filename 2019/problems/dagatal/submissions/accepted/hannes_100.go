package main

import (
	"fmt"
)

func main() {
	var month int
	var days [12]int = [12]int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	fmt.Scan(&month)
	fmt.Println(days[month-1])
}
