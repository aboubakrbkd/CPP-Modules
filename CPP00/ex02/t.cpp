#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    std::time_t timestamp = std::time(0);
    std::tm *ltm = localtime(&timestamp);  
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", ltm);
    std::cout << buffer;
}

