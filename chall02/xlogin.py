import sys

count = len(sys.argv)
if count != 2:
	print("usage: ./xlogin.py <a-zA-Z string>")
	exit()
string = sys.argv[1]
if len(string) == 0:
	print("usage: ./xlogin.py <a-zA-Z string>")
	exit()
res = list(string)
for elem in res:
	if not elem.isalpha() and  elem != ' ':
		print("usage: ./xlogin.py <a-zA-Z string>")
		exit()
morse = {
	"aA": ".-",
	"bB": "-...", 
	"cC": "-.-.",
	"dD": "-..", 
	"eE": ".", 
	"fF": "..-.", 
	"gG": "--.", 
	"hH": "....", 
	"iI": "..", 
	"jJ": ".---", 
	"kK": "-.-", 
	"lL": ".-..", 
	"mM": "--", 
	"nN": "-.", 
	"oO": "---", 
	"pP": ".--.", 
	"qQ": "--.-", 
	"rR": ".-.", 
	"sS": "...", 
	"tT": "-", 
	"uU": "..-", 
	"vV": "...-", 
	"wW": ".--", 
	"xX": "-..-", 
	"yY": "-.--", 
	"zZ": "--.."
}

ret = ""
for elem in res:
	if elem == ' ':
		ret += ' '
	else:
		for key in morse:
			if elem in key:
				ret += morse[key]
print(ret)
exit()
