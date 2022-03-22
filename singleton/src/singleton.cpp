#include <iostream>

using namespace std;

// Basic singleton class to show of the design pattern
class singleton
{
private:
    // Make the singleton instance static (only one ever)
    static singleton *instance;

    // Private constructor to ensure only a single instantiation
    singleton(){};

public:
    // Static access method to get our single instance
    static singleton *get_instance();
};

// Initialize static class member to be a nullptr
singleton *singleton::instance = nullptr;

// Returns the single Singleton instance. Creates it if it does
// not already exist
singleton *singleton::get_instance()
{
    // Check if the static instance variable is null still
    // Referred to as "lazy instantiation" (don't create until needed)
    if (!instance)
    {
        // If not, create the first singleton instance ...
        instance = new singleton();
    }

    // ... and return it
    return instance;
}

int main()
{
    // ILLEGAL! constructor is private!
    // Singleton *test = new Singleton();

    // Creates a new singleton, and returns a pointer to it
    singleton *simple_singleton_1 = singleton::get_instance();

    // Only returns a pointer to the single Singleton instance
    singleton *simple_singleton_2 = singleton::get_instance();

    // Print out pointers (should be the same)
    cout << "Singleton 1: " << simple_singleton_1 << " Singleton 2: "
         << simple_singleton_2 << endl;

    return 0;
}