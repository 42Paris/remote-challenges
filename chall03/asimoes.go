package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"regexp"
	"strconv"
	"time"
)

func main() {
	start := time.Now()
	fmt.Printf("%dms - GET http://0.0.0.0:8080/\n", time.Since(start).Milliseconds())
	resp, err := http.Get("http://0.0.0.0:8080/")
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	content, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%dms - GET http://0.0.0.0:8080/\n\tanswer:%s\n", time.Since(start).Milliseconds(), content)
	re := regexp.MustCompile(`id=([0-9]+),r=([0-9]+),g=([0-9]+),b=([0-9]+)`)
	data := re.FindSubmatch(content)
	if len(data) != 5 {
		log.Fatal("Couldn't parse data sent by the server")
	}
	r, err := strconv.Atoi(string(data[2]))
	if err != nil {
		log.Fatal("Couldnt atoi red value")
	}
	g, err := strconv.Atoi(string(data[3]))
	if err != nil {
		log.Fatal("Couldnt atoi green value")
	}
	b, err := strconv.Atoi(string(data[4]))
	if err != nil {
		log.Fatal("Couldnt atoi blue value")
	}
	url := fmt.Sprintf("http://0.0.0.0:8080/?id=%s&resp=%02x%02x%02x", data[1], r, g, b)
	fmt.Printf("%dms - GET %s\n", time.Since(start).Milliseconds(), url)
	resp, err = http.Get(url)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	content, err = ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%dms - GET %s\n\tanswer: %s\n", time.Since(start).Milliseconds(), url, content)
	fmt.Printf("%dms - DONE", time.Since(start).Milliseconds())
}
