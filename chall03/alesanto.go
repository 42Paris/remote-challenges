package main

// go run alesanto.go

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"time"
	"log"
)

func main() {
	start := time.Now()

	url := "https://chall03.hive.fi/"
	fmt.Printf("%dms - GET %s\n", time.Since(start).Milliseconds(), url)
	resp, err:= http.Get(url)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	bytes, err:= ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	body := string(bytes)
	fmt.Printf("%dms - GET %s\n\tanswer:%s\n", time.Since(start).Milliseconds(), url, body)
	var id, r, g, b int
	fmt.Sscanf(body, "id=%d,r=%d,g=%d,b=%d", &id, &r, &g, &b)
	param := fmt.Sprintf("?id=%d&resp=%02x%02x%02x", id, r, g, b)
	fmt.Printf("%dms - GET %s\n", time.Since(start).Milliseconds(), url + param)
	resp, err = http.Get(url + param)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	bytes, err = ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	body = string(bytes)
	fmt.Printf("%dms - GET %s\n\tanswer:%s\n", time.Since(start).Milliseconds(), url + param, body)
	fmt.Printf("%dms - DONE\n", time.Since(start).Milliseconds())
}
