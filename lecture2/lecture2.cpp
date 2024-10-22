#include <iostream>
#include <vector>
#include <fstream>

// put classes in their own h file
class Student
{
    std::string m_first = "First";
    std::string m_last = "Last";
    int m_id = 0;
    float m_avg = 0;

public:
    Student() {}

    Student(std::string first, std::string last, int id, float avg)
        : m_first(first), m_last(last), m_id(id), m_avg(avg)
    {
    }

    // make this function const so we can not use it to change the student
    // cont correctnest
    int getAvg() const
    {
        return m_avg;
    }

    int getID() const
    {
        return m_id;
    }

    std::string getFirst() const
    {
        return m_first;
    }

    std::string getLast() const
    {
        return m_last;
    }

    void print() const
    {
        std::cout << m_first << " " << m_last << " id: " << m_id << " avg: " << m_avg << std::endl;
    }
};

class Course
{
    std::string m_name = "Course";
    std::vector<Student> m_students;

public:
    Course() {}

    Course(const std::string &name)
        : m_name(name)
    {
    }

    void addStudent(const Student &s)
    {
        m_students.push_back(s);
    }

    const std::vector<Student> &getStudents() const
    {
        return m_students;
    }

    void loadFromFile(const std::string &filename)
    {
        std::ifstream fin(filename);
        std::string first, last;
        int id;
        float avg;
        // std::string temp;

        // while (fin >> temp)
        // {
        //     std::cout << temp << std::endl;
        // }

        while (fin >> first)
        {
            // fin >> last;
            // fin >> id;
            // fin >> avg;
            fin >> last >> id >> avg;

            addStudent(Student(first, last, id, avg));
        }
    }

    void print() const
    {
        for (const auto &s : m_students)
        {
            s.print();
        }
    }
};

int main(int argc, char *argv[])
{
    int age = 31;
    std::string first = "Andre";
    std::string last = "Jarboe";
    std::string name = first + " " + last + " ";

    std::cout << name << std::endl;

    // vectors
    std::vector<float> vec;
    vec.push_back(29.8f);
    vec.push_back(10.69f);
    vec.push_back(11.42f);
    vec.push_back(99999.999999f);

    float a = vec[1];
    auto b = vec[1];

    std::cout << "***********No Error***********" << std::endl;

    std::cout << vec[0] << std::endl;
    std::cout << vec[1] << std::endl;
    // will print whatever is in memory:
    std::cout << vec[2] << std::endl;
    // size_t will make the i comparisin the same size depeneing on the OS
    // bace a vector size is unsiged
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }

    // will print vecots ast ints
    for (int a : vec)
    {
        std::cout << a << std::endl;
    }
    // will print vectors as they are
    // be careful this will copy the thing in the vecotr
    // matters when it is a string
    // so use a refrence and point to it
    for (auto a : vec)
    {
        std::cout << a << std::endl;
    }

    // Classes
    Student s1;
    Student s2("Andre", "Jarboe", 9, 92);
    Student s3("Emily", "Breihan", 20220001, 97);
    const Student s4("Jane", "Doe", 20220000, 99.9);

    std::cout << s3.getLast() << std::endl;

    s4.print();
    s3.print();
    s1.print();

    Course comp4300("COMP 4300");
    comp4300.addStudent(s1);
    comp4300.addStudent(s2);
    comp4300.addStudent(s3);
    comp4300.addStudent(s4);
    comp4300.addStudent(Student("Billly", "Bob", 3, 75.26));

    comp4300.print();

    std::cout << "***********************" << std::endl;
    Course c("COMP 4567");
    c.loadFromFile("students.txt");
    c.print();

    return 0;
}
