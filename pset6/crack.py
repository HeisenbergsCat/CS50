import hashlib
import crypt
import sys

def main():

    if len(sys.argv) == 2:
        hashString = sys.argv[1]
    else:
        print ("Usage: crack.py hash")
        quit()

    #crypted = crypt.crypt("JH", salt="50")
    #print(crypted)
    crack()

def crack():

    letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']

    for i in letters:
        print (i)
        for k in letters:
            print (i + k)
            for l in letters:
                print (i + k + l)
                for m in letters:
                    print(i + k + l + m)

if __name__ == "__main__":
    main()