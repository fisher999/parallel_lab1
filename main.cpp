#include <omp.h>
#include <stdio.h>

int someNumber;

void firstTask() 
{
    printf("First task:\n");
    #pragma omp parallel
    {
        someNumber = omp_get_num_threads();
        printf("Number of threads in parallel %d\n", someNumber);  
    }
    
    printf("Number of threads in main %d\n", someNumber);

    #pragma omp parallel
    {
        someNumber *= omp_get_thread_num();
        printf("Result of multiply %d\n", someNumber);
    }

    printf("Result of multiply in main %d\n", someNumber); 
}

void secondTask()
{
    printf("Second task: \n");
    int anotherNumber;
    
    #pragma omp parallel
    {
        anotherNumber = 3;
        printf("Some number is %d in parallel\n", anotherNumber);  
    }

    printf("Some number is %d in main \n", anotherNumber);

    #pragma omp parallel
    {
        anotherNumber *= omp_get_thread_num();
        printf("Some number is %d in parallel\n", anotherNumber);  
    }

    printf("Some number is %d in main\n", anotherNumber);  
}

int fact(int N)
{
    if(N < 0) 
        return 0;
    if (N == 0)
        return 1; 
    else 
        return N * fact(N - 1); 
}

void thirdTask() 
{
    printf("Third task: \n");

    int anotherNumber;
    int maxThreads = omp_get_max_threads();

    #pragma omp parallel
    {
        anotherNumber = omp_get_thread_num();
        int currentThread = omp_get_thread_num();
        printf("From %d thread some value: %d\n", currentThread, anotherNumber);
        if (currentThread % 2 == 0)
        {
            printf("From %d thread modified value: %d\n", currentThread, anotherNumber + omp_get_num_threads());
        }
        else
        {
            printf("From %d thread factorial: %d\n", currentThread, fact(currentThread));
        }
    }
}

void print_separator() {
    printf("\n-----------------\n");
}

int main() 
{
    firstTask();
    print_separator();
    secondTask();
    print_separator();
    thirdTask();
}
    