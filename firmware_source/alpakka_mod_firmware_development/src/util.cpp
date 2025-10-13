#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// 返回长度
uint16_t memory_copy(void *dest, const void *src, const uint16_t size)
{
    uint8_t *_dest = (uint8_t *)dest;
    const uint8_t *_src = (const uint8_t *)src;
    for (uint16_t i = 0; i < size; i++)
    {
        _dest[i] = _src[i];
    }
    return size;
}

uint8_t dpad_button_to_hat_switch_8(uint8_t up, uint8_t down, uint8_t left, uint8_t right)
{
    uint8_t hat_switch = 8;
    if (up)
    {
        if (right)
            hat_switch = 1; // NE
        else if (left)
            hat_switch = 7; // NW
        else
            hat_switch = 0; // N
    }
    if (right)
    {
        if (up)
            hat_switch = 1; // NE
        else if (down)
            hat_switch = 3; // SE
        else
            hat_switch = 2; // E
    }
    if (down)
    {
        if (right)
            hat_switch = 3; // SE
        else if (left)
            hat_switch = 5; // SW
        else
            hat_switch = 4; // S
    }
    if (left)
    {
        if (up)
            hat_switch = 7; // NW
        else if (down)
            hat_switch = 5; // SW
        else
            hat_switch = 6; // W
    }
    return hat_switch;
}

uint8_t dpad_button_to_hat_switch_0(uint8_t up, uint8_t down, uint8_t left, uint8_t right)
{
    uint8_t hat_switch = 0;
    if (up)
    {
        if (right)
            hat_switch = 2; // NE
        else if (left)
            hat_switch = 8; // NW
        else
            hat_switch = 1; // N
    }
    if (right)
    {
        if (up)
            hat_switch = 2; // NE
        else if (down)
            hat_switch = 4; // SE
        else
            hat_switch = 3; // E
    }
    if (down)
    {
        if (right)
            hat_switch = 4; // SE
        else if (left)
            hat_switch = 6; // SW
        else
            hat_switch = 5; // S
    }
    if (left)
    {
        if (up)
            hat_switch = 8; // NW
        else if (down)
            hat_switch = 6; // SW
        else
            hat_switch = 7; // W
    }
    return hat_switch;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right, int pivot_index)
{
    int pivot_value = arr[pivot_index];
    swap(&arr[pivot_index], &arr[right]); // 将基准移到末尾
    int store_index = left;

    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivot_value)
        {
            swap(&arr[store_index], &arr[i]);
            store_index++;
        }
    }
    swap(&arr[right], &arr[store_index]); // 基准归位
    return store_index;
}

// 快速选择
int quickselect(int *arr, int left, int right, int k)
{
    if (left == right)
        return arr[left];

    int pivot_index = left + (rand() % (right - left + 1));
    pivot_index = partition(arr, left, right, pivot_index);

    if (k == pivot_index)
        return arr[k];
    else if (k < pivot_index)
        return quickselect(arr, left, pivot_index - 1, k);
    else
        return quickselect(arr, pivot_index + 1, right, k);
}

// 去极值均值 (data != NULL && sample_count >= 3)
float calculate_trimmed_mean(const int *data, int sample_count)
{
    int sum = data[0];
    int min_val = data[0];
    int max_val = data[0];

    // 1. 累加求和  2. 查找最小值  3. 查找最大值
    for (int i = 1; i < sample_count; ++i)
    {
        sum += data[i];
        min_val = (data[i] < min_val) ? data[i] : min_val;
        max_val = (data[i] > max_val) ? data[i] : max_val;
    }

    // 修正总和并计算均值
    sum = sum - min_val - max_val;
    return (float)sum / (sample_count - 2);
}

// 斜坡归一化
float sramp(float min, float val, float max)
{
    if (val <= min)
        return 0;
    if (val >= max)
        return 1;
    return (val - min) / (max - min);
}
