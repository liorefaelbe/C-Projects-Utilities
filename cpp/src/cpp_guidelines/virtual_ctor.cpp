#include <iostream>
#include <string>

// 1. Loading correct shape types from file (Factory + Virtual Constructor Idiom)

// Base interface
class IShape 
{
public:
    virtual ~IShape() {}
    virtual void draw() = 0;
    virtual const char* type() const = 0; // Optional helper
};

// Derived
class Circle : public IShape 
{
public:
    void draw()  { std::cout << "Drawing Circle\n"; }
    const char* type() const  { return "Circle"; }
};

class Square : public IShape 
{
public:
    void draw()  { std::cout << "Drawing Square\n"; }
    const char* type() const  { return "Square"; }
};

// Factory
class ShapeFactory 
{
public:
    static IShape* createShape(const std::string& shapeType) 
    {
        if (shapeType == "Circle") return (new Circle);
        if (shapeType == "Square") return (new Square);
        return (NULL);
    }
};

/***********************************************************************************************************/

// 2. Duplicating vehicle at runtime with only IVehicle* (Virtual Copy Constructor)

// Base
class IVehicle 
{
public:
    virtual ~IVehicle() {}
    virtual IVehicle* clone() const = 0; // Virtual copy constructor
};

// Derived
class Car : public IVehicle 
{
public:
    IVehicle* clone() const 
    {
        return new Car(*this); // copy constructor
    }
};

class Truck : public IVehicle 
{
public:
    IVehicle* clone() const  
    {
        return new Truck(*this);
    }
};
    
/***********************************************************************************************************/

// 3. Virtualizing << and >> for shape hierarchy (Polymorphic I/O)

// Base
class IShape 
{
public:
    virtual ~IShape() {}
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
};

// Derived
class Circle : public IShape 
{
public:
    void print(std::ostream& os) const  
    {
        os << "Circle with radius 5";
    }

    void read(std::istream& is)  
    {
        // Read data into circle
    }
};

class Square : public IShape 
{
public:
    void print(std::ostream& os) const  
    {
        os << "Square with side 3";
    }

    void read(std::istream& is)  
    {
        // Read data into square
    }
};

// Non-member operator overloads
std::ostream& operator<<(std::ostream& os, const IShape& shape) 
{
    shape.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, IShape& shape) 
{
    shape.read(is);
    return is;
}
    