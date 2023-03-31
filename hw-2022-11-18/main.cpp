/*Реализовать команду shell:

p1 || p2 || ... || pn

Такая команда работает следующим образом:
Запускается процесс, исполняющий программу p1. Родительский процесс ждет завершения p1. Если программа p1 завершилась успешно (через вызов _exit с кодом 0), то цепочка завершается, остальные программы игнорируются. Если p1 не завершилась успешно, то запускается процесс, исполняющий программу p2, отец ждет завершения процесса. И так далее, пока не завершится pn (её завершения тоже нужно дождаться) или пока очередная программа не завершится успешно (через вызов _exit с кодом 0).
Имена программ p1, p2, ..., pn передаются через аргументы командной строки.
Пример 1:

./a.out pwd ls

В результате будет исполнена только программа pwd, которая успешно завершится.
Пример 2:

./a.out false false ls pwd

В результате будет создан процесс с телом программы false, которая завершается с кодом 1, затем еще один процесс с телом false, после чего выведется содержимое текущей директории (процесс ls), после чего программа ./a.out завершится.
 */
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main(int argc, char** argv){
   
      
  int fd1[2];
  int fd2[2];  
      
  if(pipe(fd1) == -1){
    std::cout << "Error" << std::endl;
    }
  if(pipe(fd2) == -1){
    std::cout << "Error" << std::endl;
  } 
        pid_t child_1, child_2;
        (child_1 = fork()) && (child_2 = fork());
        int size = 10;

  if (child_1 == 0) {
     close(fd1[0]);
                int pid_of_child_1 = getpid();
                std::cout << "Pid of child1 is " << pid_of_child_1 << std::endl;
                write(fd1[1], &pid_of_child_1, size);
                close(fd1[1]);

          close(fd2[1]);
                int new_pid_of_child_2 = getpid();
                read(fd2[0], &new_pid_of_child_2, size);
                std::cout << "New Pid of child1 now is " << new_pid_of_child_2 << std::endl;
                close(fd2[0]);
  }  
         else if (child_2 == 0) {

                close(fd2[0]);
                int pid_of_child_2 = getpid();
                std::cout << "Pid of child2 is " << getpid() << std::endl;
                write(fd2[1],&pid_of_child_2, size);
                close(fd2[1]);

                close(fd1[1]);
                int new_pid_of_child_2 = getpid();
                read(fd1[0], &new_pid_of_child_2, size);
                std::cout << "New Pid of child2 now is " << new_pid_of_child_2 << std::endl;
                close(fd1[0]);             
     
  }
  else{
    wait(NULL);
    wait(NULL);
  }  


    }
