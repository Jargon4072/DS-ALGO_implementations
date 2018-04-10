import os
import sys

class Animal:
    __name = None
    __height = 0
    __weight = 0
    __sound = 0

    def set_name(self, name):
        self.__name = name

    def get_name(self):
        return self.__name
        print("hnbssnb")

    def set_height(self, height):
        self.__height = height

    def get_height(self):
        return self.__height

    def set_weight(self, weight):
        self.__weight = weight

    def get_weight(self):
        return self.__weight

    def set_sound(self, sound):
        self.__name = sound

    def get_sound(self):
        return self.__sound

    def __init__(self, name, height, weight, sound):
        self.__name = name
        self.__height = height
        self.__weight = weight
        self.__sound = sound

    def get_type(self):
        print("Animal")

    def toString(self):
        print("{} is {}cm tall and {}kg and says {}".format(self.__name, self.__height,  self.__weight, self.__sound))
'''
class Dog(Animal):
    __owner = ""

    def set_owner(self,owner):
        self.__owner = owner

    def get_owner(self):
        return self.__owner

    def __init__(self, name, height, weight, sound, owner):
        self. __owner__  = owner
        super(Dog, self).__init__(name, height, weight, sound)

    def get_type(self):
        print("Dog")

    def toString(self):
        print("{} is {}cm tall and {}kg and says {} and owner is {}".format(self.get_name(),self.get_height(),self.get_weight(),self.get_sound(),self.get_owner()))
'''
'''spot = Dog("Rocky",110,40,"Ruff","Chandan")
#spot.toString()'''

cat = Animal("khalisi", 50, 20, "meow")
cat.toString()
#print(cat.toString())
