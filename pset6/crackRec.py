import hashlib
import crypt
import sys
import os


def main():

    if len(sys.argv) == 2:
        hashString = sys.argv[1]
    else:
        print ("Usage: crack.py hash")
        quit()

    crackRec(2)

def initLettersArray():
    letters = []
    for i in range(97, 123):
        letters.append(chr(i))
    for i in range(65, 91):
        letters.append(chr(i))
    return letters


def checkGuess(hashedPass, i):
    guess = crypt.crypt(i, salt = "50")
    if guess == hashedPass:
        return True

def returnPassword(i):
    print("found password: {}".format(i))
    return i


def crackRec(depth):
    letters = ['a', 'b']
    out=[]
    if depth != 0:
        for i in letters:
            crackRec(depth - 1)

if __name__ == "__main__":
    main()