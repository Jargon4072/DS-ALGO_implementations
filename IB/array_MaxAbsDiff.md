``` c++
int Solution::maxArr(vector<int> &A) {         //not efficient approach.
    int maximum=0;
    for(int i=0;i<A.size()-1;i++){
        for(int j=1;j<A.size();j++){
            int val=A[i]>A[j]?(A[i]-A[j]+(i>j?(i-j):(j-i))):(A[j]-A[i]+(i>j?(i-j):(j-i)));
            maximum=max(val,maximum);
        }
    }
    return maximum;
}

```

I'll show how to solve a more general problem in linear time: give a list of points in 2D space (x[i], y[i]), find two farthest points (with respect to Manhattan distance).

1. Let's find the following points: max(x[i] + y[i]), max(-x[i] + y[i]), max(-y[i] + x[i]) and max(-x[i] - y[i]) among all i.

2. Let's compute the distance between every point in the list and the four points chosen during the previous step and pick the largest one. This algorithm clearly works in linear time as it considers  4 * N pairs of points. I claim that it's correct.

3. Why? Let's fix a point (x[k], y[k]) and try to find the farthest one from it. Consider an arbitrary point (x[i], y[i]). Let's expand the absolute value of differences between their coordinates. Let's assume that it's x[i] + x[k] + y[i] + y[k] = (x[k] + y[k]) + x[i] + y[i]. The first term is a constant. If x[i] + y[i] is not maximum among all i, (x[i], y[i]) cannot be the farthest. The three other cases (depending on the sign of x[i] and y[i] in the expansion) are handled in the same manner.

```c++
int Solution::maxArr(vector<int> &A) {
  int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN, max4=INT_MIN;
  int min1=INT_MAX,min2=INT_MAX,min3=INT_MAX,min4=INT_MAX;
  int ans;
  for(int i=0;i<A.size();i++){
    max1=max(max1,A[i]+i);
    max2=max(max2,A[i]-i);
    max3=max(max3,-A[i]+i);
    max4=max(max4,-A[i]-i);

    min1=min(min1,A[i]+i);
    min2=min(min2,A[i]-i);
    min3=min(min3,-A[i]+i);
    min4=min(min4,-A[i]-i);
  }
  ans=max(ans,max1-min1);
  ans=max(ans,max2-min2);
  ans=max(ans,max3-min3);
  ans=max(ans,max4-min4);

  return ans;
}

```
