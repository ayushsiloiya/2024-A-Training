public class BinaryHeap {
    private int[] heap;
    private int size;
    private static final int DEFAULT_CAPACITY = 10;

    public BinaryHeap() {
        this(DEFAULT_CAPACITY);
    }

    public BinaryHeap(int capacity) {
        heap = new int[capacity];
        size = 0;
    }

    private int parent(int index) {
        return (index - 1) / 2;
    }

    private int leftChild(int index) {
        return 2 * index + 1;
    }

    private int rightChild(int index) {
        return 2 * index + 2;
    }

    private void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    private void ensureCapacity() {
        if (size == heap.length) {
            int[] newHeap = new int[2 * heap.length];
            System.arraycopy(heap, 0, newHeap, 0, heap.length);
            heap = newHeap;
        }
    }

    public void insert(int value) {
        ensureCapacity();
        heap[size] = value;
        siftUp(size);
        size++;
    }

    private void siftUp(int index) {
        while (index > 0 && heap[index] < heap[parent(index)]) {
            swap(index, parent(index));
            index = parent(index);
        }
    }

    public int deleteMin() {
        if (size == 0)
            throw new IllegalStateException("Heap is empty");
        
        int minValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        siftDown(0);
        return minValue;
    }

    private void siftDown(int index) {
        while (leftChild(index) < size) {
            int smallestChild = leftChild(index);
            if (rightChild(index) < size && heap[rightChild(index)] < heap[leftChild(index)]) {
                smallestChild = rightChild(index);
            }

            if (heap[index] < heap[smallestChild]) {
                break;
            }

            swap(index, smallestChild);
            index = smallestChild;
        }
    }

    public int peek() {
        if (size == 0)
            throw new IllegalStateException("Heap is empty");

        return heap[0];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }
}
