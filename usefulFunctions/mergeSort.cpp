
#include <iostream>
#include <vector>

void printArr(std::vector<int> &arr)
{
    for (int el : arr)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void merge(std::vector<int> &arr, size_t start, size_t middle, size_t end)
{
    std::vector<int> leftPart, rightPart;
    int leftPartSize = middle - start + 1;
    int rightPartSize = end - middle;
    for (size_t i = 0; i < leftPartSize; ++i)
    {
        leftPart.push_back(arr[start + i]);
    }
    for (size_t j = 0; j < rightPartSize; ++j)
    {
        rightPart.push_back(arr[middle + j + 1]);
    }
    int i = 0, j = 0, k = start;

    while (i < leftPartSize && j < rightPartSize)
    {
        if (leftPart[i] < rightPart[j])
        {
            arr[k++] = leftPart[i++];
        }
        else
        {
            arr[k++] = rightPart[j++];
        }
    }
    while (i < leftPartSize)
    {
        arr[k++] = leftPart[i++];
    }
    while (j < rightPartSize)
    {
        arr[k++] = rightPart[j++];
    }

    printArr(arr);
}
void mergeSplitSort(std::vector<int> &arr, size_t start, size_t end)
{
    if (start >= end)
    {
        return;
    }
    int middleEl = (end + start) / 2;
    mergeSplitSort(arr, start, middleEl);
    mergeSplitSort(arr, middleEl + 1, end);
    merge(arr, start, middleEl, end);
}

void mergeSort(std::vector<int> &arr)
{
    mergeSplitSort(arr, 0, arr.size() - 1);
}

int main()
{

    std::vector<int> arr = {5, 9, 2, 87, 22, 25, 2, 2, 9, 12, 1};
    mergeSort(arr);
    std::cout << "Final sorted array: ";
    printArr(arr);
    return 0;
}