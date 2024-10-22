#include <iostream>
#include <vector>

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

    //make this function const so we can not use it to change the student
    //cont correctnest
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

    return 0;
}
