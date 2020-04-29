package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"time"
)

func makeGetRequest(url string, startTime time.Time) string {
	fmt.Printf("%4dms - GET %s\n", time.Since(startTime).Milliseconds(), url)
	resp, _ := http.Get(url)
	bodyBytes, _ := ioutil.ReadAll(resp.Body)
	body := string(bodyBytes)
	fmt.Printf("%4dms - GET %s\n\tanswer:%s\n", time.Since(startTime).Milliseconds(), url, body)
	return body
}

func main() {
	var id, r, g, b int32
	startTime := time.Now()

	body := makeGetRequest("https://chall03.hive.fi/", startTime)
	fmt.Sscanf(body, "id=%d,r=%d,g=%d,b=%d", &id, &r, &g, &b)
	resp := fmt.Sprintf("?id=%d&resp=%02x%02x%02x", id, r, g, b)
	body = makeGetRequest("https://chall03.hive.fi/" + resp, startTime)

	fmt.Printf("%4dms - DONE\n", time.Since(startTime).Milliseconds())
}
