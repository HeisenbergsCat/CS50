x = 5
y = 2

def swap(a,b):
    tmp = a
    a = b
    b = tmp
    return a, b

x, y = swap(x, y)

print("x: {}, y: {}".format(x, y))