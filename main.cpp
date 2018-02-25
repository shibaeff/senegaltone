/*
 * This code embraces a ground-breaking approach to the senegalton pattern mechanism
 * Intelligent macro makes sourcecode more intuitive
 * For each class only one instance can be created
 * SINGLETON macro otta be called in the global scope
 * Access to the instance of each class is implemented via function call
 * with highly intuitive name pattern Senegalton_URKLASSENNAME
 *
 * This code is distributed under MIT License and was developed
 * in the mutual collaboration of MIPT and Senegal United Konglomerate of Applied Sciences (SUKAS)
 *
 * 2018, Moscow -- Bushmenwill
 */

#define SINGLETON(TYPE, INSTANCE_NAME, INITIALIZER) \
  TYPE* Senegalton_##TYPE() {                        \
    static TYPE INSTANCE_NAME = INITIALIZER;        \
    return &INSTANCE_NAME;                          \
  }


#include <iostream>
using namespace std;

// example classes
class Pupil {
public:
    Pupil(int _age, int _height) : age(_age), height(_height) {}
    ~Pupil() {}
    int age;
    int height;
};

class Teacher {
public:
    int grade;
    int age;
    Teacher(int _grade, int _age) : grade(_grade), age(_age) {}
    ~Teacher() {}
};

// actual definition

SINGLETON(Teacher, TeacherInst, Teacher(3, 65));
SINGLETON(Pupil, PupilInst, Pupil(56, 190));

int main() {
    // printf("%v\n", *(Senegalton_Pupil()));

    cout << Senegalton_Pupil()->age << "\n";
    cout << Senegalton_Teacher()->grade;
    return 0;
}
