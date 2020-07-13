#include <iostream>

using namespace std;

template <class T>
class IStack
{
    virtual bool IsEmpty();

    virtual T Peek();

    virtual IStack<T> Push(T value);

    virtual IStack<T> Pop();

    virtual void PrintStack();
};

template <class T>
class ImmutableStack : public IStack<T>
{

    class EmptyStack : IStack<T>
    {
        bool IsEmpty()
        {
            return true;
        }

        T Peek()
        {
            cout << "Empty Stack\n";
        }

        IStack<T> Push(T value)
        {
            return new ImmutableStack<T>(value, this);
        }

        IStack<T> Pop()
        {
            cout << "Empty Stack\n";
        }

        void PrintStack()
        {
            cout << "Empty Stack\n";
        }
    };

private:
    T head;
    IStack<T> tail;
    ImmutableStack(T head, IStack<T> tail)
    {
        this->head = head;
        this->tail = tail;
    }

public:
    static IStack<T> Empty = new EmptyStack();

    bool IsEmpty()
    {
        return false;
    }

    T Peek()
    {
        return head;
    }

    IStack<T> Push(T value)
    {
        return new ImmutableStack<T>(value, this);
    }

    IStack<T> Pop()
    {
        return tail;
    }

    void PrintStack()
    {
        for (ImmutableStack<T> stack = this; !stack.IsEmpty(); stack = stack.Pop())
            cout << stack.Peek << endl;
    }
};

int main()
{
    ImmutableStack<int> s1 = ImmutableStack<int>::Empty;

    return 0;
}