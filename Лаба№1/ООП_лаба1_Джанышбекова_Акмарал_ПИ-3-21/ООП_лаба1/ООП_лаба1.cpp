// Задача #1


//#include <iostream>
//using namespace std;
//
//double Power(double n, int p = 2);
//int main()
//{
//    double n;
//    int p, answer;
//    cout << "Input N:\n";
//    cin >> n;
//    cout << "Will you input the power? (0-No; 1-Yes)\n";
//    cin >> answer;
//    if (answer) {
//        cout << "Input number >=2 : \n";
//        cin >> p;
//    }
//    else p = 2;
//    double result = Power(n, p);
//    cout << "Result : " << result;
//    return 0;
//}
//
//double Power(double n, int p = 2) {
//    double result = 1;
//    for (int i = 0; i < p; i++) {
//        result = result * n;
//    }
//    return result;
//}



// Задача #2


//#include <iostream>
//using namespace std;
//
//double Power(double n, int p = 2) {
//    double result = 1;
//    for (int i = 0; i < p; i++) {
//        result = result * n;
//    }
//    return result;
//}
//
//short int Power(short int n, int p = 2) {
//    short int result = 1;
//    for (int i = 0; i < p; i++) {
//        result = result * n;
//    }
//    return result;
//}
//
//long int Power(long int n, int p = 2) {
//    long int result = 1;
//    for (int i = 0; i < p; i++) {
//        result = result * n;
//    }
//    return result;
//}
//
//float Power(float n, int p = 2) {
//    float result = 1;
//    for (int i = 0; i < p; i++) {
//        result = result * n;
//    }
//    return result;
//}
//
//double Power(char n, int p = 2) {
//    double result = 1;
//    static_cast<double>(n);
//    for (int i = 0; i < p; i++) {
//        result = result * n;
//    }
//    return result;
//}
//
//int main() {
//    double n;
//    int p, answer;
//    char c;
//    short int s;
//    long int l;
//    float f;
//    cout << "Input double:\n";
//    cin >> n;
//    cout << "Input char:\n";
//    cin >> c;
//    cout << "Input short:\n";
//    cin >> s;
//    cout << "Input long:\n";
//    cin >> l;
//    cout << "Input float:\n";
//    cin >> f;
//
//    cout << "Will you input the power? (0-No; 1-Yes)\n";
//    cin >> answer;
//    if (answer) {
//        cout << "Input number >= 2 : \n";
//        cin >> p;
//    }
//    else {
//        p = 2;
//    }
//
//    double result = Power(n, p);
//    cout << "Result for double : " << result << endl;
//    cout << "Result for char: " << Power(c, p) << endl;
//    cout << "Result for short int: " << Power(s, p) << endl;
//    cout << "Result for long int: " << Power(l, p) << endl;
//    cout << "Result for float: " << Power(f, p) << endl;
//
//    return 0;
//}
//


// Задача #3


#include <iostream>
#include <string>

using namespace std;

struct Employee {
    string lastName;
    int age;
    string specialty;
    double averageSalary;
};

int main() {
    const int N = 2; 
    Employee employees[N][100];
    int numMechanics = 0;
    int numTurners = 0;
    int numMechanic = 0;
    int numTurner = 0;
    for (int i = 0; i < N; i++) {
        int numEmployees;
        cout << "Input number of employees for the factory " << i + 1 << ": ";
        cin >> numEmployees;
        int numMechanics = 0;
        int numTurners = 0;
        for (int j = 0; j < numEmployees; j++) {
            cout << "Input the informatio about employee " << j + 1 << " on the factory " << i + 1 << ":\n";
            cout << "Last name: ";
            cin >> employees[i][j].lastName;
            cout << "Age: ";
            cin >> employees[i][j].age;
            cout << "Specialty: ";
            cin >> employees[i][j].specialty;
            cout << "Average salary: ";
            cin >> employees[i][j].averageSalary;

            if (employees[i][j].specialty == "mechanic") {
                numMechanics++;
            }
            else if (employees[i][j].specialty == "turner") {
                numTurners++;
            }
        }
        cout << "Factory " << i + 1 << " - Number of mechanics: " << numMechanics << ", Number of turners: " << numTurners << endl;
       
    }
   
    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 100; j++) {
            
            if (employees[i][j].specialty == "mechanic") {
                numMechanic++;
            }
            else if (employees[i][j].specialty == "turner") {
                numTurner++;
            }
        }
       
        
       
    }
    
    cout << "Number of mechanics: " << numMechanic << endl;
    cout << "Number of turnes: " << numTurner << endl;

    return 0;
}
