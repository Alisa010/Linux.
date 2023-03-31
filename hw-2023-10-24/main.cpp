/*Написать программу, реализующую следующее поведение shell:
pr arg1 arg2 ...
echo Finish
То есть реализовать запуск на исполнение программы pr с аргументами arg1, arg2  и так далее (количество аргументов не фиксировано), ожидание завершения pr и печать строки Finish.
Имя программы и её аргументы (pr и arg1, arg2 и т.д.) передаются вашей программе как аргументы командной строки.
Печать строки Finish реализовать с помощью printf.
Пример:
./a.out cat file1 file2
Такой запуск вашей программы должен породить сына, который заменит своё тело програмой cat с аргументами file1 и file2 (здесь тоже должна использоваться PATH). cat выведет содержимое файлов file1 и file2, завершится. Ваш отцовский процесс дожидается завершения cat и печатает Finish. Не забывайте про символ конца строки в конце. */
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char** argv){

   for(int i = 1; i < argc; ++i){  
  pid_t pid = fork();
  char* arr[] = {argv[i], nullptr};
  if(pid == -1){ 
    exit(1);
  }
  if(pid == 0){
    execvp(argv[i], arr);
    
  }

  if(pid > 0){
    int wait_status;
    wait(&wait_status);
    if(WIFEXITED(wait_status)){
      if(WEXITSTATUS(wait_status) == 0){
        break;
      }
     
    }
  }
  }
}
