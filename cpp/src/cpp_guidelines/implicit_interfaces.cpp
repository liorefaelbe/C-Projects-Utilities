// Exercise 1: Runtime Polymorphism - Abstract Base Class

#include <iostream>
#include <vector>
#include <memory>

class IWorker
{
public:
    virtual void Work(float time) = 0;
    virtual float CalculateSalary() = 0;
    virtual ~IWorker() {}
};

class Engineer : public IWorker
{
public:
    void Work(float time) override { std::cout << "Engineer worked " << time << " hours.\n"; }
    float CalculateSalary() override { return 100.0f; }
};

class Manager : public IWorker
{
public:
    void Work(float time) override { std::cout << "Manager worked " << time << " hours.\n"; }
    float CalculateSalary() override { return 200.0f; }
};

class Company1
{
    std::vector<std::shared_ptr<IWorker>> workers;
public:
    void AddWorker(std::shared_ptr<IWorker> w) { workers.push_back(w); }
    void SimulateWork() 
    {
        for (auto& w : workers)
        {
            w->Work(8);
            std::cout << "Salary: " << w->CalculateSalary() << "\n";
        }
    }
};

// Exercise 2: Compile-Time Polymorphism - Template

#include <iostream>
#include <vector>

template <typename T>
class Company2
{
    std::vector<T> workers;
public:
    void AddWorker(const T& w) { workers.push_back(w); }
    void SimulateWork()
    {
        for (const auto& w : workers)
        {
            w.Work(8);
            std::cout << "Salary: " << w.CalculateSalary() << "\n";
        }
    }
};

class Developer
{
public:
    void Work(float time) { std::cout << "Developer worked " << time << " hours.\n"; }
    float CalculateSalary() { return 150.0f; }
};