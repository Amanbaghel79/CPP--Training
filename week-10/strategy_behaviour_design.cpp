// Strategy Pattern is a behavioral design pattern that defines a family of interchangeable 
// algorithms and allows them to be used interchangeably within a context. This pattern 
// enables the algorithm to be selected at runtime, providing flexibility and promoting code 
// reusability.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Strategy Interface
class SortStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~SortStrategy() = default;
};

// Concrete Strategy: Bubble Sort
class BubbleSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Using Bubble Sort\n";
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data.size() - i - 1; ++j) {
                if (data[j] > data[j+1]) {
                    std::swap(data[j], data[j+1]);
                }
            }
        }
    }
};

// Concrete Strategy: Standard Sort (quick sort underneath)
class QuickSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Using Quick Sort\n";
        std::sort(data.begin(), data.end());
    }
};

// Context
class SortContext {
private:
    SortStrategy* strategy;  // Pointer to the strategy
public:
    SortContext(SortStrategy* strat) : strategy(strat) {}
    
    void setStrategy(SortStrategy* strat) {
        strategy = strat;
    }

    void executeStrategy(std::vector<int>& data) {
        strategy->sort(data);
    }
};

int main() {
    std::vector<int> data = {5, 2, 9, 1, 5, 6};
    BubbleSort bubble_sort;
    QuickSort quick_sort;
    SortContext obj(&bubble_sort);
    obj.setStrategy(&quick_sort);
    obj.executeStrategy(data);
     for (int num : data) std::cout << num << " ";
    std::cout << "\n";
}  