import cs50

def main():
    colh = inputHeight()
    drawPyramid(colh)

def drawPyramid(colh):

    #main pyramid loop
    for i in range(colh):
        #in single line print proper number of spaces
        for k in range(colh - i - 1):
            print(" ", end = "")
        #in same line print proper number of hashes
        for j in range(i + 2):
            print("#", end = "")
        #still in the same line print a space for center of the pyramid
        print(" ", end ="")
        #and complete the other side
        for k in range(i + 2):
            print("#", end = "")
        #print the newline and proceed to the next loop iteration (next line)
        print()

def inputHeight():
    while(True):
        print ("Input the column height(<23):", end = " ")
        colh = cs50.get_int();
        if colh > 0 and colh < 24:
            break
    return colh


if __name__ == "__main__":
    main()