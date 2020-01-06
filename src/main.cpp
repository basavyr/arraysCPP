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
    static void Update(std::vector<T> &);
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

template <class T>
void VectorOperations<T>::Update(std::vector<T> &vec)
{
    for (int it = 0; it != vec.size(); ++it)
    {
        auto item = std::chrono::system_clock::now();
        std::time_t date = std::chrono::system_clock::to_time_t(item);
        // vec.at(it) = static_cast<T>(item);
        // std::cout << typeid(item).name() << " " << typeid(date).name();
        // newLine();
        // vec.at(it) = item;
    }
}

template <typename T>
void printarray(T vec)
{
    size_t size = sizeof(vec);
    std::cout << size;
    newLine();
    std::cout << sizeof(T);
    newLine();
    std::cout << sizeof(vec[0]);
    newLine();
    std::cout << vec[0];
    newLine();
}

int main()
{
    const std::string name = "Robert";
    app(name);
    auto now = std::chrono::system_clock::now();
    std::time_t date = std::chrono::system_clock::to_time_t(now);
    std::string utc = std::ctime(&date);
    // std::cout << utc;

    auto stringsize = utc.length();
    std::cout << stringsize;
    newLine();
    char sdate[stringsize + 1];
    strcpy(sdate, utc.c_str());
    std::cout << sizeof sdate;
    newLine();
    printarray(sdate);
    newLine();
    // std::cout << typeid(utc).name();
    newLine();
    VectorOperations<double> vop(6, 'a');
    // std::cout << vop.Sum(vop.array);
    newLine();
    /* 
    vop.show(vop.array);
    newLine(); */

    /*  vop.Update(vop.array);
    newLine();
    vop.show(vop.array);
    newLine();
    */
    return 0;
}