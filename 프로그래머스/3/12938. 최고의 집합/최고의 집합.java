class Solution {
    public int[] solution(int n, int s) {
        int[] answer = {};
        
        if(n>s) {
            answer= new int[1];
            answer[0]=-1;
            return answer;
        }
        
        answer= new int[n];
        if(s%n==0){
            int temp=s/n;
            for(int i=0;i<n;i++){
                answer[i]=temp;
            }
        }else {
            int temp=s/n;
            int mod=s%n;
            for(int i=0;i<(n-mod);i++){
                answer[i]=temp;
            }
            for(int i=n-mod;i<n;i++){
                answer[i]=temp+1;
            }
        }
        return answer;
    }
}