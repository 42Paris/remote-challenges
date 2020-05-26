package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"strconv"
	"strings"
	"time"
)

func main() {
	start := time.Now()
	fmt.Print("0ms: GET http://0.0.0.0:8080/\n")
	res, err := http.Get("http://0.0.0.0:8080/")
	if err != nil {
		panic("cannot make request to http://0.0.0.0:8080/")
	}
	raw, err := ioutil.ReadAll(res.Body)
	if err != nil {
		panic("unable to read body")
	}
	defer res.Body.Close()
	fmt.Printf("%s: GET http://0.0.0.0:8080/\n\t - answer: %s\n", time.Since(start), string(raw))

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
	hexa := fmt.Sprintf("%02x%02x%02x", uint16(r), uint16(g), uint16(b))

	endpoint := fmt.Sprintf("http://0.0.0.0:8080/?id=%d&resp=%s", id, hexa)
	fmt.Printf("%s: GET %s\n", time.Since(start), endpoint)
	res, err = http.Get(endpoint)
	if err != nil {
		panic("error sending hexa")
	}
	/*if res.StatusCode != http.StatusOK {
		panic("error bad response code")
	}*/
	raw, err = ioutil.ReadAll(res.Body)
	if err != nil {
		panic("cannot read body")
	}
	defer res.Body.Close()
	fmt.Printf("%s: GET %s\n\t - answer: %s\n", time.Since(start), endpoint, string(raw))
}
