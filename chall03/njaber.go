package main

import (
	"fmt"
	"net/http"
	"io/ioutil"
	"log"
	"time"
)

type logWriter struct {
}

var start time.Time

func (writer logWriter) Write(bytes []byte) (int, error) {
	timestamp := time.Since(start)
	return fmt.Printf("%3.3fs - %s", timestamp.Seconds(), string(bytes))
}

func main() {
	start = time.Now()
	log.SetFlags(0)
	log.SetOutput(new(logWriter))

	url := "https://chall03.hive.fi/"

	log.Print("GET " + url)
	resp1, err := http.Get(url)
	if err != nil {
		log.Fatal("la callotte de ses morts")
	}
	defer resp1.Body.Close()
	body, err := ioutil.ReadAll(resp1.Body)
	if err != nil {
		log.Fatal("le sang de ses morts")
	}

	bodyStr := string(body)
	log.Print(bodyStr)

	var id, r, g, b int
	fmt.Sscanf(bodyStr, "id=%d,r=%d,g=%d,b=%d", &id, &r, &g, &b)
	log.Printf("id:%d,r:%d,g:%d,b:%d", id, r, g, b)

	answer := fmt.Sprintf("%s?id=%d&resp=%02.2x%02.2x%02.2x", url, id, r, g, b)
	log.Printf("Get " + answer)

	resp2, err := http.Get(answer)
	if err != nil {
		log.Fatal("la callotte de ses morts")
	}
	defer resp2.Body.Close()
	body, err = ioutil.ReadAll(resp2.Body)
	if err != nil {
		log.Fatal("le sang de ses morts")
	}

	bodyStr = string(body)
	log.Print(bodyStr)
}
