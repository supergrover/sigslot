#include <iostream>
using namespace std;

#include "signal.h"

class Emitter: public Object
{
    public:
        Signal<int> the_signal;

        void do_emit(int value)
        {
            the_signal.invoke(value);
        }
};

class Receiver: public Object
{
    public:
        void slot(int v)
        {
            cout << "Yay! " << v << endl;
        }
};

int main(int argc, char* argv[])
{
    Emitter em;
    Receiver recv;

    em.the_signal.bind(&Receiver::slot, &recv);

    em.do_emit(42);

    return EXIT_SUCCESS;
}
