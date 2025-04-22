#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <map>
#include "student.h"

class StudentManager {
private:
    std::map<int, Student> students;

public:
    void addStudent(const Student& student);
    void removeStudent(int id);
    void addGrade(int id, double grade);
    void displayStudent(int id) const;
    void displayAllStudents() const;
    double getOverallAverage() const;
};

#endif // STUDENT_MANAGER_H 