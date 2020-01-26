# @Author: Dwivedi Chandan
# @Date:   2019-05-15T23:01:36+05:30
# @Email:  chandandwivedi795@gmail.com
# @Last modified by:   Dwivedi Chandan
# @Last modified time: 2019-05-15T23:29:37+05:30



strs=["flower","flow","flight"]             # TODO: implement it with dp
strs.sort(key=len)
maxstr = ''
x=0
for i in range(len(strs[0])):
    mystr = strs[0][:i+1]
    print("mystr: "+str(mystr))
    print("strs[1:]: "+str(strs[1:]))
    for word in strs[1:]:
        if word[:i+1] != mystr:
            print("word: "+str(word))
            x=1
        	#print(maxstr)
        	#continue
    if x==0:
    	maxstr = mystr
print(maxstr) # your code goes here