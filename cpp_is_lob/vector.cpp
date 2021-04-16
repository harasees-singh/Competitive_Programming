#include<vector>
#include<iostream>
int main()
{
    std::vector<int> a = {1, 2, 3, 4};
    std::cout << a[3] << " " << std::endl;      // accessing vector through index
    for(int n:a)
    {
        std::cout<< n << "\n";
    }
    auto it = a.begin();        // auto is basically "set the type of it by yourself" at runtime
    std::cout<< *it << "\n" ;
    it++;
    std::cout<< *it;            // accessing vector through pointer
    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(&a).name() << std::endl;
    return 0;
}