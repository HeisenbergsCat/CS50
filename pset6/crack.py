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

    crack(sys.argv[1])

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


def crack(hashedPass):
    letters = initLettersArray()

    print("checking 1 letter passwords")
    for i in letters:
        if checkGuess(hashedPass, i) == True:
            return returnPassword(i)
            break

    print("checking 2 letters passwords")
    for i in letters:
        for k in letters:
            if checkGuess(hashedPass, i + k):
                return returnPassword(i + k)
                break

    print("checking 3 letters passwords")
    for i in letters:
        for k in letters:
            for l in letters:
                if checkGuess(hashedPass, i + k + l):
                    return returnPassword(i + k + l)
                    break

    print("checking 4 letters passwords")
    for i in letters:
        for k in letters:
            for l in letters:
                for m in letters:
                    if checkGuess(hashedPass, i + k + l + m):
                        return returnPassword(i + k + l + m)
                        break

if __name__ == "__main__":
    main()