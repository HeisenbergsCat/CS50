def main():
    cNumber = input("Card Number: ")
    checkSum = 0;
    for digit in cNumber[-2::-2]:
        checkSum += sumProductDigits(int(digit) * 2)
    for digit in cNumber[::-2]:
        checkSum += sumProductDigits(digit)

    if checkSum % 10 == 0:
        cSignature = cNumber[0] + cNumber[1]
        if cSignature == "34" or cSignature == "37":
            print("AMEX")
        elif 51<= int(cSignature) <= 55:
            print("MASTERCARD")
        elif cNumber[0] == "4":
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")

# neat solution for adding number's products found on Stack Overflow
def sumProductDigits(number):
    sum = 0
    intnumber = int(number)
    while intnumber:
        #division by 10 remainder of any base10 number will always be it's last digit
        sum += intnumber % 10
        #if a base10 number is divided by 10 and floored, it shaves off the last digit
        intnumber //= 10
    return sum

if __name__ == "__main__":
    main()