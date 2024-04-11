#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
/*typedef struct node node;
struct node {
    char value;
    struct node *prox;
};*/

char proximo_char(){
    char c = std::cin.get();
    return c;
}

int isnode(char c){
    if( c == 46){
        return 1;
    }else{return 0;}
}

typedef struct par par;
struct par{
    int i;
    int j;
};

queue<par> adjacentes(par p,int i,int j){
    queue<par> fila;
    par q;
    if(p.i<i){
        q.i=p.i+1;
        q.j=p.j;
        fila.push(q);
    }
        if(p.j<j){
        q.j=p.j+1;
        q.i=p.i;
        fila.push(q);
    }
        if(p.i>0){
        q.j=p.j;
        q.i=p.i-1;
        fila.push(q);
    }
        if(p.j>0){
        q.j=p.j-1;
        q.i=p.i;
        fila.push(q);
    }
    return fila;
}
int main(){
    
    int i,j,a,b;
    cin >> a >> b;
    //cout << "A:" << a <<" B:" <<b << "\n";

    char** matrix = new char*[a];
    for ( i = 0; i < a ;++i){
        matrix[i] = new char[b];
    }

    int** visited = new int*[a];
    for ( i = 0; i < a; ++i){
        visited[i] = new int[b]();
    }

    proximo_char();
    char lookahead=proximo_char();

    i=0;
    j=0;

    do{
        
       // cout << lookahead;
        if(lookahead != 10){
        matrix[i][j] = lookahead;
        j++;}else{
            i++;
            j = 0;
        }
        lookahead = proximo_char();
    }while(lookahead != EOF); //-1 ==EOF

//busca em largura:
queue<par> fila;
queue<par> adj;
par p;
par u;
par v;
int count =0;
// busca em largura
for(i=0;i<=(a-1);i++){
    for(j=0;j<=(b-1);j++){
        if(visited[i][j]==0 and isnode(matrix[i][j])){
            p.i=i;
            p.j=j;
            fila.push(p);
            //cout<<"MÃE:"<<p.i<<p.j<<"\n";
            visited[i][j]=1;
            count++;
            //cout<<"COUNT"<<count<<"\n";
            while(!fila.empty()){
                u=fila.front(); fila.pop();
               // cout<<"U:"<<u.i<<u.j<<" ";
                adj=(adjacentes(u,(a-1),(b-1)));
                //cout<<"ADJACÊNCIAS: ";
                while(!adj.empty()){
                    v=adj.front(); adj.pop();
                    if(visited[v.i][v.j]==0 and isnode(matrix[v.i][v.j])){
                       // cout<<v.i<<v.j<<" ";
                        visited[v.i][v.j]=1;
                        fila.push(v);
                    }
                }//cout<<"\n";
            }
        }
    }
}
    cout<<count<<"\n";
    return 0;
}