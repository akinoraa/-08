#include <iostream>

using namespace std;

class Stack
{
    int* ar; 
    int index;  
    int size; 

public:
   
    Stack(int maxSize)
    {
        size = maxSize;
        ar = new int[size];
        index = -1;
    }

    ~Stack()
    {
        delete[] ar; 
    }

    void Clear()
    {
        index = -1;
    }

    bool IsEmpty() const
    {
        return index == -1;
    }

    bool IsFull() const
    {
        return index == size - 1;
    }

    int GetCount() const
    {
        return index + 1;
    }

    void Push(int value)
    {
        if (!IsFull())
        {
            ar[++index] = value;
        }
        else
        {
            throw "Stack overflow!";
        }
    }

    int Pop()
    {
        if (!IsEmpty())
        {
            return ar[index--];
        }
        else
        {
            throw "Stack is empty!";
        }
    }

    int Peek() const
    {
        if (!IsEmpty())
        {
            return ar[index];
        }
        else
        {
            throw "Error";
        }
    }

    bool Contains(int value) const
    {
        for (int i = 0; i <= index; ++i)
        {
            if (ar[i] == value)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Stack st(10); // розмір динамічного масиву 10

    // до тих пір, поки стек не заповниться
    while (!st.IsFull())
        st.Push(rand() % 90 + 10); // додаємо елемент на вершину стека

    // до тих пір, поки в стеку є значення
    while (!st.IsEmpty())
        cout << st.Pop() << "  "; // вилучити значення і показати на екрані

    if (st.Contains(5) == true)
    {
        cout << "True\n";
    }

    return 0;
}
