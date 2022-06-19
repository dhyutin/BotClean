#include<iostream>
#include<vector>
#include <queue>

using namespace std;

// searches and checks if the coordinates are previously visited or not
bool search_(vector<vector<int>> check, vector<int> coords){
    
    int len = check.size();
    //cout<<len<<endl;
    for(int i = 0; i < len; i++){
        if(check[i] == coords){
            return false;
        }
    }
    //cout<<coords[0]<<", "<<coords[1]<<" is NOT present\n";
    return true;
}

vector<int> bfs(vector<string> board, int r, int c){
    
    queue<vector<int>> q;
    vector<vector<int>> check_arr;
    vector<int> initial, mt;
    initial.push_back(r);
    initial.push_back(c);
    
    int n = board.size();
    int m = board[0].length();
    
    mt.push_back(-1);
    mt.push_back(-1);    
    
    q.push(initial);
    check_arr.push_back(initial);
    

    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    vector<int> last;
    vector<int> neighbour1, neighbour3;
    vector<int> neighbour2, neighbour4;    
    while(1){
        
        if(q.empty()){
            return mt;
        }
        
        last = q.front();
        q.pop();
        
        if(board[last[0]][last[1]] == 'd'){
            return last;
        }
        
        if(search_(check_arr, last)){
            check_arr.push_back(last);
        }
   
        
        // Neighbours
        n1 = 0; n2 = 0; n3 = 0; n4 = 0;
        
        neighbour1.push_back(last[0]);
        neighbour1.push_back(last[1]+1);
        
        
        if(last[1]+1 < m){
            n1 = 1;
            // cout<<"n1 is nrighbour\n";
        }
        
        //cout<<board[neighbour1[0]][neighbour1[1]]<<endl;
        if(n1 == 1 && board[neighbour1[0]][neighbour1[1]] == 'd' && search_(check_arr, neighbour1)){
            return neighbour1;
        }
        
        neighbour2.push_back(last[0]+1);
        neighbour2.push_back(last[1]);
        
        if(last[0]+1 < n){
            n2 = 1;
            // cout<<"n2 is nrighbour\n";
        }
        
        //cout<<board[neighbour2[0]][neighbour2[1]]<<endl;
        if(n2 == 1 && board[neighbour2[0]][neighbour2[1]] == 'd' && search_(check_arr, neighbour2)){
            return neighbour2;
        }
        
        neighbour3.push_back(last[0]);
        neighbour3.push_back(last[1]-1);
        
        if(last[1]-1 >= 0){
            n3 = 1;
            // cout<<"n3 is nrighbour\n";
        }
        
        // cout<<board[neighbour3[0]][neighbour3[1]]<<endl;       
        if(n3 == 1 && board[neighbour3[0]][neighbour3[1]] == 'd' && search_(check_arr, neighbour3)){
            return neighbour3;
        }
        
        neighbour4.push_back(last[0]-1);
        neighbour4.push_back(last[1]);
        
        if(last[0]-1 >= 0){
            n4 = 1;
            // cout<<"n4 is nrighbour\n";
        }
        // cout<<board[neighbour4[0]][neighbour4[1]]<<endl;  
        if(n4 == 1 && board[neighbour4[0]][neighbour4[1]] == 'd' && search_(check_arr, neighbour4)){
            return neighbour4;
        }
        
        if(n1 == 1 && search_(check_arr, neighbour1)){
            // cout<<"N1\n";
            check_arr.push_back(neighbour1);
            q.push(neighbour1);

        }
        
        if(n2 == 1 && search_(check_arr, neighbour2)){
            check_arr.push_back(neighbour2);
            q.push(neighbour2);
            // cout<<"N2\n";
        }
        if(n3 == 1 && search_(check_arr, neighbour3)){
            check_arr.push_back(neighbour3);
            q.push(neighbour3);
            // cout<<"N3\n";
        }
        if(n4 == 1 && search_(check_arr, neighbour4)){
            check_arr.push_back(neighbour4);
            q.push(neighbour4);
            // cout<<"N4\n";
        }
        
        neighbour1.clear();
        neighbour2.clear();
        neighbour3.clear();
        neighbour4.clear();
        last.clear();
    }
    
    return mt;
}

void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
    //add logic here
    // Use BFS to determine the closest dirty position
    vector<int> next_pos = bfs(board, posr, posc);
    
    // Move towards it
    if(next_pos[0] - posr > 0){
        cout<<"DOWN\n";
        return;
    }
    else{
        if(next_pos[0] != posr){
            cout<<"UP\n";
            return;
        }
    }
    
    if(next_pos[1] - posc > 0){
        cout<<"RIGHT\n";
        return;
    }
    else{
        if(next_pos[1] != posc){
            cout<<"LEFT\n";
            return;
        }
    }
    
    if(next_pos[0] == posr && next_pos[1] == posc){
        cout<<"CLEAN\n";
        return;
    }
}

int main(void) {
    int pos[2];
    int dim[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}
