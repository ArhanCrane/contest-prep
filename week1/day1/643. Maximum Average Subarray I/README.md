643. Maximum Average Subarray I
https://leetcode.com/problems/maximum-average-subarray-i/description/

Статус: Решена за 7 минут

Условие:

Дан массив чисел с размером N. Необходимо найти субстроку размера K, 
в котором сумма элементов в подстроке при делении на число K дает максимальное значение.

Подход: Используется метод скользящего окна (Sliding Window, Fixed-Length)

1. Так как число K <= N, добавляем первые K элементов из массива в переменную addition
2. Инициализируем max_average значением addition / l (среднее для первого окна)
3. Проходим циклом по массиву, начиная с индекса k и до конца (r < n).
4. Сдвигаем окно по формуле addition += nums[r] - nums[r - k], где r - индекс правого края окна.
5. Каждую итерацию, обновляя окно, сравниваем среднее с максимальным значением.

Краевые случаи:

1. По условию количество чисел не выйдет за 10^5, а каждое число в пределах (-10^4 to 10^4), что означает
гарантию, при которой переменная int addition, хранящая числа окна, не выйдет за свои пределы (2*10^9)

2. Число K гарантированно не равно нулю, что оберегает от случайного деления на ноль.

Сложность по скорости: O (N), где N - размер массива
Сложность по памяти: O (1)

Код:

```c++
class Solution {
public:
    //Fixed Size Sliding Window
    double findMaxAverage(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());

        double addition{};
        for (int i{}; i < k; i++) {addition += nums[i];}// k <= n, O (k)

        double max_average{addition / k}; // k != 0
        
        for (int r{k}; r < n; r++) { // O (n)
            addition += nums[r] - nums[r - k];                        
            max_average = std::max(max_average, (addition / k)); // k != 0
        }

        return max_average;
    }
};
```
