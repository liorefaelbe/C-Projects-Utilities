#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Forward declarations
class RaceCar;
class Truck;
class Motorcycle;

// Base interface
class IEntity 
{
public:
    virtual ~IEntity() {}

    // Accept method for double dispatch
    virtual void CollideWith(IEntity* other) = 0;

    // Overloaded handlers for each type
    virtual void CollideWithRaceCar(RaceCar* rc) = 0;
    virtual void CollideWithTruck(Truck* truck) = 0;
    virtual void CollideWithMotorcycle(Motorcycle* mc) = 0;

    virtual const char* getName() const = 0;
};

// Derived types

class RaceCar : public IEntity 
{
public:
    void CollideWith(IEntity* other)  
    {
        other->CollideWithRaceCar(this);
    }

    void CollideWithRaceCar(RaceCar* rc)  
    {
        (void)rc;

        cout << "Collision: RaceCar vs RaceCar\n";
    }

    void CollideWithTruck(Truck* truck)  
    {
        (void)truck;

        cout << "Collision: Truck vs RaceCar\n";
    }

    void CollideWithMotorcycle(Motorcycle* mc)  
    {
        (void)mc;

        cout << "Collision: Motorcycle vs RaceCar\n";
    }

    const char* getName() const  
    {
        return "RaceCar";
    }
};

class Truck : public IEntity 
{
public:
    void CollideWith(IEntity* other)  
    {
        other->CollideWithTruck(this);
    }

    void CollideWithRaceCar(RaceCar* rc)  
    {
        (void)rc;

        cout << "Collision: RaceCar vs Truck\n";
    }

    void CollideWithTruck(Truck* truck)  
    {
        (void)truck;

        cout << "Collision: Truck vs Truck\n";
    }

    void CollideWithMotorcycle(Motorcycle* mc)  
    {
        (void)mc;

        cout << "Collision: Motorcycle vs Truck\n";
    }

    const char* getName() const  
    {
        return "Truck";
    }
};

class Motorcycle : public IEntity 
{
public:
    void CollideWith(IEntity* other)  
    {
        other->CollideWithMotorcycle(this);
    }

    void CollideWithRaceCar(RaceCar* rc)  
    {
        (void)rc;

        cout << "Collision: RaceCar vs Motorcycle\n";
    }

    void CollideWithTruck(Truck* truck)  
    {
        (void)truck;

        cout << "Collision: Truck vs Motorcycle\n";
    }

    void CollideWithMotorcycle(Motorcycle* mc)  
    {
        (void)mc;

        cout << "Collision: Motorcycle vs Motorcycle\n";
    }

    const char* getName() const  
    {
        return "Motorcycle";
    }
};

int main()
{
    vector<IEntity*> entities;
    entities.push_back(new RaceCar);
    entities.push_back(new Truck);
    entities.push_back(new Motorcycle);

    cout << "=== Collision Tests ===\n";

    for (size_t i = 0; i < entities.size(); ++i) 
    {
        for (size_t j = 0; j < entities.size(); ++j) 
        {
            cout << entities[i]->getName() << " Collides with " << entities[j]->getName() << ": ";
            entities[i]->CollideWith(entities[j]);
        }
    }

    for (size_t i = 0; i < entities.size(); ++i) 
    {
        delete entities[i];
    }

    return (0);
}
