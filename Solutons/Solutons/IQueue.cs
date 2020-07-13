using System;
namespace Solutons
{
    public interface IQueue<T>
    {
        bool IsEmpty { get; }
        T Peek();
        IQueue<T> Enqueue(T value);
        IQueue<T> Dequeue();
        void PrintQueue();
    }
}
