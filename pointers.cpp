// compile: g++ -std=c++14 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include <iomanip>


typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    // Student ID
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);

    // Student first name
    std::string f_name;
    std::cout << "Please enter the student's first name: ";
    std::cin >> f_name;
    student.f_name = new char[f_name.length() + 1]; // Making space for null terminator 
    std::strcpy(student.f_name, f_name.c_str()); // Converting string to char

    // Student last name
    std::string l_name;
    std::cout << "Please enter the student's last name: ";
    std::cin >> l_name;
    student.l_name = new char[l_name.length() + 1]; // Making space for null terminator 
    std::strcpy(student.l_name, l_name.c_str()); // Converting string to char

    // How many assignments 
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 9999);

    //Memory for grades
    student.grades = new double[student.n_assignments];
    for(int i = 0; i < student.n_assignments; i++){
        std:: string assig_message = "Please enter the grade for assignment "; // Assign mesage 
        std:: string x = std::to_string(i); // Convert int to string in order to concat

        student.grades[i] = promptDouble(assig_message + x + ": ", 0, 999); // Add the strings together and call promptDouble

    }

    calculateStudentAverage(&student, &average);
    std:: cout << "\nStudent: " << student.f_name << " " << student.l_name << " "<< "[" << student.id << "]" << std::endl; std:: cout << " Average grade: " << std::fixed<< std::setprecision(1) << average << std::endl;
    // " Average grade: " << std::fixed<< std::setprecision(1)
    //Rounds average grade
    

    delete[] student.f_name;
    delete[] student.l_name;
    delete[] student.grades;
    // Output `average`

    return 0;
}   
    


/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    int input;
    std::cout << message; // Output message

    while(!(std::cin >> input) || input < min || input > max){
        std::cout << "Sorry, I cannot understand your answer" << std::endl;// Output message
        
        if(std::cin.fail()){ // If input fail
            std::cin.clear(); // Clear error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
        }
        std::cout << message;
    }
    return input;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    double input;
    std::cout << message; // Output message

    while(!(std::cin >> input) || input < min || input > max){
        std::cout << "Sorry, I cannot understand your answer" << std::endl;// Output message
        
        if(std::cin.fail()){ // If input fail
            std::cin.clear(); // Clear error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
        }
        std::cout << message;
    }
    return input;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    Student *student = (Student*)object; //Convert generic pointer to Student 
    double sum = 0; // Initialize sum 

    for(int i = 0; i < student->n_assignments; i++){ //Loop through grades
        sum += student->grades[i]; // Add grades to sum
    }
    *avg = sum/ student->n_assignments; // Calculate average, store in pointer
}