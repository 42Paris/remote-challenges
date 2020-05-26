package main

import (
	"fmt"
	"net/http"
	"io/ioutil"
	"strings"
	"strconv"
)

func getChallenge() string {
	resp, err := http.Get("http://0.0.0.0:8080/")
	if err != nil {
		fmt.Println("Error while requesting challenge")
		return ""
	}
	defer resp.Body.Close()
	bodyBytes, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		fmt.Println("Error while reading body")
		return ""
	}
	bodyString := string(bodyBytes)
	return bodyString
}

// return [id, r, g, b]
func parseData(data string) []int {
	var res []int
	
	utilPart := strings.Split(data, " - ")[0]
	values := strings.Split(utilPart, ",")
	for _, v := range values {
		nbr, _ := strconv.Atoi(strings.Split(v, "=")[1])
		res = append(res, nbr)
	}

	return res
}

func sendResult(id int, hexColor string) {
	url := fmt.Sprintf("http://0.0.0.0:8080/?id=%d&resp=%s", id, hexColor)
	fmt.Println("sending request to: ", url)
	resp, err := http.Get(url)
	if err != nil {
		fmt.Println("Error while sending result", err)
		return 
	}
	defer resp.Body.Close()
	fmt.Println("Status code:", resp.StatusCode)
}

func main() {
	challengeStr := getChallenge()
	if challengeStr == "" {
		return 
	}
	
	fmt.Println(challengeStr)
	
	values := parseData(challengeStr)
	hexColor := fmt.Sprintf("%02x%02x%02x", values[1], values[2], values[3])

	sendResult(values[0], hexColor)
}
