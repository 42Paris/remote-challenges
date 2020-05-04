package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"strconv"
	"strings"
)

func sendRequest(req string) string {
	response, err := http.Get(req)
	body, err := ioutil.ReadAll(response.Body)
	if err != nil {
		log.Fatalln(err)
	}
	response.Body.Close()
	return string(body)
}

func main() {
	res, err := http.Get("https://chall03.hive.fi/")
	if err != nil {
		log.Fatal(err)
	}
	response, err := ioutil.ReadAll(res.Body)
	if err != nil {
		log.Fatal(err)
	}
	res.Body.Close()
	result := strings.Split(string(response), "-")
	params := strings.Split(result[0], ",")
	id := strings.Split(params[0], "=")[1]
	r, err := strconv.Atoi(strings.Split(params[1], "=")[1])
	g, err := strconv.Atoi(strings.Split(params[2], "=")[1])
	b, err := strconv.Atoi(strings.TrimSpace(strings.Split(params[3], "=")[1]))
	if err != nil {
		log.Fatal(err)
	}
	req := fmt.Sprintf("https://chall03.hive.fi/?id=%s&resp=%02x%02x%02x", id, r, g, b)
	bodyResponse := sendRequest(req)
	fmt.Printf("answer = %s\n", bodyResponse)
}
