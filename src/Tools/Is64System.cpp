#include <cstdlib>

int main(int argc, char** argv)
{
    size_t size = sizeof(void*);
    if (size == 4) return 0;
    return 1;
}
