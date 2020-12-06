// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <iostream>
#include <vector>
#include <string>

struct Student {
  std::string Name;
  std::string GroupId;
  std::vector<unsigned> Ratings;
  std::vector<std::string> Subjects;
};
struct Group {
  std::string Id;
  std::vector<Student> Students;
};

struct result;
void SortByName(std::vector<Student>& students);
void SortByRating(std::vector<Student>& students);
size_t CountTwoness(const std::vector<Student>&students);
size_t CountExcellent(const std::vector<Student>&);
std::vector<std::string> GroupsId(const std::vector<Student>& students );
std::vector<Student> VectorMathExcellent(
    const std::vector<Student>& students);
std::vector<Group> Groups(const std::vector<Student>& students);
#endif  // INCLUDE_HEADER_HPP_
