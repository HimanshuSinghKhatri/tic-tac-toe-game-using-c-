#include<iostream>
#include<string>
#include<conio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

    string str1="";
    string str2="";
    string firstplayer;
    string secondplayer;
    char array[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char token='X';
    int row;
    int col;
    bool tie=false;
    int num=0;
 void upper(){
 	cout<<"\t\t\t"<<"`````````````````````````````````"<<endl;  
 	cout<<"\t\t\t"<<"`````````````````````````````````"<<endl;
 	cout<<"\t\t\t"<<"``                             ``"<<endl;
 	cout<<"\t\t\t"<<"``    ****TIC TAC TOE****      ``" <<endl;
	cout<<"\t\t\t"<<"``                             ``"<<endl;
	cout<<"\t\t\t"<<"`````````````````````````````````"<<endl;  
	cout<<"\t\t\t"<<"`````````````````````````````````"<<endl;                  
 }
void player(){
	
	 cout<<"\t\tPLAYER 1 NAME: \n";
    	     cin.ignore();
              getline(cin,str1);
             
              cout<<"\t\tPLAYER 2 NAME: \n";
              getline(cin,str2);
              int check=0;
              while(check==0){
			  
              cout<<"\t\tWHO PLAY FIRST: "<<str1<<"  "<<str2<<endl;
             
             getline(cin,firstplayer);
//                cin.ignore();
              if(firstplayer==str2){
	              check=1;
                  secondplayer=str1;
//                  firstplayer=str1;
                  
                   }
               else if(firstplayer==str1) {
                check=1;
					
//                firstplayer=str1;
                secondplayer=str2;
	             }
	             
	             else{
	             	  
			     	system("cls");
              	    cout<<"\t\tPLAYER NAME IN INCORRECT :" <<endl;
	             	continue; 
				 }
              
               
	         }
	              cout<<"\t\tFIRST PLAYER :"<<firstplayer<<endl;
                   cout<<"\t\tSECOND PLAYER:"<<secondplayer<<endl;
//	             cout<<secondplayer<<endl;
}
void layout(){
	cout<<endl;
	cout<<"\t\t\t"<<"*****PLAY****"<<endl;
	cout<<"\t\t\t"<<"-------------"<<endl;
	cout<<"\t\t\t"<<"-------------"<<endl;
	cout<<"\t\t\t"<<"|  |    |   |"<<endl;
	cout<<"\t\t\t"<<"|"<<array[0][0]<<" | " <<array[0][1]<<"  | "<<array[0][2]<<" | \n";
//    cout<<"|  |    |   |"<<endl; 
	cout<<"\t\t\t"<<"|__|____|___|"<<endl;
	cout<<"\t\t\t"<<"|  |    |   |"<<endl;
	cout<<"\t\t\t"<<"|"<<array[1][0]<<" | " <<array[1][1]<<"  | "<<array[1][2]<<" | \n";
	cout<<"\t\t\t"<<"|__|____|___|"<<endl;
	cout<<"\t\t\t"<<"|  |    |   |"<<endl;
	cout<<"\t\t\t"<<"|"<<array[2][0]<<" | " <<array[2][1]<<"  | "<<array[2][2]<<" | \n";
	cout<<"\t\t\t"<<"|  |    |   |"<<endl;
	cout<<"\t\t\t"<<"-------------"<<endl;
	cout<<"\t\t\t"<<"-------------"<<endl;

	cout<<endl;		
}
void play(){
	   int digit;
	   if(token=='X'){
	   	cout<<firstplayer<<": TURN";
	   	cin>>digit;
	   }
	    if(token=='O'){
	   	cout<<secondplayer<<": TURN"<<endl;
	   	cin>>digit;
	   }
	   
	   /////////////specifing area////////
	   if(digit==1){
	   	row=0;
	   	col=0;
	   	num++;
	   }
	    if(digit==2){
	   	row=0;
	   	col=1;
	   	num++;
	   }
	    if(digit==3){
	   	row=0;
	   	col=2;
	   	num++;
	   }
	    if(digit==4){
	   	row=1;
	   	col=0;
	   	num++;
	   }
	    if(digit==5){
	   	row=1;
	   	col=1;
	   }
	    if(digit==6){
	   	row=1;
	   	col=2;
	   	num++;
	   }
	    if(digit==7){
	   	row=2;
	   	col=0;
	   	num++;
	   }
	    if(digit==8){
	   	row=2;
	   	col=1;
	   	num++;
	   }
	    if(digit==9){
	   	row=2;
	   	col=2;
	   	num++;
	   }
	   else if(digit<1 || digit>9){
	   
	       cout<<"\t!!!! INVALID CHOICE !!!!"<<endl;
	       play();
	   }
	       
	if(token=='X' && array[row][col]!='X' && array[row][col]!='O'){
	                  	//unsed place
		array[row][col]='X';
		token='O';
	}
	else if(token=='O' && array[row][col]!='X' && array[row][col]!='O'){
	
	   array[row][col]='O';
	   token='X';
}
 
else{
	num--;
	cout<<"\tSPACE FILLED"<<endl;
	play();
}
 
layout();

}

bool winner(){
	int i;
	for(i=0;i<3;i++){
		if(array[i][0]==array[i][1] && array[i][0]==array[i][2] || array[0][i]==array[1][i] && array[0][i]==array[2][i]){
			 return true;
		}
		
	}
	if(array[0][0]==array[1][1] && array[1][1]==array[2][2] || array[0][2]==array[1][1] && array[2][0]){
	      return true;	
	}
	
	for(i=0;i<3;i++){
		int j;
		for(j=0;j<3;j++){
			if(array[i][j]!='X' && array[i][j]!='O')
			return false;
		}
	}
	
	 tie=true;
	 
	 return false;
}
void load(){
	int i;
	char ch= 219;
	cout<<"\n\t\t\t LoAdInG...";
	for(i=0;i<30;i++){
		cout<<ch;
			if(i<10)
				Sleep(220);
			if(i>=10)
				Sleep(150);
			if(i>=20)
				Sleep(80);
			}
}
int main(){
 
     system("color 35");
     upper();
     
      
    while(1){
    	
    	cout<<"\n\n\t\t\t"<<"..........START NEW GAME........."<<endl;
    	cout<<"\t\t\t\t[START](1)";
    	cout<<"\t [END](2)"<<endl;
    
    	char choice;
    	cin>>choice;
    	system("cls");
    	cout<<"......................................................................"<<endl;
    	if(choice!='1' && choice!='2'){
    		system("cls");
		}
	
    	switch(choice){
    		case '1':
    	    
	     	
    			cout<<"\n\t\t........GAME STARTED........"<<endl;
    			load();
	        	system("cls");
	        	
    			 player();
    	        cout<<endl;
    	        system("cls");
    			while(!winner()){
                   layout();
                   play();
                   winner();
               }
                   if(token=='X' && tie==false)
                        cout<<"\t\t***"<<secondplayer<<" WINS "<<"***"<<endl;
                   else if(token=='O' && tie==false)
                       cout<<"\t\t***"<<firstplayer<<" WINS "<<"***"<<endl;
                    else
                        cout<<"\t***MATCH TIE***"<<endl;
                    getch();
                    system("cls");
    			break;
    			
    	case '2':
    		
    		cout<<"BYE! see you next time..... "<<(char)1<<(char)1;
    			return 0;
    	default:
    			cout<<"\tCHOICE IS INCORRECT ENTER CORRECT ONE"<<endl;
    			break;
		}
		
	}
	return 0;
}
    
