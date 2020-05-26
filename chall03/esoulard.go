package main

import (
	"net/http"
	"regexp"
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
)

func main() {
	var str1 string
	str1 = "http://0.0.0.0:8080/?id="

	resp, err := http.Get("http://0.0.0.0:8080/")
	if err != nil {
 		fmt.Println(err)
 		os.Exit(1)
 	}

 	defer resp.Body.Close()

 	htmlData, err := ioutil.ReadAll(resp.Body)

	re := regexp.MustCompile(`[-]?\d[\d]*[\.]?[\d{2}]*`)

	submatchall := re.FindAllString(string(htmlData), -1)
	str1 += submatchall[0]
	str1 += "&resp="
	tmpr, errr := strconv.Atoi(submatchall[1])
	hr := fmt.Sprintf("%02x", tmpr)
	tmpg, errg := strconv.Atoi(submatchall[2])
	hg := fmt.Sprintf("%02x", tmpg)
	tmpb, errb := strconv.Atoi(submatchall[3])
	hb := fmt.Sprintf("%02x", tmpb)
	if errr != nil {
 		fmt.Println(errr)
 		os.Exit(1)
 	}
 	if errg != nil {
 		fmt.Println(errg)
 		os.Exit(1)
 	}
 	if errb != nil {
 		fmt.Println(errb)
 		os.Exit(1)
 	}

	str1 += string(hr)
	str1 += string(hg)
	str1 += string(hb)
	
	resp1, err1 := http.Get(string(str1))
	if err1 != nil {
 		fmt.Println(err1)
 		os.Exit(1)
 	}

	defer resp1.Body.Close()

 	htmlData1, err := ioutil.ReadAll(resp1.Body)
 	fmt.Println(os.Stdout, string(htmlData1))
}