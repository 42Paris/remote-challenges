package main

import "net/http"
import "log"
import "io/ioutil"
import "strings"
import "strconv"
import "fmt"

var (
	host = "https://chall03.hive.fi"
)

func getValue(str string) int {
	val, err := strconv.Atoi(strings.Split(str, "=")[1])
	if err != nil {
		log.Fatalf("GetValue > %s\n", err)
		return 0
	}
	return val
}


func main(){
	resp, err := http.Get(host)
	if err != nil {
		log.Fatal(err)
	}
	if resp.StatusCode != 200 {
		log.Fatalf("Expecting StatusCode 200 got, %d\n", resp.StatusCode)
	}
	body, err := ioutil.ReadAll(resp.Body)
	resp.Body.Close()
	if err != nil {
		log.Fatalf("Unable to read body, %s\n", body)
	}
	sbody := strings.Split(string(body), " ")
	if len(sbody) != 7 {
		log.Fatalf("Expecting 7 args got %d\n", len(sbody))
	}
	args := strings.Split(sbody[0], ",")
	if len(args) != 4 {
		log.Fatalf("Expecting 4 args got %d\n", len(args))
	}
	log.Printf("Received RGB %s\n", args)
	id := getValue(args[0])
	r := getValue(args[1])
	g := getValue(args[2])
	b := getValue(args[3])
	hex := fmt.Sprintf("%02x%02x%02x", r, g, b)
	url := "https://" + strings.Replace(strings.Replace(sbody[6], "<id>", strconv.Itoa(id), 1), "<hex>", hex, 1)
	log.Printf("Sending Hex to %s\n", url)
	req, err := http.Get(url)
	if err != nil {
		log.Fatalf("Unable to send response, %s", err)
	}
	if req.StatusCode != 200 {
		log.Fatalf("Expecting StatusCode 200 got, %d\n", req.StatusCode)
	}
	body, err = ioutil.ReadAll(req.Body)
	if err != nil {
		log.Fatalf("Unable to send response, %s", err)
	}
	log.Printf("Success: %s\n", string(body))
	req.Body.Close()
}
