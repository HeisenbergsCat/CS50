class Student:
    def __init__(self, name, dorm):
        self.name = name
        self.dorm = dorm

    def printStudents(self):
        print("{} is in  {}.". format(self.name, self.dorm))