import cs50
import sys

def main():
    printChars()

def helloArgv():
    if len(sys.argv) == 2:
        print ("Hello, {}".format(sys.argv[1]))
    else:
        print ("Hello, World")

def chars():
    for i in range(65, 65 + 26):
        print ("{} is {}".format(chr(i), i))

def printArgvs():
    for i in range(len(sys.argv)):
        print(sys.argv[i])

def printChars():
    for s in sys.argv:
        for c in s:
            print(c)
        print()

if __name__ == "__main__":
    main()

