//
//  main.cpp
//  Recitation1
//
//  Created by Augustus Crosby on 5/20/19.
//  Copyright © 2019 Augustus Crosby. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//forward declaration
void executeAction(char c);
void addStudent(string name, double gpa);
void displayList();
void countNumberOfStudents();

struct studentNode {
    string name;
    double gpa;
    studentNode* next = NULL;
};
int numberOfStudents = 0;

studentNode* head = NULL;
studentNode* tail = NULL;       // global pointers

int main() {
    char c = 'i';                // initialized to a dummy value
    
    do {
        cout << "Choose an action:\n";
        cout << "\t a: Add student record\n";
        cout << "\t d: Display student records\n";
        cout << "\t c: Count the number of student records\n";
        cout << "\t q: Quit\n";
        cin >> c;
        cin.ignore();
        
        executeAction(c);
    } while (c != 'q');
}

void executeAction(char c) {
    string name_input;
    double gpa_input;
    
    switch (c) {
        case 'a':    // add student
            // input student details from user
            cout << endl << "Enter student's name: ";
            getline(cin, name_input);
            cout << "Enter gpa: ";
            cin >> gpa_input;
            cin.ignore();
            addStudent(name_input,gpa_input);
            break;
            
        case 'd':        // display the list
            displayList();
            break;
            
        case 'c':        // count number of students
            countNumberOfStudents();
            cout << endl << "Number of students: ";
            cout << numberOfStudents << endl <<endl;
            break;
            
        case 'q':        // quit
            break;
            
        default: cout << c << " is invalid input!\n";
    }
}

void addStudent(string name, double gpa) {
    studentNode* newStudent = new studentNode;
    
    newStudent->name = name;
    newStudent->gpa = gpa;
    
    if (head == NULL){
        head = newStudent;
        tail = newStudent;
    } else {
        tail->next = newStudent;
        tail = newStudent;
    }
}

void displayList(){
    studentNode* tempList = head;       //parse with temp pointer
    
    if(head == NULL){
        cout << "There is no list to display!\n";
    } else {
        cout << "Students:\n";
        
        while (tempList != NULL){
            cout << "Name: " << tempList->name;
            cout << "\nGPA: " << tempList->gpa << endl << endl;
            
            tempList = tempList->next;
        }
    }
}


void countNumberOfStudents(){
    studentNode* tempList = head;       //parse with temp pointer
    
    if(head == NULL){
        numberOfStudents = 0;
    } else {
        while (tempList != NULL){
            numberOfStudents++;
            tempList = tempList->next;
        }
    }
}











