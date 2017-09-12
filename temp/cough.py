def main():
        coughsneeze(3, "cough")
        coughsneeze(3, "achoo")

def coughsneeze(n, word):
    for i in range(n):
        say(word)

def say(word):
    print(word)

if __name__ == "__main__":
    main()