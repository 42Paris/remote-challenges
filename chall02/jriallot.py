import sys

conv = [".-",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--.."]

# On récupère la liste des paramètres d'execution du script et on parcourt cette liste.
# Lors ce que le paramètre est purement alphabétique, on construit une chaine de caractère
# a partir de cette dernière en convertissant chaque caractère par sa correspondance dans un tableau.
# Pour se faire, j'utilise des boucle de parcourt de liste, deux fonction propres aux chainees de
# caractères et ord() qui renvoit la valeur ascii d'un caractère.
for i in sys.argv :
	if i.isalpha() :
		temp = ""
		for c in i :
			temp += conv[ord(c.upper()) - ord('A')]
		print(temp)
