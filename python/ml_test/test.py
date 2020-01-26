#test the algo
'''
Author: Chandan Dwivedi
Date: 04/02/2019

Instructions: Please keep this file and 'waterStored.py' file in same directory and execute test.py as:
python3 test.py [on Linux]
py -3 test.py   [on Windows]
'''
#from waterkeep import waterStored
import waterStored
import os
import sys
import numpy as np
ROOT_DIR = os.path.abspath("./")
sys.path.append(ROOT_DIR)

if __name__ == '__main__':
    print("Test Case: 1")
    print("Input:\n[2.2.2]\n[2.2.2]\n[2.2.2] ")
    platform1=np.array([[2,2,2],[2,2,2],[2,2,2]])
    water1=waterStored.WaterStoredInPlatform(platform1)
    print("Answer: "+str(water1))
    print("\n")

    print("Test Case: 2")
    print("Input:\n[2.2.2.2]\n[2.1.2.1]\n[2.2.2.1]")
    platform2=np.array([[2,2,2,2],[2,1,2,1],[2,2,2,1]])
    water2=waterStored.WaterStoredInPlatform(platform2)
    print("Answer: "+str(water2))
    print("\n")

    print("Test Case: 3")
    print("Input:\n[3.3.3.3.3.3]\n[3.1.2.3.1.3]\n[3.1.2.3.1.3]\n[3.3.3.1.3.3]")
    platform3=np.array([[3,3,3,3,3,3],[3,1,2,3,1,3],[3,1,2,3,1,3],[3,3,3,1,3,3]])
    water3=waterStored.WaterStoredInPlatform(platform3)
    print("Answer: "+str(water3))
    print("\n")

    print("Test Case: 4")
    print("Input:\n[3.3.3.3.5.3]\n[3.0.2.3.1.3]\n[3.1.2.3.1.3]\n[3.3.3.1.3.3]")
    platform4=np.array([[3,3,3,3,5,3],[3,0,2,3,1,3],[3,1,2,3,1,3],[3,3,3,1,3,3]])
    water4=waterStored.WaterStoredInPlatform(platform4)
    print("Answer: "+str(water4))
    print("\n")

    print("Test Case: 5")
    print("Input:\n[5.5.5.5.5]\n[9.1.1.1.5]\n[5.1.5.1.5]\n[5.1.1.1.5]\n[5.5.5.5.5]")
    platform5=np.array([[5,5,5,5,5],[9,1,1,1,5],[5,1,5,1,5],[5,1,1,1,5],[5,5,5,5,5]])
    water5=waterStored.WaterStoredInPlatform(platform5)
    print("Answer: "+str(water5))
    print("\n")

    print("Test Case: 6")
    plt=np.array([[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]])
    water_plt=waterStored.WaterStoredInPlatform(plt)
    print("Answer: "+str(water_plt))
    print("\n")

    print("Test Case: 7")
    plt1=np.array([[3,3,3,3,5,3],[3,1,2,3,1,3],[3,0,2,3,1,3],[3,3,3,1,3,3]])
    water_plt1=waterStored.WaterStoredInPlatform(plt1)
    print("Answer: "+str(water_plt1))
    print("\n")

    print("Test Case: 8")
    plt2=np.array([[5,7,8,9,1,2],[2,1,3,0,1,2],[5,7,8,9,1,3],[7,2,1,4,2,1]])
    water_plt2=waterStored.WaterStoredInPlatform(plt2)
    print("Answer: "+str(water_plt2))
    print("\n")

    print("Test Case: 9")
    plt3=np.array([[5,7,8,9,5,2],[2,1,2,0,1,2],[5,1,2,1,1,3],[7,3,3,4,2,1]])
    water_plt3=waterStored.WaterStoredInPlatform(plt3)
    print("Answer: "+str(water_plt3))
    print("\n")