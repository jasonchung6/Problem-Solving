import java.util.*;
class Solution {
    boolean solution(String s) { 
        
        Stack<Character> stack = new Stack<>();
        
        for(int i=0;i<s.length();i++){
            if(stack.empty()){
                if(s.charAt(i)==')') return false;
                else stack.push('(');
            } else{
                if(s.charAt(i)=='(') stack.push('(');
                else{
                    if(stack.peek()=='(') stack.pop();
                    else return false;
                }
            }
        }
        if(!stack.empty()) return false;
        return true;
    }
}