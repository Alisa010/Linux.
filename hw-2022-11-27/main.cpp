/*Напишите программу, которая получает извне число N (N > 1 000 000), создает массив размера N и заполняет его случайными целыми числами.
После этого программа должна вычислить сумму массива следующим образом:
- Получить извне другое число M, которое было бы количеством параллельных рабочих для вычисления суммы
- Каждый параллельный рабочий является дочерним процессом. Каждый процесс должен принимать два индекса i и j, вычислять промежуточную сумму массива от i до j и возвращать вычисленное число родительскому процессу.
- Каждый дочерний процесс должен также печатать значение промежуточной суммы (часть суммы, которую он вычислил).
- Все М-процессы должны работать параллельно и родитель должен ждать их всех
- После того, как все дочерние процессы завершили вычисления, родительский процесс должен получить все значения промежуточных сумм и вычислить окончательную сумму, а затем распечатать общую сумму.

Требование: Связь родителей и детей должна быть реализована с помощью каналов. Коммуникация включает в себя отправку начального и конечного индексов от родителя к дочернему элементу, а также отправку промежуточного итога от дочернего элемента к родительскому.
---
Write a program that gets from outside a number N (N > 1 000 000), creates an array of size N and fills it with random integer numbers.
After that program should calculate the sum of array this way:
- Get from outside another number M that would be the number of parallel workers to calculate the sum
- Every parallel worker is a child process. Each process should take two indexes i and j, calculate sub-total sum of array from i to j and return the calculated number to parent.
- Every child process should also print the sub-total value (part of sum it calculated).
- All M processes should work in parallel and parent should wait them all
- After all the child processes completed calculation, the parent process should get all the sub-total values and calculate the final sum, and then, print the total summary.

Requirement: Parent and child communication should be implemented with pipes. Communication includes sending start and end index from parent to child as well as sending sub total from child to parent. */
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char** argv){

       	int n = atoi(argv[1]);
        int arr[n];
	srand(time(NULL));
        for(int i = 0; i < n; ++i){
                arr[i] = rand() % 5;
        }
        for(int i = 0; i < n; ++i){
                std::cout << arr[i] << " ";
        }

	std::cout << std::endl;

        int m = atoi(argv[2]);

        pid_t childs;
        int pipe1[2];
	int pipe2[2];
	int pipe3[2];

	pipe(pipe1);
        for(int i = 0; i < m; ++i){
                childs = fork();
                if(childs == -1){
                        std::cout << "Error" << std::endl;
                }

                else if(childs == 0){
			close(pipe1[0]);
			int j;
			close(pipe2[1]);
			read(pipe2[0], &i, sizeof(int));
			close(pipe3[1]);
			read(pipe3[0], &j, sizeof(int));

			int sum = 0;
                        for( j = i * n / m; j < (i + 1) * n / m; j++){
                                sum += arr[j];
                        }
                        std::cout << "The sum of " << i + 1 << "th range is " << sum << std::endl;

                        if (write(pipe1[1], &sum, sizeof(int)) == -1) {
                                std::cout << "Error at writing\n";
                        }

                        close(pipe1[1]);
			exit(0);
                        }
		}
			close(pipe2[0]);
			int i;
			write(pipe2[1], &i, sizeof(int));
			close(pipe2[1]);
			int j;
			close(pipe3[0]);
			write(pipe3[1], &j, sizeof(int));
			close(pipe3[1]);

			close(pipe1[1]);
			int result_sum = 0;
                        for(int i = 0 ; i < m ; ++i){
                                wait(NULL);
        	                int sum;
	                        read(pipe1[0], &sum, sizeof(int));
				result_sum += sum;
                        }
			std::cout << "The result sum is " << result_sum;

}
