package main

import(
	"fmt"
	"log"
	"time"
	"io/ioutil"
	"net/http"
	"regexp"
	"strconv"
)

const URL = "https://chall03.hive.fi/"

func parse_input(input []byte) map[string]int {
	re := regexp.MustCompile(`([0-9]+)`)
	values := re.FindAll(input, 4)

	var parsed_input = make(map[string]int)
	if s, err := strconv.Atoi(string(values[0])); err == nil {
		parsed_input["id"] = s
	}
	if s, err := strconv.Atoi(string(values[1])); err == nil {
		parsed_input["R"] = s
	}
	if s, err := strconv.Atoi(string(values[2])); err == nil {
		parsed_input["G"] = s
	}
	if s, err := strconv.Atoi(string(values[3])); err == nil {
		parsed_input["B"] = s
	}
	return parsed_input
}

func get_input() map[string]int {
	resp, err := http.Get(URL)
	if err != nil {
		log.Fatal(err)
	}
	input, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	return parse_input(input)
}

func compute_hexa(input map[string]int) string {
	return fmt.Sprintf("%02x%02x%02x", input["R"], input["G"], input["B"])
}

func submit(id int, hexa_value string) string {
	var out_url = fmt.Sprintf("%s?id=%d&resp=%s", URL, id, hexa_value)
	resp, err := http.Get(out_url)
	if err != nil {
		log.Fatal(err)
	}
	answer, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()

	return string(answer)
}

func get_ms_from_start(start int64) int64 {
	return (time.Now().UnixNano() - start) / 1000000
}

func main() {
	// Get and parse values from server
	var start = time.Now().UnixNano()
	fmt.Printf("%4dms - GET %s ...", get_ms_from_start(start), URL)
	var input = get_input()
	fmt.Printf(" =>\033[0;33m Id = %d, R = %d, G = %d, B = %d\033[0m\n", input["id"], input["R"], input["G"], input["B"], )

	// Compute hexa value from RGB
	fmt.Printf("%4dms - Calculating ...", get_ms_from_start(start))
	var hexa_value = compute_hexa(input)
	fmt.Printf(" =>\033[0;33m %s\033[0m\n", hexa_value)

	// Send request with hexa value
	var out_url = fmt.Sprintf("%s?id=%d&resp=%s", URL, input["id"], hexa_value)
	fmt.Printf("%4dms - GET %s ...", get_ms_from_start(start), out_url)
	var answer = submit(input["id"], hexa_value)

	//print answer
	if answer == "ok!" {
		fmt.Printf(" =>\033[0;32m %s\033[0m\n", answer)
	} else {
		fmt.Printf(" =>\033[0;31m %s\033[0m\n", answer)
	}

	fmt.Printf("%4dms - Done\n", get_ms_from_start(start))
}
