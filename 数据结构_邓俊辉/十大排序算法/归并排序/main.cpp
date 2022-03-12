//空间复杂度为O(1)的归并排序
//时间复杂度O(nlogN)
#include <iostream>
using namespace std;

void reverse_array(int a[], int n) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        swap(a[i], a[j]);
        ++i;
        --j;
    }
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

}

void exchange(int a[], int length, int length_left) {
    // a+begin开始,length=2 length_left=1
    cout << *a << " ";
    cout << length << " "<< length_left << endl;
    reverse_array(a, length_left);
    printArr(a, length);
    reverse_array(a + length_left, length - length_left);
    printArr(a, length);
    reverse_array(a, length);
    printArr(a, length);
}

void Merge(int a[], int begin, int mid, int end) {
    cout << begin << " " << mid << " " << end << endl;
    // begin = 0  mid = 2  end = 1 step=1
    // 2 3 3
    while (begin < mid && mid <= end) {
        int step = 0;
        while (begin < mid && a[begin] <= a[mid])
            ++begin;
        while (mid <= end && a[mid] <= a[begin]) {
            ++mid;
            ++step;
        }
        // a[0] 2 1
        // 3 4 1 
        cout << "a+begin= " << *(a+begin) << endl;
        exchange(a + begin, mid - begin, mid - begin - step);
    }
}

void MergeCore(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2; // start+(end-start)/2
        MergeCore(a, left, mid);
        MergeCore(a, mid + 1, right);
        // left = 0  mid = 1  right = 1
        // left = 2 mid = 3 right=3
        Merge(a, left, mid + 1, right);
    }
}

void MergeSort(int a[], int length) {
    if (a == NULL || length < 1)
        return;
    MergeCore(a, 0, length - 1);
}

int main() {
    int a[] = {1,0,2,9,3,8,4,7,6,5,11,99,22,88,11};
    int length = sizeof(a) / sizeof(int);
    MergeSort(a, length);
    
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}