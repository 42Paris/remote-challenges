package main

import (
	"net/http"
	"io/ioutil"
	"log"
	"fmt"
	"regexp"
	"strconv"
)

func main() {
	resp, err := http.Get("https://chall03.hive.fi/")
	if err != nil {
		log.Fatal(err)
		return
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
		return
	}
	s := string(body)
	re := regexp.MustCompile(`(?:id|r|g|b)=(\d*)`)
	submatchall := re.FindAllStringSubmatch(s, -1)
	if (len(submatchall) != 5) {
		return
	}
	r, _ := strconv.Atoi(submatchall[1][1])
	g, _ := strconv.Atoi(submatchall[2][1])
	b, _ := strconv.Atoi(submatchall[3][1])
	hex := fmt.Sprintf("%02x%02x%02x", r, g, b)
	url := fmt.Sprintf("https://chall03.hive.fi/?id=%s&resp=%s", submatchall[0][1], hex)
	send, err := http.Get(url)
	if err != nil {
		log.Fatal(err)
		return
	}
	defer send.Body.Close()
	fmt.Printf("%d\n", send.StatusCode)
}
