#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class MyType
{
    int value;
    double factor;
    std::string type;

public:
    MyType()
    : value(0), factor(0.0), type("none") {}
    MyType(int value, double factor, const std::string& type)
    : value(value), factor(factor), type(type) {}

    // Serialized output
    friend std::ostream& operator<<(std::ostream& os, const MyType& m)
    {
        return os << m.value << ' ' << m.factor << ' ' << m.type;
    }

    // Serialized input
    friend std::istream& operator>>(std::istream& is, MyType& m)
    {
        return is >> m.value >> m.factor >> m.type;
    }
};

int main()
{
    std::vector<MyType> v {{1, 2.7, "one"}, {4, 5.1, "two"}, {3, 0.6, "three"}};

    std::cout << "Serialize to standard output." << '\n';

    for(auto const& m: v)
        std::cout << m << '\n';

    std::cout << "\nSerialize to a string." << '\n';

    std::stringstream ss;
    for(auto const& m: v)
        ss << m << '\n';

    std::cout << ss.str() << '\n';

    std::cout << "Deserialize from a string." << '\n';

    std::vector<MyType> v2;

    MyType m;
    while(ss >> m)
        v2.push_back(m);

    for(auto const& m: v2)
        std::cout << m << '\n';

}