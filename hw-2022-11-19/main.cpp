/*"Задача о Бруте":

Напишите программу, в которой родительский процесс порождает дочерний процесс, который должeн убить своего родителя. Проверить может ли дочерний процесс убить своего родителя, если да, то что станет с дочерним процессом.
---
Write a program in which a parent process create a child process that must "kill" its father. Check if the child process can kill its parent process. If so, what will happen to the child process.
 */

#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main(){
  pid_t pid = fork();
  if(pid == -1){
    std::cout << "Error" << std::endl;
  }
  if(pid == 0){
    kill(getppid(), 9);
  }

        else{
    wait(NULL);
  }

}
