package main

import (
    "io/ioutil"
    "fmt"
    "net/http"
    "time"
    "regexp"
    "strconv"
)

func printWithTimestamp(start time.Time, a ...interface{}) {
    fmt.Print(time.Now().Sub(start).Nanoseconds() / 1000000, "ms - ")
    fmt.Println(a...)
}

func getWithTimestamp(start time.Time, url string) (*http.Response, string) {
    printWithTimestamp(start, "GET", url)
    resp, err := http.Get(url)
    defer resp.Body.Close()
    if err != nil { panic(err) }
    bytes , err2 := ioutil.ReadAll(resp.Body)
    if err2 != nil { panic(err2) }
    body := string(bytes)
    printWithTimestamp(start, "GET", url)
    fmt.Println("        answer:", body)
    return resp, body
}

func main() {
    start := time.Now()
    _, body := getWithTimestamp(start, "https://chall03.hive.fi/")
    values := regexp.MustCompile("[0-9]+").FindAllString(body, 4)
    id, _ := strconv.Atoi(values[0])
    r, _ := strconv.Atoi(values[1])
    g, _ := strconv.Atoi(values[2])
    b, _ := strconv.Atoi(values[3])
    getWithTimestamp(start, fmt.Sprintf(
                "https://chall03.hive.fi/?id=%d&resp=%02.2x%02.2x%02.2x",
                id, r, g, b))
    printWithTimestamp(start, "DONE")
}
