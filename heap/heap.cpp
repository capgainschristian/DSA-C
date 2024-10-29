#include <stdio.h>

// Function to insert an element into the max heap
void Insert(int heap[], int* size, int key) {
    int i = *size;
    heap[i] = key;
    (*size)++;

    // Rearrange elements to maintain max heap property
    while (i > 0 && key > heap[(i - 1) / 2]) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = key;
}

// Function to delete the root element (maximum element) from the max heap
void Delete(int heap[], int* size) {
    if (*size == 0) {
        printf("Heap is empty. Nothing to delete.\n");
        return;
    }

    // Replace root with last element
    int lastElement = heap[(*size) - 1];
    heap[0] = lastElement;
    (*size)--;

    // Rearrange elements to maintain max heap property (heapify down)
    int i = 0;
    while (1) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild < *size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < *size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != i) {
            // Swap with the largest child
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest;
        } else {
            break; // No further swaps needed
        }
    }
}

// Function to print the elements of the heap
void PrintHeap(int heap[], int size) {
    printf("Max Heap: [");
    for (int i = 0; i < size; i++) {
        printf("%d", heap[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int heap[15]; // Assuming heap size
    int size = 0;

    // Insert elements into the heap
    Insert(heap, &size, 45);
    Insert(heap, &size, 35);
    Insert(heap, &size, 15);
    Insert(heap, &size, 30);
    Insert(heap, &size, 10);
    Insert(heap, &size, 12);
    Insert(heap, &size, 6);
    Insert(heap, &size, 5);
    Insert(heap, &size, 20);

    PrintHeap(heap, size);

    // Delete the root element
    Delete(heap, &size);
    PrintHeap(heap, size);

    return 0;
}
