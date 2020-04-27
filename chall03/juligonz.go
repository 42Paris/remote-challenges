package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"time"
)

// Getbody Print the query time and the body. Return the body from the GET query.
func Getbody(url string) string {
	start := time.Now()
	resp, _ := http.Get(url)
	bytes, _ := ioutil.ReadAll(resp.Body)
	body := string(bytes)
	fmt.Printf("• %4dms - GET %s\n    %s\n\n", time.Since(start).Milliseconds(), url, body)
	return body
}

// Getparams Build and return the parameter string
func Getparams(body string) string {
	var id, r, g, b int
	fmt.Sscanf(body, "id=%d,r=%d,g=%d,b=%d", &id, &r, &g, &b)
	params := fmt.Sprintf("?id=%d&resp=%02x%02x%02x", id, r, g, b)
	return params
}

func main() {
	url := "https://chall03.hive.fi/"

	body := Getbody(url)
	params := Getparams(body)
	Getbody(url + params)
}
