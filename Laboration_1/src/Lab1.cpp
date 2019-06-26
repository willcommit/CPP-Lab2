/* -------------------------------
 * Laboration 1
 * PEKARE
 * William Elfversson, wiel1300
 * 2019-01-27
 * -------------------------------*/

//HEADER
#include <iostream>
#include <random>
#include <ctime>

// Takes array and address to beyond last element and returns point to LARGEST element
int *findMaxNumber (int array[], int *end);
// Takes array and address to beyond last element and returns point to SMALLEST element
int *findMinNumber (int array[], int *end);
// Takes array and address to beyond last element and returns SUM of elements
int calculateSum (int array[], int *end);
//------------------------------------------------------------------


int main() {

    int counter {0}; // used for counting loop number
    constexpr int MAX_PRINT {200}; // constant for maximum number of elements to print
    size_t size{0}; // size of array, dynamically assigned by user.
    int *array_ptr{nullptr}; // pointer which will be used to point to dynamically assigned array.

    std::default_random_engine generator(static_cast<unsigned>(time(0))); // initialization of random generator.
    std::uniform_int_distribution<int> random(-5000, 5000); // distribution of random integers from -5000 to +5000

    std::cout << "Enter how many numbers the array should hold: ";
    std::cin >> size;
    std::cin.get();

    array_ptr = new int[size]; // create new dynamic memory block/array in heap

    int *end = &array_ptr[size]; // pointer to beyond LAST address in array block

    // iterating from address of first element while address not beyond last element i array
    for (int *b = array_ptr; b != end; ++b) {

        // used to only show 200 elements at a time
        if (counter == MAX_PRINT) {
            counter = 0;
            std::cout << "\nPress \"ENTER\" to print 200 elements more\n";
            std::cin.ignore(); // Actually any key kan be pressed..
        }

        *b = random(generator); // assigning random number to value of address.
        std::cout << *b << std::endl; // printing value;

        counter++;
    }

    std::cout << "\nMax number is: " << *findMaxNumber(array_ptr, end)
              << "\nMin number is: " << *findMinNumber(array_ptr, end)
              << "\nSum of all numbers are: " << calculateSum(array_ptr, end) << std::endl;

    delete[] array_ptr; //delete block after use, otherwise memory leak.

    return 0;
}

int *findMaxNumber (int array[], int *end)
{
    int max {0};
    int *returnPointer {nullptr};

    for(int *b = array; b != end; ++b){
        if(*b > max){
            max = *b;
            returnPointer = b;
        }
    }
    return returnPointer;
}

int *findMinNumber (int array[], int *end)
{
    int min {0};
    int *returnPointer {nullptr};

    for(int *b = array; b != end; ++b){
        if(*b < min){
            min = *b;
            returnPointer = b;
        }
    }
    return returnPointer;
}

int calculateSum (int array[], int *end)
{
    //int *end = &array[size];
    int sum {0};

    for(int *b = array; b != end; ++b)
        sum += *b;

    return  sum;
}

