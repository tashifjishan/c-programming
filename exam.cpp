#include<iostream>
using namespace std;

string questions[10] = {
        "1. What is the correct file extension for a C++ program?",
        "2. Which symbol is used to end a statement in C++?",
        "3. Which header file is needed to use cout and cin?",
        "4. Which keyword is used to define a constant in C++?",
        "5. What is the correct way to print \"Hello World\" in C++?",
        "6. Which of the following is a valid C++ comment?",
        "7. Which function is the starting point of every C++ program?",
        "8. Which data type is used to store whole numbers?",
        "9. Which operator is used for addition in C++?",
        "10. Which keyword is used to take input from the user?"
};


 string options[10][4] = {
        {".c", ".cpp", ".java", ".py"},
        {":", ".", ";", ","},
        {"<stdio.h>", "<iostream>", "<conio.h>", "<stdlib.h>"},
        {"var", "constant", "const", "define"},
        {"print(\"Hello World\");", "cout << \"Hello World\";", "printf(\"Hello World\")", "System.out.println(\"Hello World\");"},
        {"<!-- comment -->", "** comment **", "// comment", "## comment"},
        {"start()", "main()", "program()", "begin()"},
        {"float", "char", "double", "int"},
        {"*", "/", "+", "%"},
        {"input", "read", "cin", "scanf"}
};

void printQuestions(){
    cout<<"============================================"<<endl;
    for(int i=0; i<10; i++){
        cout<<questions[i]<<endl;
        for(int j=0; j<4; j++){
            cout<<(char)(97+j)<<". "<<options[i][j]<<endl;
        }
        cout<<"\n";

    }

    cout<<"============================================"<<endl;
}

void takeExam(){}
void viewResult(){}


int completedList[100];

class Student{
    public:
        int correct[10];
        int reg;
        Student(int reg):reg(reg){}
};

int main(){
    while(1){
        cout<<"1. Take exam"<<endl;
        cout<<"2. View Result"<<endl;
        cout<<"3. View Question Paper"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Choose: ";
        int choice;
        cin>>choice;

        if(choice==1){
            takeExam();
        }else if(choice ==2){
            viewResult();
        }else if(choice == 3){
            printQuestions();
        }else{
            cout<<"Bye Bye!";
            break;
        }
    }
    return 0;
}


/*

1. Take Exam
2. View Result

Choose: 1

1. Which of the following is the correct representation of 2 in binary:

a. 10   b. 20
c. 02   d. 01

Choose: a

#### if chosen correctly increment the correct count in the student's object else do it for the incorrect property

Result should be formatted!
hence also store the question which was answered correctly and the question which was answered incorrectly

also give the option to view entire question paper for verification by adding a correctly answered or incorrectly answered emoji near it


*/