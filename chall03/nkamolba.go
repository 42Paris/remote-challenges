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

	url1 := "http://0.0.0.0:8080/"

	// start
	start := time.Now()
	fmt.Printf("0ms - GET %s\n", url1)

	// get first response
	resp1, err := http.Get(url1)
	if err != nil {
		panic(err)
	}
	defer resp1.Body.Close()

	// read response
	body1, err := ioutil.ReadAll(resp1.Body)
	if err != nil {
		panic(err)
	}

	fmt.Printf("%dms - GET %s\n", time.Now().Sub(start).Milliseconds(), url1)
	fmt.Printf("        answer:%s\n", body1)

	// parse response (substring, split comma, split equal and store to map)
	filtered := string(body1[0 : len(body1)-63])
	fields := strings.Split(filtered, ",")
	value_map := make(map[string]int)

	for _, field := range fields {
		values := strings.Split(field, "=")
		value, err := strconv.Atoi(values[1])
		if err != nil {
			panic(err)
		}
		value_map[values[0]] = value
	}

	// generate new url
	url2 := fmt.Sprintf("http://0.0.0.0:8080/?id=%d&resp=%02x%02x%02x", value_map["id"], value_map["r"], value_map["g"], value_map["b"])
	fmt.Printf("%dms - GET %s\n", time.Now().Sub(start).Milliseconds(), url2)

	// request new response 2
	resp2, err := http.Get(url2)
	if err != nil {
		panic(err)
	}
	defer resp2.Body.Close()

	// read response 2
	body2, err := ioutil.ReadAll(resp2.Body)
	if err != nil {
		panic(err)
	}

	// print result
	fmt.Printf("%dms - GET %s\n", time.Now().Sub(start).Milliseconds(), url2)
	fmt.Printf("        answer: %s\n", body2)
	fmt.Printf("%dms - DONE\n", time.Now().Sub(start).Milliseconds())
}
