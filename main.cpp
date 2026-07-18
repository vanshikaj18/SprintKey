#include <iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"paras.h"
using namespace std;
 
int randomindex(){
    srand(time(0));
    return rand()%5;
}

void test(){
    cout<<endl<<"Choose Difficulty level; "<<endl<<"1. Easy"<<endl<<"2. Medium"<<endl<<"3. Hard"<<endl;
    int x;
    cout<<endl<<"Enter level number: ";
    cin>>x;
    cin.ignore();
   
    if(x==1){
        int index = randomindex() % 5;
        cout<<endl<<easy[index];
        
    }
    else if(x==2){
        int index = randomindex() % 5;
        cout<<endl<<medium[index];
    }
    else if(x==3){
        int index = randomindex() % 5;
        cout<<endl<<hard[index];
    }
    else{
        cout<<"Invalid";
    }
    string s;
    cout<<endl<<"Start Typing!"<<endl;
    time_t start = time(nullptr);

    getline(cin,s);
    string inputpara = s;

    time_t end = time(nullptr);
    double diff = difftime(end,start);

    double minutes = diff/60;
    double words = ( inputpara.length() / 5.0);
    double wpm = words/minutes;


    cout<<endl<<"RESULT: "<<endl;
    cout<<"WPM: "<<wpm<<endl;
    cout<<"Time Taken: "<<diff<<endl;
}

int exit(){
    cout<<"Session Ends";
    return 0;
}

int help(){
    cout<<endl<<">What is SprintKey?\n*It is a terminal based typing speed tester."<<endl;
    cout<<endl<<">How it works?\n*Start the Test in the main menu.\nChoose the difficulty level - Easy/Medium/Hard.\nType the paragraph shown above in your speed.\nBy pressing Enter, typing ends and your result will be shown."<<endl;
    cout<<endl<<">What is WPM?\n*Words Per Minute is the standard measure of typing speed."<<endl;
    cout<<"Exit (Press 1)"<<endl;
    int x;
    cin>>x;
    if(x==1)exit();
}

void menu(){
    cout<<"_______________________________________"<<endl;
    cout<<endl<<"              SprintKey               "<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"Main Menu"<<endl;
    cout<<endl<<"1. Start Test\n2. Help\n3. Exit"<<endl;
    
    int choice;
    cout<<endl<<"Enter choice: ";
    cin>>choice;
    if(choice==1){
        test();
    }
    else if(choice==2){
        help();
    }
    else if(choice==3){
        exit();
    }
    else{
        cout<<"Invalid! Enter again"<<endl;
        menu();
        }
    
    
}

int main() {
    menu();
    return 0;
}
