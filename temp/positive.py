def main():
    i = getPositiveInt()
    print ("{} is a positive integer".format(i))
    return 0

def getPositiveInt():
    while True:
        print("n is", end =": ")
        n = input()
        n = int(n)
        if n >= 1:
            break
    return n

if __name__ == "__main__":
    main()