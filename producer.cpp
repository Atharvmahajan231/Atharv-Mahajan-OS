#include<iostream>
using namespace std;

int S=1,full=0,empty=10,i=0;
void producer();
void consumer();
int wait(int);
int signal(int);

int main(){
    int n;
    cout<<"\n1.Producer \n2.Consumer \n3.exit";
    while(1){
        cout<<"\n Enter your choice";
        cin>>n;
        
        switch(n){
            case 1:
            if(S==1 && full!=10)
            producer();
            else
            cout<<"Buffer is full";
            break;
            case 2:
            if(S==1 && empty !=0)
            consumer();
            else
            cout<<"Buffer is empty";
            break;
            case 3:
            exit(0);
            break;
        }
    }
}
int wait(int S){
    return(--S);
}

int signal(int S){
    return(++S);
}

void producer(){
    S=wait(S);
    full=signal(full);
    empty=wait(empty);
    i++;
    cout<<"\n Producer produces item x";
    S=signal(S);
}

void consumer(){
    S=wait(S);
    full=wait(full);
    empty=signal(empty);
    cout<<"\n Consumer consumes item x";
    i--;
    S=signal(S);
}