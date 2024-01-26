#ifndef Q_H
#define Q_H
template <class T>

class Q
{
    public:
        Q(int = 10);
        ~Q()
        {
            delete[] stackPtr;
        }
        bool push(const T&);
        bool pop(T&);

    private:
        int size;
        int bottom;
        int len;
        T* stackPtr;
        bool isEmpty() const
        {
            return len == 0;
        }

        bool isFull() const
        {
            return len == size;
        }
};

template <class T>
 Q<T>::Q(int s)

{
        size = s > 0 ? s : 10;
        bottom = 0;
        len = 0;
        stackPtr = new T[size];
}

template <class T>
    bool Q<T>::push(const T& pushValue)
{
        if(!isFull())
        {
            stackPtr[(bottom + len)%size] = pushValue;
            len++;
            return true;
        }
        return false;
}


template <class T>
    bool Q<T>::pop(T& popValue)
{
        if(!isEmpty())
        {
            popValue = stackPtr[bottom++];
            len--;
            return true;
        }
        return false;
}
#endif

