#include "Class.h"
#include <string>
#include <vector>
#include "Student.h"
#include <sstream>
#include <fstream>
std::string Class::toString() const {
    std::ostringstream oss;
    oss << "Class Information:"
        << "\n\tname: " << name
        << "\n\tpoint: " << point
        << std::endl;
    return oss.str();
}

void Class::addStudent(const Student& st) {
    StudentWrapper sw(st.id, st);
    students.push_back(sw);
}

StudentWrapper& Class::getStudentWrapper(const std::string& studentId) {
    for (std::vector<StudentWrapper>::iterator it = students.begin();
            it != students.end();
            ++ it) {
        if (it->id == studentId)
            return *it;
    }
    throw "No Match Student";
}

double Class::getHighestScore() {
    // TODO implement getHighestScore
    double highest = -1.0;
    for (auto& sw : students) {
        double s = sw.getScore();
        if (s >= 0) {
            if (highest < 0 || s > highest) highest = s;
        }
    }
    if (highest < 0) throw "No Valid Score";
    return highest;
}

double Class::getLowestScore() {
    // TODO implement getLowestScore
    double lowest = -1.0;
    for (auto& sw : students) {
        double s = sw.getScore();
        if (s >= 0) {
            if (lowest < 0 || s < lowest) lowest = s;
        }
    }
    if (lowest < 0) throw "No Valid Score";
    return lowest;
}

double Class::getAvgScore() {
    // TODO implement getAvgScore
    double sum = 0;
    int count = 0;
    for (auto& sw : students) {
        double s = sw.getScore();
        if (s >= 0) {
            sum += s;
            count++;
        }
    }
    if (count == 0) throw "No Valid Score";
    return sum / count;
}

void Class::saveScore(const std::string& filename) {
    // TODO implement saveScore
    std::ofstream fout(filename, std::ios::app);
    if (!fout.is_open()) return;

    fout << name << std::endl;
    for (auto& sw : students) {
        if (sw.getScore() >= 0) {
            fout << sw.id << "," << sw.getScore() << std::endl;
        }
    }
}
