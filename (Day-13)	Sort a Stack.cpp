//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&leftPanelTab=1

void stackInsert(stack<int> &stack, int curr){
    if(stack.empty()){
        stack.push(curr) ;
        return ;
    }
    int top = stack.top() ;
    
    if(top <= curr){
        stack.push(curr) ;
        return ;
    }
    
    stack.pop();
    stackInsert(stack,curr) ;
    stack.push(top) ;
}

void sortStack(stack<int> &stack)
{
    if(stack.empty()) return;
    
    int top = stack.top();
    stack.pop();
    sortStack(stack) ;
    stackInsert(stack,top) ;

}
