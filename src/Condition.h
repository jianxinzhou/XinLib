#ifndef CONDITION_H
#define CONDITION_H 

#include "NonCopyable.h"
#include <pthread.h>

class MutexLock;

class Condition : NonCopyable
{
    public:
        Condition(MutexLock &mutex);
        ~Condition();

        void wait();
        void notify();
        void notifyAll();

    private:
        pthread_cond_t cond_;
        MutexLock &mutex_;
};


#endif  /*CONDITION_H*/
