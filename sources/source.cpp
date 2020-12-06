// Copyright 2020 Your Name <your_email>

#include <header.hpp>
#include <vector>
void SortByName(std::vector<Student>& students) {
  if (students.size() != 0) {
    for (unsigned int i = 0; i < students.size() - 1; i++) {
      for (unsigned int j = 0; j < students.size() - i - 1; j++) {
        if (students[j].Name.compare(students[j + 1].Name) > 0) {
          Student x = students[j + 1];
          students[j + 1] = students[j];
          students[j] = x;
        }
      }
    }
  }
}
void SortByRating(std::vector<Student>& students) {
  std::vector<double> srzn(students.size());
  Student v;
  double o;
  if (students.size() != 0) {
    for (unsigned int i = 0; i < students.size(); i++) {
      for (unsigned int j = 0; j < students[i].Ratings.size(); j++)
        srzn[i] += students[i].Ratings[j];
      srzn[i] /= students[i].Ratings.size();
    }
    for (unsigned int n = 0; n < students.size(); n++)
      for (unsigned int i = 0; i < (srzn.size() - 1); i++)
        if (srzn[i] < srzn[i + 1]) {
          v = students[i];
          students[i] = students[i + 1];
          students[i + 1] = v;
          o = srzn[i + 1];
          srzn[i + 1] = srzn[i];
          srzn[i] = o;
        }
  }
}

size_t CountTwoness(const std::vector<Student>& students) {
  size_t count = 0;
  for (unsigned int k = 0; k < students.size(); k++)
    for (unsigned int i = 0; i < (students[k].Ratings.size()); i++)
      if (students[k].Ratings[i] == 2) {
        count++;
        break;
      }
  return (count);
}

size_t CountExcellent(const std::vector<Student>& students) {
  size_t count = 0;
  for (unsigned int k = 0; k < students.size(); k++)
    for (unsigned int i = 0; i < (students[k].Ratings.size()); i++)
      if (students[k].Ratings[i] != 5) {
        count++;
        break;
      }
  return (students.size() - count);
}

std::vector<Student> VectorMathExcellent(const std::vector<Student>& students);
unsigned amount(std::vector<std::string> Subjects) {
  unsigned int result = Subjects.size() + 1;
  for (unsigned int i = 0; i < Subjects.size(); i++) {
    if (Subjects[i] == "Math") {
      result = i;
    }
  }
  if (result == (Subjects.size() + 1)) {
    return Subjects.size() + 1;
  }
  return result;
}
std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) {
  std::vector<Student> excellent;
  for (unsigned int i = 0; i < students.size(); i++) {
    if (amount(students[i].Subjects) != (students[i].Subjects.size() + 1)) {
      if (students[i].Ratings[amount(students[i].Subjects)] == 5) {
        excellent.push_back(students[i]);
      }
    }
  }
  return excellent;
}

std::vector<std::string> GroupsId(const std::vector<Student>& students) {
  std::vector<std::string> GN = {};
  if (!(students.empty())) GN.push_back(students[0].GroupId);
  for (unsigned int i = 0; i < students.size(); i++) {
    for (unsigned int j = 0; j < GN.size(); j++) {
      if (students[i].GroupId == GN[j]) break;
      if (j == GN.size() - 1) GN.push_back(students[i].GroupId);
    }
  }
  return (GN);
}
std::vector<Group> Groups(const std::vector<Student>& students) {
  std::vector<Group> groups;
  std::vector<Student> studentss;
  for (unsigned int i = 0; i < GroupsId(students).size(); i++) {
    for (unsigned int j = 0; j < students.size(); j++) {
      if (students[j].GroupId == GroupsId(students)[i]) {
        studentss.push_back(students[j]);
      }
    }
    groups.push_back({GroupsId(students)[i], studentss});
    studentss.clear();
  }
  return groups;
}
