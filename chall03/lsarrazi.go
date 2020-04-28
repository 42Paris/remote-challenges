/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsarrazi.go                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarrazi <lsarrazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:24:14 by lsarrazi          #+#    #+#             */
/*   Updated: 2020/04/27 16:24:14 by lsarrazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"
	"strconv"
	"time"
)

// URL of the chall03 server
const URL = "https://chall03.hive.fi/"

// Chall03Command store RGB to hex conversion command of the chall03 server
type Chall03Command struct {
	id int
	r  byte
	g  byte
	b  byte
}

func main() {
	commandString := fetchSync(URL)
	fmt.Println("COMMAND:", commandString, "\n ")
	command := parseCommand(commandString)
	color := executeCommand(command)

	start := time.Now()
	answer := getAnswer(command, color)
	fmt.Printf("ANSWER: %s (took %d ms)", answer, time.Now().Sub(start).Milliseconds())
}

func fetchSync(url string) string {
	resp, httpError := http.Get(url)
	if httpError != nil {
		fmt.Println(httpError)
		os.Exit(1)
	}
	fmt.Println("GET: \"" + url + "\"")
	defer resp.Body.Close()
	body, ioError := ioutil.ReadAll(resp.Body)
	if ioError != nil {
		fmt.Println(ioError)
		os.Exit(1)
	}
	return string(body)
}

func parseCommand(req string) Chall03Command {
	command := Chall03Command{}
	reqRegexp := regexp.MustCompile(`([a-zA-Z]+)=([0-9]+)`)
	submatches := reqRegexp.FindAllStringSubmatch(req, -1)
	for _, match := range submatches {
		operand, _ := strconv.Atoi(match[2])
		switch match[1] {
		case "id":
			command.id = operand
		case "r":
			command.r = byte(operand)
		case "g":
			command.g = byte(operand)
		case "b":
			command.b = byte(operand)
		}
	}
	return command
}

func byteToHex(b byte) byte {
	if b >= 10 {
		return b - 10 + 'a'
	}
	return b + '0'
}

func executeCommand(command Chall03Command) string {
	color := []byte{
		byteToHex(command.r >> 4),
		byteToHex(command.r & 0xF),
		byteToHex(command.g >> 4),
		byteToHex(command.g & 0xF),
		byteToHex(command.b >> 4),
		byteToHex(command.b & 0xF)}
	return string(color)
}

func getAnswer(command Chall03Command, color string) string {
	commandIDString := strconv.Itoa(command.id)
	url := URL + "?id=" + commandIDString + "&resp=" + color
	return fetchSync(url)
}
