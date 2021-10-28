#include "Zombie.hpp"

int main(void)
{//const char*를 인자로 한 string 객체 생성자 자동 호출
    Zombie zombie1("zombie1");
    zombie1.announce();//스택 저장됐다 main()의 return 만나면 소멸자 호출

    Zombie* zombie2 = newZombie("zombie2");
    zombie2->announce();//힙에 할당됐다
    delete zombie2;//여기서 해제되고 소멸자 호출

    randomChump("zombie3");
    //함수 내서 지역변수로 객체 생성됐다가 함수 반환 후 객체 소멸자 호출
    return 0;
}