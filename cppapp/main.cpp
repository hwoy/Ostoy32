#include <cstdio>

template <typename Tint>
bool isprime(Tint num)
{
    if(num<2) return false;

    for(Tint i=2;i*i<=num;++i)
    if(!(num%i)) return false;

    return true;
}

extern "C"
int main()
{
    for(unsigned int num=1;num<=100;++num)
    if(isprime(num)) std::printf("%u\n",num);

    return 0;
}