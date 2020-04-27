package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"strconv"
	"strings"
)

func main() {
	res, err := http.Get("https://chall03.hive.fi/")
	if err != nil {
		panic("cannot make request to https://chall03.hive.fi/")
	}
	raw, err := ioutil.ReadAll(res.Body)
	if err != nil {
		panic("unable to read body")
	}
	defer res.Body.Close()

	parts := strings.Split(string(raw), "-")
	if len(parts) != 2 {
		panic("badly formatted response")
	}
	parts = strings.Split(parts[0], ",")
	if len(parts) != 4 {
		panic("badly formatted response")
	}
	id, err := strconv.Atoi(strings.Split(parts[0], "=")[1])
	if err != nil {
		panic("id not an int")
	}
	r, err := strconv.Atoi(strings.Split(parts[1], "=")[1])
	if err != nil {
		panic("r not an int")
	}
	g, err := strconv.Atoi(strings.Split(parts[2], "=")[1])
	if err != nil {
		panic("g not an int")
	}
	b, err := strconv.Atoi(strings.Trim(strings.Split(parts[3], "=")[1], " "))
	if err != nil {
		panic("b not an int")
	}
	hexa := fmt.Sprintf("%X%X%X", r, g, b)

	res, err = http.Get(fmt.Sprintf("https://chall03.hive.fi/?id=%d&resp%s", id, hexa))
	if err != nil {
		panic("error sending hexa")
	}
	if res.StatusCode != http.StatusOK {
		panic("error bad response code")
	}
}
