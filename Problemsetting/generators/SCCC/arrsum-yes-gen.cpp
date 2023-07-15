#include "testlib.h"
#include <iostream>

using namespace std;

vector<int> random_array(int size, int min_val, int max_val) {
    vector<int> res(size);
    res[0] = rnd.next(-1'000'000'000, 1'000'000'000);
    int d = rnd.next((-1'000'000'000-res[0])/size, (1'000'000'000-res[0])/size);
    for (int i = 1; i < size; i++) {
        res[i] = res[i-1] + d;
    }
    return res;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int size = atoi(argv[1]);
    int min_int = atoi(argv[2]);
    int max_int = atoi(argv[3]);

    vector<int> a = random_array(size, min_int, max_int);
    cout << size << endl;
    for (int i = 0; i < size-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[size-1] << endl;
    return 0;
}