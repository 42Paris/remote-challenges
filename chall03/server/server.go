package main

import (
	"context"
	"fmt"
	"log"
	"math/rand"
	"net/http"
	"os"
	"os/signal"
	"strconv"
	"syscall"
	"time"
)

var waitingList = make(map[int]string)
var counter = 0

func randomColor() (r, g, b int) {
	r = rand.Intn(255)
	g = rand.Intn(255)
	b = rand.Intn(255)

	return r, g, b
}

func autoDestroy(id int) {
	time.Sleep(time.Millisecond * 500)
	delete(waitingList, id)
}

func root(w http.ResponseWriter, req *http.Request) {

	if err := req.ParseForm(); err != nil {
		w.WriteHeader(http.StatusInternalServerError)
		fmt.Fprintf(w, "Internal error while Parsing")
	}

	fmt.Printf("%+v", req.URL.Query())
	id := req.URL.Query().Get("id")
	resp := req.URL.Query().Get("resp")

	fmt.Println("id: ", id)
	fmt.Println("resp: ", resp)
	if id != "" && resp != "" {
		fmt.Println("ici2")
		idInt, err := strconv.Atoi(id)
		if err != nil {
			w.WriteHeader(http.StatusUnprocessableEntity)
			fmt.Fprintf(w, "wrong id?")
		}
		if waitingList[idInt] == resp {
			fmt.Fprintf(w, "ok!")
		} else {
			w.WriteHeader(http.StatusNotFound)
			fmt.Fprintf(w, "too slow")
		}
		return
	}
	fmt.Println("ici3")
	counter++
	r, g, b := randomColor()

	waitingList[counter] = fmt.Sprintf("%02x%02x%02x", r, g, b)
	fmt.Fprintf(w, "id=%d,r=%d,g=%d,b=%d - Send your response here: %s/?id=<id>&resp=<hex>", counter, r, g, b, req.Host)
	go autoDestroy(counter)
}

func returnQueue(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "%v", waitingList)
}

func main() {
	srv := &http.Server{
		Handler:      nil,
		Addr:         ":8080",
		ReadTimeout:  10 * time.Second,
		WriteTimeout: 10 * time.Second,
	}

	http.HandleFunc("/", root)
	http.HandleFunc("/queue", returnQueue)
	go func() {
		log.Println("Starting Server")
		if err := http.ListenAndServe("0.0.0.0:8080", nil); err != nil {
			log.Fatal(err)
		}
	}()

	waitForShutdown(srv)
}

func waitForShutdown(srv *http.Server) {
	interruptChan := make(chan os.Signal, 1)
	signal.Notify(interruptChan, os.Interrupt, syscall.SIGINT, syscall.SIGTERM)

	<-interruptChan

	ctx, cancel := context.WithTimeout(context.Background(), time.Second*10)
	defer cancel()
	srv.Shutdown(ctx)

	log.Println("Shutting down")
	os.Exit(0)

}
