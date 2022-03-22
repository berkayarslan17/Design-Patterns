#include <iostream>

using namespace std;

// Base class for a product from the factory
class product
{
public:
    virtual void print_product() = 0;
};

// Implementation 1 of the abstract class
class product_one : public product
{
public:
    void print_product()
    {
        cout << "Hello from Product1!" << endl;
    }
};

// Implementation 2 of the abstract class
class product_two : public product
{
public:
    void print_product()
    {
        cout << "Hello from Product2!" << endl;
    }
};

// Simple factory for products
// Commonly implemented as a singleton
class product_factory
{
private:
    // Make the instance static
    static product_factory *instance;

    // Private constructor
    product_factory(){};

public:
    // Static access method to get our single instance
    static product_factory *get_instance();

    // Product instantiation occurs through a factory method
    // Allows user code to not worry about instantiation
    product *create_product(int ID);
};

// Create's a product on the caller's behalf
product *product_factory::create_product(int ID)
{
    // Create a product of type 1
    if (ID == 0)
    {
        return new product_one();
        // Create a product of type 2
    }
    else if (ID == 1)
    {
        return new product_two();
        // Return nullptr if no matching type
    }
    else
    {
        return nullptr;
    }
}

// Initialize static class member to be a nullptr
product_factory *product_factory::instance = nullptr;

// Returns the single Product Factory instance. Creates creates it if
// it does not already exist
product_factory *product_factory::get_instance()
{
    // Check if the static instance variable is null still
    // Referred to as "lazy instantiation" (don't create until needed)
    if (!instance)
    {
        // If not, create the first singleton instance ...
        instance = new product_factory();
    }

    // ... and return it
    return instance;
}

int main()
{
    // Create the first instance of the factory singleton
    product_factory *pf = product_factory::get_instance();

    // Create a pointer parent class
    product *p;

    // Create a product of type 0
    p = pf->create_product(0);
    p->print_product();

    // Create a product of type 1
    p = pf->create_product(1);
    p->print_product();

    return 0;
}