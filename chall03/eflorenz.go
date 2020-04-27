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
	client := &http.Client{}
	addr := "https://chall03.hive.fi/"
	start := time.Now()

	fmt.Println(time.Now().Sub(start), " - GET ", addr) // On annonce la requète
	req, err := http.NewRequest("GET", addr, nil)       // On prépare la requète
	if err != nil {                                     // Gestion d'erreur
		log.Fatal(err)
	}

	resp, err := client.Do(req) // On execute la requète
	if err != nil {             // Gestion d'erreur
		log.Fatal(err)
	}
	if resp.StatusCode != 200 {
		log.Fatalf("HTTP : %d", resp.StatusCode)
	}

	defer resp.Body.Close()                             // On fermera le Body après sa lecture
	body, _ := ioutil.ReadAll(resp.Body)                // On lit l'entièreté du Body
	fmt.Println(time.Now().Sub(start), " - GET ", addr) // On annonce qu'on a bien reçu une réponse
	fmt.Printf("answer : %s\n", body)

	reg, _ := regexp.Compile(`id=(\d+),r=(\d+),g=(\d+),b=(\d+)`) // On compile une regexp pour extraire les informations qui nous intéresse du body
	strs := reg.FindSubmatch(body)                               // On cherche les match et les submatchs (groupes entre paranthèses)
	id, _ := strconv.Atoi(string(strs[1]))                       // On converti tout ça vers des int
	r, _ := strconv.Atoi(string(strs[2]))
	g, _ := strconv.Atoi(string(strs[3]))
	b, _ := strconv.Atoi(string(strs[4]))

	hex := fmt.Sprintf("%02x%02x%02x", r, g, b) // On converti les rgb vers leur format hexadécimal d'arrivée
	//fmt.Println(id)
	//fmt.Println(hex)

	addr = fmt.Sprintf("https://chall03.hive.fi/?id=%d&resp=%s", id, hex) // On fait un string de la nouvelle adresse

	fmt.Println(time.Now().Sub(start), " - GET ", addr) // On annonce la nouvelle requète
	req, _ = http.NewRequest("GET", addr, nil)          // On prépare la requète
	if err != nil {                                     // Gestion d'erreur
		log.Fatal(err)
	}

	resp, _ = client.Do(req) // On execute la requète
	if err != nil {          // Gestion d'erreur
		log.Fatal(err)
	}
	if resp.StatusCode != 200 {
		log.Fatalf("HTTP : %d", resp.StatusCode)
	}

	defer resp.Body.Close()                             // On fermera le Body quand on l'aura lu
	body, _ = ioutil.ReadAll(resp.Body)                 // On lit le Body entièrement
	fmt.Println(time.Now().Sub(start), " - GET ", addr) // On annonce qu'on a bien reçu la réponse
	fmt.Printf("answer : %s\n", body)
}
