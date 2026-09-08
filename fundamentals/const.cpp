#include <iostream>
#include <string>

class Entity{
    private:
        int m_X, m_Y;
    public:
        int GetX() const{
            return m_X;
        }
        void SeetX(int x){
            m_X = x;
        }
};

int main(){
    const int MAX_AGE = 90;
    int *a = new int;
    *a = 2;

    std::cout << *a << std::endl;
    std::cin.get();
    return 0;
}