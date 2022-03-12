#include <iostream>


void merge(int arr[], int start, int mid, int end)
{
    int *temp = new int[end - start + 1];
    // mid到最后肯定是和start相同, 因此p2指向mid之后的数
    int p = 0, p1 = start, p2 = mid+1;
    // p1从开始到mid, p2从mid+1到end, 进行合并
    while (p1 <= mid && p2 <= end)
    {
         // 比较p1和p2指向的值谁小
        if (arr[p1] > arr[p2]) // 如果arr[p1]大那么临时数组存小的
            temp[p++] = arr[p2++];
        else
            temp[p++] = arr[p1++]; // 如果arr[p1]小那么保持原来的插入即可，保持稳定性    
    }
    
    // 将剩余的大元素填入数组，这里应该是只有长度小于等于的那个数组会填充元素
    while (p1 <= mid)
        temp[p++] = arr[p1++];

    while (p2 <= end)
        temp[p++] = arr[p2++];

    // 将临时数组都填入原数组
    for (int i = 0; i < end-start+1; i++)
    {
        arr[i + start] = temp[i];
    }
    delete [] temp;
}

/**
 * 
 * @brief 归并排序递归实现，分治
 * @param a[] 待排序数组
 * @param start 起始位置
 * @param end 结束位置
 * @return void 返回值为空
 * 
*/

void mergeSort(int a[], int start, int end)
{
    if (start >= end) return;
    // std::cout << end << start;
    // -, +号优先级比右移优先级要大
    int mid = (end-start >> 1) + start;
    // std::cout << mid << std::endl;
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);
    merge(a, start, mid, end); // 合并
}

int main()
{

    int a[] = {2, 4, 6, 1, 3, 7, 9, 8, 5};

    std::cout << sizeof(a)/sizeof(a[0]) << std::endl;

    mergeSort(a, 0, sizeof(a)/sizeof(a[0])-1);

    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;

}