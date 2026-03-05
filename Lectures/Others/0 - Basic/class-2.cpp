/*
 Write a C++ program in which we have
     A class vehicle as the base class with private,
        protected, and public objects
     A class car as a derived class
     A class truck as a derived class
     A main instantiating objects of the previous classes
*/

#include <iostream>
#include <string>

class Vehicle {
    private:
        // Vehicle Identification Number (hidden)
        std::string privateVIN;
    protected:
        // Make of the vehicle and yaer (accessible to derived)
        std::string protectedMake;
        int protectedYear;
    public:
        // Color of the vehicle (accessible to all)
        std:: string publicColor;
    
        // Primary Constructor
        Vehicle(const std::string& vin, const std::string& make, 
                 int year, const std::string& color)
            : privateVIN(vin), protectedMake(make), 
              protectedYear(year), publicColor(color) { }

        void displayPublicInfo() const { // const means it can't change the object.
            std::cout << "Color: " << publicColor << std::endl;
        }
    protected:
        void displayProtectedInfo() const {
            std::cout << "Make: " << protectedMake << std::endl;
            std::cout << "Year: " << protectedYear << std::endl;
        }

    private:
        void displayPrivateInfo() const {
            std::cout << "VIN: " << privateVIN << std::endl;
        }
    
    public:
        void displayFullInfo() const {
            displayPublicInfo();
            displayProtectedInfo();
            displayPrivateInfo();
        }
};

class Car: public Vehicle {
    private:
        int privateNumDoors;

    public:
        Car(const std::string& vin, const std::string& make,
            int year, const std::string& color, int numDoors):
          Vehicle(vin, make, year, color),
          privateNumDoors(numDoors) { } // privateNumDoors(numDoors) is the initializer list

        void displayCarInfo() const {
            displayProtectedInfo(); // accessible to derived class
            displayPublicInfo();
            std::cout << "Number of Doors: " << 
                privateNumDoors << std::endl;
        }
};

class Truck : public Vehicle {
    private:
        double privatePayloadCapacity;

    public:
        Truck(const std::string& vin, const std::string& make,
                int year, const std::string& color,
            double capacity) :
         Vehicle(vin, make, year, color),
         privatePayloadCapacity(capacity) { }

         void displayTruckInfo() const {
            displayProtectedInfo();
            displayPublicInfo();
            std::cout << "Playload Capacity: " <<
                privatePayloadCapacity << std::endl;
         }
};

int main() {
    Car myCar ("123456789", "toyota", 2022, "Blue", 4);
    Truck myTruck("987654321", "Ford", 2021, "Red", 5.0);

    std::cout << "Car Information:\n";
    myCar.displayCarInfo();

    std::cout << "\nTruck Information:\n";
    myTruck.displayTruckInfo();

    std::cout << "\nVehicle full information: \n";
    myCar.displayFullInfo();

    // Error: The private function is not accesible
    // myCar.displayPrivateInfo();

    return 0;
}