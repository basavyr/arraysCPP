#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>

inline void newLine()
{
    std::cout << "\n";
}

template <typename T>
void app(const T &name)
{
    std::cout << "This is " << name;
    newLine();
}

template <typename T>
void printArray(std::vector<T> &vec)
{
    for (auto &&n : vec)
    {
        std::cout << n << " ";
    }
    newLine();
}

template <typename T>
size_t sizeOfArray(std::vector<T> &vec)
{
    auto retval = sizeof(vec) + (sizeof(T) * vec.size());
    return retval;
}

template <class T>
class VectorOperations
{
    size_t arrsize;

public:
    std::vector<T> array;
    VectorOperations(size_t size, T arg)
    {
        for (auto id = 0; id < size; ++id)
        {
            auto currentValue = static_cast<T>(arg);
            VectorOperations::array.emplace_back(currentValue);
        }
    }
    static T Sum(std::vector<T> &);
    static void show(std::vector<T> &);
};

template <class T>
T VectorOperations<T>::Sum(std::vector<T> &array)
{
    auto sum = 0.0;
    for (auto &&n : array)
    {
        sum += n;
    }
    return sum;
}

template <class T>
void VectorOperations<T>::show(std::vector<T> &vec)
{
    for (auto &&n : vec)
    {
        std::cout << n << " ";
    }
    std::cout << std::flush;
}

int main()
{
    const std::string name = "Robert";
    app(name);
    VectorOperations<double> vop(6, 69.420);
    std::cout << vop.Sum(vop.array);
    newLine();
    vop.show(vop.array);
    newLine();
    return 0;
}