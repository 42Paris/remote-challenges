package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"regexp"
	"strings"
	"strconv"
)

func main() {
	res, err := http.Get( "https://chall03.hive.fi/")
	if err != nil {
		log.Fatal(err)
	}
	message, err := ioutil.ReadAll(res.Body)
	res.Body.Close()
	if err != nil {
		log.Fatal(err)
	}
	reg, err := regexp.Compile("[^0-9]+")
	if err != nil {
		log.Fatal(err)
	}
	ID := (reg.ReplaceAllString(strings.Split(string(message), "=")[1],""))
	R, err := strconv.Atoi(reg.ReplaceAllString(strings.Split(string(message), "=")[2],""))
	G, err := strconv.Atoi(reg.ReplaceAllString(strings.Split(string(message), "=")[3],""))
	B, err := strconv.Atoi(reg.ReplaceAllString(strings.Split(string(strings.Split(string(message), "=")[4]), " " )[0],""))
	rhex := fmt.Sprintf("%x",R)
	if len(rhex) < 2{
		rhex =  "0" + rhex}
	ghex := fmt.Sprintf("%x",G)
	if len(ghex) < 2{
		ghex = "0" + ghex }
	bhex := fmt.Sprintf("%x",B)
	if len(bhex) < 2{
		bhex = "0" + bhex}
	// fmt.Printf("%s \n", message)
	rgb := rhex + ghex + bhex
	// fmt.Println(R,G,B , rgb)
	res2, err := http.Get( "https://chall03.hive.fi/?id=" +string(ID) + "&resp="+string(rgb))
	if err != nil {
		log.Fatal(err)
	}
	message2, err := ioutil.ReadAll(res2.Body)
	fmt.Printf("%s\n", message2)
	fmt.Println("https://chall03.hive.fi/?id=" +string(ID) + "&resp="+string(rgb))
}