package main

import (
  "net/http"
  "fmt"
  "io/ioutil"
  "time"
  "strconv"
  "log"
)

func parse(str []byte, i int) (int64, int) {
  var ret int64 = 0
  for str[i] >= '0' && str[i] <= '9' {
    ret = 10 * ret + int64(str[i] - '0')
    i++
  }
  return ret, i
}

func gobble(str []byte, i int) (int) {
  for str[i] < '0' || str[i] > '9' {
    i++
  }
  return i
}

func showTime(start time.Time) (string) {
  return strconv.FormatInt(int64(time.Since(start).Seconds() * 1e3), 10)
}

func printBody(getMsg string, body []byte, start time.Time) () {
  str := showTime(start)
  fmt.Println(str, "ms - GET ", getMsg)
  for j := 0; j < len(str); j++ {
    fmt.Print(" ")
  }
  fmt.Println(string(body))
}

func sendGet(getMsg string) []byte {
  resp, err := http.Get(getMsg)
  if (err != nil) {
    log.Fatalln("There was an error:", err)
  }
  defer resp.Body.Close()
  body, _ := ioutil.ReadAll(resp.Body)
  return body
}

func convertColor(color int64) (str string) {
  if (color >= 16) {
    return strconv.FormatInt(color, 16)
  }
  return "0" + strconv.FormatInt(color, 16)
}

func main() {
  var id int64 = 0
  getMsg := "https://chall03.hive.fi/"
  var r int64 = 0
  var g int64 = 0
  var b int64 = 0
  i := 3
  start := time.Now()
  fmt.Println("0ms - GET ", getMsg)
  body := sendGet(getMsg)
  printBody(getMsg, body, start)

  id, i = parse(body, i)
  i = gobble(body, i)
  r, i = parse(body, i)
  i = gobble(body, i)
  g, i = parse(body, i)
  i = gobble(body, i)
  b, i = parse(body, i)

  getMsg = getMsg + "?id=" + strconv.FormatInt(id, 10) + "&resp=" + convertColor(r) +
            convertColor(g) + convertColor(b)
  fmt.Println(showTime(start), "ms - GET ", getMsg)
  body = sendGet(getMsg)
  printBody(getMsg, body, start)
}
