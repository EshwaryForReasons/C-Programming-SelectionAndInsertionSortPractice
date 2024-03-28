
#include <iostream>

class Pet
{
public:

    std::string name;
    double weight;
    double height;

    bool operator<(const Pet& other) const;
    bool operator>(const Pet& other) const;
    bool operator==(const Pet& other) const;
};

bool Pet::operator<(const Pet& other) const
{
    if (weight == other.weight)
        return height < other.height;

    return weight < other.weight;
}

bool Pet::operator>(const Pet& other) const
{
    if (weight == other.weight)
        return height > other.height;

    return weight > other.weight;
}

bool Pet::operator==(const Pet& other) const
{
    return weight == other.weight && height == other.height;
}


void print_array(Pet** arr, int size)
{
    std::cout << "{";
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i]->name << (i == size - 1 ? "" : ", ");
    }
    std::cout << "}" << std::endl;;
}

void selection_sort(Pet** pets, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Step " << i + 1 << ": ";
        print_array(pets, size);

        //Consider only the unsorted portion, find min_element, bring to front
        int min_pet_index = i;
        for (int j = i; j < size; ++j)
        {
            if (*(pets[j]) < *(pets[min_pet_index]))
                min_pet_index = j;
        }

        //Small optimization, I will swap the elements instead of shifting them
        Pet* temp = pets[i];
        pets[i] = pets[min_pet_index];
        pets[min_pet_index] = temp;
    }
}

void insertion_sort(Pet** pets, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Step " << i + 1 << ": ";
        print_array(pets, size);

        //Find first smaller element
        int first_smaller_index = i;
        for (int j = i; j < size; ++j)
        {
            if(*(pets[j]) < *(pets[first_smaller_index]))
            {
                first_smaller_index = j;
                break;
            }
        }

        Pet* temp = pets[i];
        pets[i] = pets[first_smaller_index];
        pets[first_smaller_index] = temp;
    }
}

void init_array(Pet** arr)
{
    arr[0] = new Pet{ "Bob0", 10.0, 12.0 };
    arr[1] = new Pet{ "Bob1", 20.0, 13.0 };
    arr[2] = new Pet{ "Bob8", 90.0, 20.0 };
    arr[3] = new Pet{ "Bob2", 30.0, 14.0 };
    arr[4] = new Pet{ "Bob3", 40.0, 15.0 };
    arr[5] = new Pet{ "Bob6", 70.0, 18.0 };
    arr[6] = new Pet{ "Bob7", 80.0, 19.0 };
    arr[7] = new Pet{ "Bob4", 50.0, 16.0 };
    arr[8] = new Pet{ "Bob9", 100.0, 21.0 };
    arr[9] = new Pet{ "Bob5", 60.0, 17.0 };
}

int main()
{
    Pet** arr = new Pet*[10];

    std::cout << "Running selection sort:" << std::endl;
    init_array(arr);
    selection_sort(arr, 10);

    std::cout << "Running insertion sort:" << std::endl;
    init_array(arr);
    insertion_sort(arr, 10);

    return 0;
}