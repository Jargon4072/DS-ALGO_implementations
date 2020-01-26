# @Author: Dwivedi Chandan
# @Date:   2019-04-25T07:28:47+05:30
# @Email:  chandandwivedi795@gmail.com
# @Last modified by:   Dwivedi Chandan
# @Last modified time: 2019-04-25T08:02:03+05:30



n=int(input())
str=input()
a=""
while (len(str)>0):
    m = int(len(str)/2)
    print("m: ")
    print(m)
    print(str)
    if(len(str)%2==0):
        a+=str[m-1]
        print(a)
        str=str[:m-1]+str[m:]
    else:
        a+=str[m]
        print(a)
        str=str[:m]+str[m+1:]

print(a)