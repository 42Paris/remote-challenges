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
	client := &http.Client{}           // Set a Client object
	addr := "https://chall03.hive.fi/" // First addr
	start := time.Now()                // Get the start time to time everything

	fmt.Println(time.Now().Sub(start), " - GET ", addr) // Print the request
	req, err := http.NewRequest("GET", addr, nil)       // Prepare the request
	if err != nil {                                     // Check for errors
		log.Fatal(err)
	}

	resp, err := client.Do(req) // Execute the request
	if err != nil {             // Check for error
		log.Fatal(err)
	}
	if resp.StatusCode != 200 {
		log.Fatalf("HTTP : %d", resp.StatusCode)
	}

	defer resp.Body.Close()                // Will close the Body when done
	body, err := ioutil.ReadAll(resp.Body) // Read the Body
	if err != nil {                        // Check for errors
		log.Fatal(err)
	}
	fmt.Println(time.Now().Sub(start), " - GET ", addr) // Print the answer
	fmt.Printf("answer : %s\n", body)

	reg, err := regexp.Compile(`id=(\d+),r=(\d+),g=(\d+),b=(\d+)`) // Compile a regexp that will get what we need
	if err != nil {                                                // Check for errors
		log.Fatal(err)
	}
	strs := reg.FindSubmatch(body)          // Execute the regexp with the FindSubmatch method
	id := string(strs[1])                   // Convert id to string
	r, err := strconv.Atoi(string(strs[2])) // Convert r, g and b to int
	if err != nil {                         // Check for errors
		log.Fatal(err)
	}
	g, err := strconv.Atoi(string(strs[3]))
	if err != nil { // Check for errors
		log.Fatal(err)
	}
	b, err := strconv.Atoi(string(strs[4]))
	if err != nil { // Check for errors
		log.Fatal(err)
	}

	hex := fmt.Sprintf("%02x%02x%02x", r, g, b) // Format r, g and b to hex with 2 width and "0" padding

	addr = fmt.Sprintf("%s?id=%s&resp=%s", addr, id, hex) // New address

	fmt.Println(time.Now().Sub(start), " - GET ", addr) // Print the new request
	req, err = http.NewRequest("GET", addr, nil)        // Prepare the request
	if err != nil {                                     // Check for errors
		log.Fatal(err)
	}

	resp, err = client.Do(req) // Execute the request
	if err != nil {            // Check for errors
		log.Fatal(err)
	}
	if resp.StatusCode != 200 {
		log.Fatalf("HTTP : %d", resp.StatusCode)
	}

	defer resp.Body.Close()               // Will close the Body when done
	body, err = ioutil.ReadAll(resp.Body) // Read the Body
	if err != nil {                       // Check for errors
		log.Fatal(err)
	}
	fmt.Println(time.Now().Sub(start), " - GET ", addr) // Print the answer
	fmt.Printf("answer : %s\n", body)
}
