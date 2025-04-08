#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(const string& name, int age) : name(name), age(age) {}

    virtual void sayHello() const {
        cout << "Привет, меня зовут " << name << "!" << endl;
    }

    virtual void displayInfo() const {
        cout << "Имя: " << name << ", Возраст: " << age << endl;
    }

    const string& getName() const { return name; }
    void setName(const string& newName) { name = newName; }

    int getAge() const { return age; }
    void setAge(int newAge) { 
        if (newAge > 0 && newAge < 150) {
            age = newAge;
        }
    }

    virtual ~Person() = default;
};

class Student : public Person {
private:
    string university;

public:
    Student(const string& name, int age, const string& university)
        : Person(name, age), university(university) {}

    void study() const {
        cout << name << " учится в " << university << endl;
    }

    const string& getUniversity() const { return university; }
    void setUniversity(const string& newUniversity) { university = newUniversity; }

    void displayInfo() const override {
        cout << "Студент: ";
        Person::displayInfo();
    }
};

void greetPerson(const Person& p) {
    p.sayHello();
}

int main() {
    unique_ptr<Student> student = make_unique<Student>("Иван", 20, "КМПО");
    
    cout << "Информация о студенте:" << endl;
    student->displayInfo();
    student->study();
    
    cout << "\nДемонстрация полиморфизма:" << endl;
    greetPerson(*student);
    
    cout << "\nДемонстрация геттеров и сеттеров:" << endl;
    cout << "Текущее имя: " << student->getName() << endl;
    cout << "Текущий возраст: " << student->getAge() << endl;
    cout << "Текущий университет: " << student->getUniversity() << endl;
    
    student->setName("Петр");
    student->setAge(21);
    student->setUniversity("Сириус");
    
    cout << "\nПосле изменения:" << endl;
    student->displayInfo();
    student->study();
    
    return 0;
}