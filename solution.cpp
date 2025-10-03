
#include <iostream>
#include <string>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity)
{
    if(size == capacity)
    {
        throw std::string("List full");
    }
    else
    {
        names[size] = new char[std::strlen(name)+1];
        std::strcpy(names[size], name);
        gpas[size] = gpa;
        size++;
    }
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa)
{
    *gpaPtr = newGpa;
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa)
{
    std::cout << name << std::endl;
    std::cout << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size)
{
    if(size == 0)
    {
        throw(std::string("No students"));
    }
    double sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += gpas[i];
    }
    return sum / size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        try
        {
            switch (choice) {
                case 1: {
                    // TODO: implement menu logic
                    std::string temp;
                    double gpa;
                    std::cin >> temp >> gpa;
                    char* name = new char[temp.size()+1];
                    std::strcpy(name, temp.c_str());
                    addStudent(name, gpa, names, gpas, size, capacity);
                    break;
                }
                case 2: {
                    // TODO: implement menu logic
                    int idx;
                    double gpa;
                    std::cin >> idx >> gpa;
                    if (idx < 0 || idx >= size) 
                    {
                        throw std::string("Bad index");
                    }
                    updateGPA(&gpas[idx], gpa);
                    break;
                }
                case 3: {
                    // TODO: implement menu logic
                    for(int i = 0; i < size; i++)
                    {
                        printStudent(names[i], gpas[i]);
                    }
                    break;
                }
                case 4: {
                    // TODO: implement menu logic
                    if(size == 0)
                    {
                        throw std::string("No students");
                    }
                    else
                    {
                        std::cout << "Average GPA" << std::endl;
                        std::cout << averageGPA(gpas, size) << std::endl;
                    }
                    break;
                }
                case 5: {
                    std::cout << "Goodbye!" << std::endl;
                    break;
                }
                default: {
                    std::cout << "Invalid choice" << std::endl;
                }
            }
        }
        catch(const std::string& msg)
        {
            std::cout << msg << std::endl;
        }
    } while (choice != 5);

    // TODO: free memory
    for(int i = 0; i < size; i++)
    {
        delete[] names[i];
    }
    return 0;
}
