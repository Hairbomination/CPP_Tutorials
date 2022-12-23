#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(const std::string& name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
};

class Department
{
private:
    std::vector<std::reference_wrapper<const Teacher>>m_teacher{};

public:
    Department(const Teacher& teacher)
        : m_teacher{ teacher }
    {
    }

    Department() = default;         //My code is lines 31-52. All else is copy/paste
                                    //Their solution doesn't have any constuctors, just the add function
    void add(const Teacher& teacher)
    {
        m_teacher.push_back(teacher);
    }
    
    friend std::ostream& operator<< (std::ostream& out, const Department& dept);
};

std::ostream& operator<< (std::ostream& out, const Department& dept)
{
    out << "Department: ";
    for (auto name : dept.m_teacher)
    {                                   //Their solution is out << name.get().getName() << ' ';
        Teacher hm{ name.get() };       //Their creates an anonymous Teacher object. I knew creating a variable here was a bad
        out << hm.getName() << " ";     //idea but by this stage I was out of ideas. My code kept trying to construct
    }                                   //Department objects and was gettng stuck in endless loops.
    out << '\n';

    return out;
}

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        // Create a department and add some Teachers to it
        Department department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}