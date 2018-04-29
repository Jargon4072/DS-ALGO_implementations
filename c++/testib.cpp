/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool check4overlap(Interval a, Interval b){
   if(max(a.start,b.start)>min(a.end,b.end))
      return false;
   return true;
 }
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=intervals.size();
    vector<Interval> sol;
    if(n==0){
      sol.push_back(newInterval);
      return sol;
    }
    if(newInterval.start>intervals[n-1].end ||newInterval.end<intervals[0].start){
      if(newInterval.end<intervals[0].start){
        sol.push_back(newInterval);
      }
      for(int i=0;i<n;i++){
        sol.push_back(intervals[i]);
      }
      if(newInterval.start>intervals[n-1].end){
        sol.push_back(newInterval);
      }
      return sol;
    }
    for(int i=0;i<n;i++){
      bool overlap=check4overlap(intervals[i],newInterval);
      if(!overlap){
        sol.push_back(intervals[i]);
        if(i<n-1 && newInterval.start>intervals[i].end && newInterval.end<intervals[i+1].start){
          sol.push_back(newInterval);
        }
        continue;
      }
      int st=i;
      while(i<n && overlap){
        i++;
        if(i==n) overlap=false;
        else{
          overlap=check4overlap(intervals[i],newInterval);
        }
      }
      i--;
      Interval fInterval(min(newInterval.start,intervals[st].start),max(newInterval.end,intervals[i].end));
      sol.push_back(fInterval);
    }
      return sol;
}
