/*Напишите программу, в которой родительский процесс порождает две дочерние процессы, которые должны обменяться своими pid. Обмен должен быть реализован с помощью каналов.
---
Write a program in which a parent process create two child processes that must exchange their pids. The exchange must be implemented using pipes.
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
