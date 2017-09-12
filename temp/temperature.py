import cs50

def main():
    f = input("float: ")
    c = 5 / 9 * (f - 32)
    print ("{:.1f}".format(c))

if __name__ == "__main__":
    main()
