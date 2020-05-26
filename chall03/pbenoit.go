package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"strconv"
	"strings"
	"time"
)

/*
	AUCUNE GESTION DES ERREURS, LE RETOUR DU GET AURAIT ÉTÉ MIEUX EN JSON.
	TEMPS MOYEN 200ms.
	COMMENTAIRES LIGNE PAR LIGNE ET EXPLICATION DE CHAQUE FONCTION AU DEBUT.
	AUTEUR : Pascal BENOIT
	LOGIN : pbenoit
	Date : 27/04/2020
*/


func GetInfoFromString(s string) (id, ret string) {
	respTab := strings.Split(strings.TrimSpace(strings.Split(s,"-")[0]),",")
	id = strings.Split(respTab[0],"=")[1]

	r,_ := strconv.ParseInt(strings.Split(respTab[1],"=")[1],10,64)

	part1 := strconv.FormatInt(r, 16)
	if len(part1) == 0 {
		part1 = "0" + part1
	}
	g,_ := strconv.ParseInt(strings.Split(respTab[2],"=")[1],10,64)

	part2 := strconv.FormatInt(g, 16)
	if len(part2) == 0 {
		part2 = "0" + part2
	}
	b,_ := strconv.ParseInt(strings.Split(respTab[3],"=")[1],10,64)

	part3 := strconv.FormatInt(b, 16)
	if len(part3) == 0 {
		part3 = "0" + part3
	}
	ret = part1+part2+part3

	return
}

func GetChall03(id, resp string, start time.Time) (string) {

	req, _ := http.NewRequest("GET", "http://0.0.0.0:8080/?", nil)

	q := req.URL.Query()
	if len(id) > 0 && len(resp) > 0 {
		q.Add("id", id)
		q.Add("resp", resp)
	}
	t := time.Now()

	req.URL.RawQuery = q.Encode()
	fmt.Printf("%dms - GET %v\n",t.Sub(start).Milliseconds(),req.URL)
	res, _ := http.DefaultClient.Do(req)
	defer res.Body.Close()
	body, _ := ioutil.ReadAll(res.Body)
	return string(body)
}
func main() {

	start := time.Now()
	resp := GetChall03("","", start)
	fmt.Printf("\t%s\n",resp)

	id, resp2 := GetInfoFromString(resp)

	GetChall03(id,resp2,start)
	resp = GetChall03(id,resp2,start)
	fmt.Printf("\t%s\n",resp)
}

