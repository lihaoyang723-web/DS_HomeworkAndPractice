#include "Student.h"
#include <string>
#include <sstream>
#include "Class.h"

std::string Student::toString() const
{
     //TODO: uncomment the following code after implementing class Student.
    
    std::ostringstream oss;
    oss << "Student Information:"
        << "\n\tid: " << id
        << "\n\tname: " << name
        << "\n\tenrollment year: " << year
        << "\n\tdegree: " << (degree == graduate ? "graduate" : "undergraduate")
        << std::endl;
    return oss.str();
    
    return "";
}

// TODO: implement functions which are declared in Student.h.
double Undergraduate::getGpa() const {
    double totalPoints = 0;
    double weightedGpaSum = 0;
    for (Class* c : classes) {
        try {
            double s = c->getStudentWrapper(id).getScore();
            if (s >= 0) {
                double gpa = s / 20.0;
                weightedGpaSum += gpa * c->point;
                totalPoints += c->point;
            }
        } catch (...) {}
    }
    if (totalPoints == 0) return 0.0;
    return weightedGpaSum / totalPoints;
}

double Undergraduate::getAvgScore() const {
    double totalPoints = 0;
    double weightedSum = 0;
    for (Class* c : classes) {
        try {
            double s = c->getStudentWrapper(id).getScore();
            if (s >= 0) {
                weightedSum += s * c->point;
                totalPoints += c->point;
            }
        } catch (...) {}
    }
    if (totalPoints == 0) return 0.0;
    return weightedSum / totalPoints;
}

double Graduate::getGpa() const {
    double totalPoints = 0;
    double weightedGpaSum = 0;
    for (Class* c : classes) {
        try {
            double s = c->getStudentWrapper(id).getScore();
            if (s >= 0) {
                double gpa = 0.0;
                if (s >= 90 && s <= 100) gpa = 4.0;
                else if (s >= 80 && s < 90) gpa = 3.5;
                else if (s >= 70 && s < 80) gpa = 3.0;
                else if (s >= 60 && s < 70) gpa = 2.5;
                else gpa = 2.0;
                
                weightedGpaSum += gpa * c->point;
                totalPoints += c->point;
            }
        } catch (...) {}
    }
    if (totalPoints == 0) return 0.0;
    return weightedGpaSum / totalPoints;
}

double Graduate::getAvgScore() const {
    double totalPoints = 0;
    double weightedSum = 0;
    for (Class* c : classes) {
        try {
            double s = c->getStudentWrapper(id).getScore();
            if (s >= 0) {
                weightedSum += s * c->point;
                totalPoints += c->point;
            }
        } catch (...) {}
    }
    if (totalPoints == 0) return 0.0;
    return weightedSum / totalPoints;
}