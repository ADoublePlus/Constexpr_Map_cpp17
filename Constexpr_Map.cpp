#include <iostream>
#include <array>
#include <string.h>

using namespace std;

class Constexpr_Map
{
    public:
        constexpr Constexpr_Map() : ind{ 0 }, arr{{}} {};

        constexpr void insert(const char* str)
        {
            arr[ind++] = str;
        }

        constexpr int _recursive_strcmp(const char* str1, const char* str2, int i) 
        {
            if ((!str1[i] && str2[i]) || (!str2[i] && str1[i]))
                return 1;

            if ((!str1[i] && !str2[i]))
                return 0;

            if (str1[i] == str2[i])
                return _recursive_strcmp(str1, str2, i + 1);

            return 1;
        }

        constexpr int recursive_strcmp(const char* str1, const char* str2)
        {
            return _recursive_strcmp(str1, str2, 0);
        }

        constexpr int getind(const char* str)
        {
            for (int i = 0; i < 3; i++) 
            {
                if (!recursive_strcmp(arr[i], str))
                    return i;
            }

            return -1;
        }

        int ind;
        array<const char*, 10> arr;
};

int main()
{
    Constexpr_Map a;
    a.insert("aa");
    a.insert("ba");
    a.insert("ca");

    cout << a.getind("c");
}