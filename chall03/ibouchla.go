package main


import "fmt"
import "log"
import "time"
import "strings"
import "strconv"
import "net/http"
import "io/ioutil"

func ConvertHex(r int, g int, b int) string {
	const	str = "0123456789abcdef"
	var		hex = []byte("000000")

	hex[0] = str[r / 16];
	hex[1] = str[r % 16];
	hex[2] = str[g / 16];
	hex[3] = str[g % 16];
	hex[4] = str[b / 16];
	hex[5] = str[b % 16];
	return (string(hex))
}

func main() {
	start := time.Now()
	var client http.Client

	// Store response of the [GET] request and check the status code
	fmt.Println("0ms - GET https://chall03.hive.fi/")
	resp, err := client.Get("https://chall03.hive.fi/")
	elapsed := time.Now().Sub(start).Milliseconds()
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()

	if resp.StatusCode == http.StatusOK {
		bodyBytes, err := ioutil.ReadAll(resp.Body)
		if err != nil {
			log.Fatal(err)
		}
		// Parse body response with `id`, `r`, `g`, `b` attrs
		bodyText := string(bodyBytes)
		body := strings.Split(bodyText, ",")
		fmt.Printf("%vms - GET https://chall03.hive.fi/\n\t%s\n", elapsed, bodyText)
		id := body[0][3:]
		r, err := strconv.Atoi(body[1][2:])
		g, err := strconv.Atoi(body[2][2:])
		b, err := strconv.Atoi(body[3][2:strings.Index(body[3], "-") - 1])
		if err != nil {
			log.Fatal(err)
		}
		// Convert `RGB` to `HEX` color and send it in a [GET] request
		hex := ConvertHex(r, g, b)
		url := "https://chall03.hive.fi/?id=" + id + "&resp=" + hex
		fmt.Printf("%vms - GET %s\n", elapsed, url)
		resp, err := http.Get(url)
		elapsed := time.Now().Sub(start).Milliseconds()
		fmt.Printf("%vms - GET %s\n", elapsed, url)
		if resp.StatusCode == http.StatusOK {
			fmt.Println("\tanswer: ok!")
		} else {
			fmt.Println("\tanswer: ko :(")
		}
		fmt.Printf("%vms - DONE\n", elapsed)
	}
}
