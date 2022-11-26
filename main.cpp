#include "print_ip_file.cpp"


int main(int, char const **)
{
    try
    {
        char addrChar{-1};
        PrintIp(addrChar);

        short addrShort{0};
        PrintIp(addrShort);

        int addrInt{2130706433};
        PrintIp(addrInt);

        long addrLong{8875824491850138409};
        PrintIp(addrLong);

        PrintIp("123.45.67.89.12.34.56");

        using IntList = std::list<int>;
        IntList l{0, 1, 2, 3};
        PrintIp<IntList>(l);

        using StringVector = std::vector<std::string>;
        StringVector v{"abc", "def", "gij", "klm", "nop", "rst"};
        PrintIp<StringVector>(v);

        std::tuple<int, int, int, int> t{127, 0, 0, 1};
        PrintIp(t);

        std::tuple<std::string, std::string, std::string> tStr{"abc", "def", "gij"};
        PrintIp(tStr);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
