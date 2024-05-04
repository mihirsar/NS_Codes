#include<bits/stdc++.h>
using namespace std;

int main(){
    string username, storedPass = "secure123", inPass;
    bool logindone = false;
    cout<<"Enter username: "; cin>>username;

   for(int i=0; i<3 && !logindone; ++i){
	cout<<"Enter password: "; cin>>inPass;
	if(inPass==storedPass){
		logindone=true;
		cout<<"Access Granted, Welcome "<<username<<"!!\n";
    } else{
        cout<<"Access denied, Try Again...\n";
    }
   }
   if(!logindone){
        cout<<"Too many attempts, account locked\n";
   }
   return 0;
}
