// Naive search
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "this is a text";
    string pattern = "is";
    int m = text.length();
    int n = pattern.length();
    for(int i=0;i<m-n+1;i++){
        int c=0;
            for(int j=0;j<n;j++){
                if(text[i+j]!=pattern[j]){
                    break;
                }
                else{
                    c++;
                    if(c==n){
                        cout<<"found at "<<i;
                        cout<<"\n";
                    }
                }
            }
        }
       
   

    return 0;
}
