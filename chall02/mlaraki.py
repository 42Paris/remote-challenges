import sys

morse = {
'a' :'.-',
'b' : '-...', 
'c' : '-.-.', 
'd' : '-..', 
'e' : '.' ,
'f' : '..-.', 
'g' :'--.' ,
'h' :'....' ,
'i' :'..' ,
'j' : '.---', 
'k' :'-.-' ,
'l' :'.-..' ,
'm' :'--' ,
'n' :'-.' ,
'o' :'---' ,
'p' :'.--.' ,
'q' :'--.-' ,
'r' :'.-.',
's' :'...' ,
't' :'-',
'u' :'..-' ,
'v' :'...-' ,
'w' :'.--' ,
'x' :'-..-' ,
'y' :'-.--' ,
'z' : '--..',
' ' : ' '
}

def error():
  print("usage: ./mlaraki.py <a-zA-Z string>")
  exit(1)

def convert():
    text = sys.argv[1].lower()
    result = ""
    for el in text:
        try:
          result += morse[el]
        except:
          error()
    print(result)

def main():
    if len(sys.argv) != 2 or len(sys.argv[1]) == 0:
        error()
    else:
        convert()

if __name__ == "__main__":
    main()
