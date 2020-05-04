<h1 align="center"><code>Chall03 / HTTP RGB to Hexadecimal</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/jgengo">Jordane Gengo (Titus)</a>, <a href="">Oleksii Martynovskyi (Disky)</a>, <a href="">Paula Lantran (Ablette)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://hive.fi">Hive Helsinki</a> for all the 42 Network</sub>
</div>

---

### Instructions

<sub>**Turn-in directory:** `chall03/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.go`</sub><br />
<sub>**Language:** `Go`</sub>

<sub>**Deadline:** 29.04.2020 - 23:42am</sub>
<br /><br />
### Subject

<p align="center">
  <img width="350" height="350" src="https://boxopix.fr/hive/golang.png">
</p>

On this chall, you will need to learn how to use `net/http` in Golang to make a GET request to https://chall03.hive.fi/ 

You will receive as a response an id, a RGB value sets and you will have to answer back in less than 400 ms to the server with another HTTP GET the Hexa value of this RGB sets on https://chall03.hive.fi/?id=ID&resp=HEXA 

The hexa doesn't have a `#` this time!!

The output format doesn't matter, what matter is that at the end I'm able to see you get a return status code 200 client-side or a "ok!" body response.

<br /><br />
### Examples

not good
```
[titus@pentest-lab ~ ]$ go run chall03-client.go
0ms - GET https://chall03.hive.fi/
196ms - GET https://chall03.hive.fi/
	answer:id=13,r=72,g=211,b=45 - Send your response here: chall03.hive.fi/?id=<id>&resp=<hex>
1199ms - GET https://chall03.hive.fi/?id=13&resp=48d32d
1214ms - GET https://chall03.hive.fi/?id=13&resp=48d32d
	answer: ko :(
1214ms - DONE
```
good:
```
[titus@pentest-lab ~ ]$ go run chall03-client.go
0ms - GET https://chall03.hive.fi/
209ms - GET https://chall03.hive.fi/
	answer:id=14,r=156,g=103,b=220 - Send your response here: chall03.hive.fi/?id=<id>&resp=<hex>
209ms - GET https://chall03.hive.fi/?id=14&resp=9c67dc
221ms - GET https://chall03.hive.fi/?id=14&resp=9c67dc
	answer: ok!
221ms - DONE
```

### Reward
 - Vous devez faire une description de PR détaillée, expliquant le fonctionnement de votre solution, à savoir le comportement de votre code, pourquoi vous faites tel choix, ce que tel choix est censé faire, ce que chaque étape fait, etc...
 - La description doit être en anglais. Toute PR ne respectant pas les consignes sera refusée.
 - The first one to submit a working solution will earn `30` or `1260` points for their coalition.
 - Everyone else submitting a working solution *(not yet submitted)* will earn `10` or `420` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `5` or `210` points for their coalition.
 
<br /><br />
Good luck!
