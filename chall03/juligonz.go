package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	url := "https://chall03.hive.fi/"

	// First get to get the rgb color
	resp, _ := http.Get(url)
	bytes, _ := ioutil.ReadAll(resp.Body)
	body := string(bytes)

	var id, r, g, b int
	fmt.Sscanf(body, "id=%d,r=%d,g=%d,b=%d - Send your response here: chall03.hive.fi/?id=<id>&resp=<hex> ", &id, &r, &g, &b)
	params := fmt.Sprintf("?id=%d&resp=%02x%02x%02x", id, r, g, b)

	fmt.Println(params)
	// Second get puting response in url
	resp2, _ := http.Get(url + params)
	bytes2, _ := ioutil.ReadAll(resp2.Body)
	body2 := string(bytes2)

	fmt.Println("response:\n\n", body2)

}
