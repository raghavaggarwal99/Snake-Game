/* 
You are given an array A of N integers. Now, two functions  and  are defined:

 : This is the smallest number Z such that  and 

 : This is the smallest number Z such that  and 

Now, you need to find for each index i of this array , where  . If such a number does not exist, for a particular index i, output 1 as its answer. If such a number does exist, output 



*/


#include<bits/stdc++.h>
using namespace std;

vector<long long> solution (vector<long long> A) {
   // Write your code here
  long s = A.size() ;
   
   vector<long long> F ;
   
   for(long i = 0 ; i < s ; i++){
       long j = i+1 ;
       while(j != s){
           if(A[j] > A[i]){
               break ;
           }
           j++ ;
       }
       if(j != s){
           F.push_back(j) ;
       }
       else{
           F.push_back(-1) ;
       }
   }
   
   vector<long long> G ;
   
  for(long i = 0 ; i < s ; i++){
      
      if(F[i] == -1){
          G.push_back(-1) ;
          continue ;
      }
      
      long j = F[i]+1 ;
      while(j != s){
          if(A[j] < A[F[i]]){
              break ;
          }
          j++ ;
      }
      
      if(j != s){
          G.push_back(j) ;
      }
      else{
          G.push_back(-1) ;
      }
  }
  
  vector<long long> ans ;
  
  for(long i = 0 ; i < s ; i++){
      if(G[i] == -1){
          ans.push_back(-1) ;
          continue ;
      }
      ans.push_back(A[G[i]]) ;
  }
  
  return ans ;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }

    vector<long long> out_;
    out_ = solution(A);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}
