#include <iostream>
#include <vector>
#define SIZE 10

int main(void) {

    /* 9, 8, 3, 2, 3, 1, 5, 2, 7 */
    std::vector<int> arr = {1, 8, 3, 2, 3, 1, 5, 2, 7};
    
    std::vector<int>::iterator it;

    int i, j;

    for (j = 1; j < arr.size(); j++){
        int key = arr[j];
        i = j-1;
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i -= 1;
        }
        arr[i+1] = key;
    }
    for (it = arr.begin(); it != arr.end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl;

    return 0;
}