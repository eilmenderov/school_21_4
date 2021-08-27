-Philosophers-

In this project, you will learn the basics of threading a process.
You willlearn how to make threads. You will discover the mutex.


How to use:

make re && make clean && ./philo 2 1010 500 450 2

for bonus:

make re && make clean && ./philo_bonus 2 1010 500 450 2

ARGs:
- number_of_philosophers
- time_to_die
- time_to_eat
- time_to_sleep
- [number_of_times_each_philosopher_must_eat]

You are allowed to use the following functions:

-- usleep -- (засыпает на заданное количество микросекунд)
https://www.opennet.ru/man.shtml?topic=usleep&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- gettimeofday -- (определяет время  #include <sys/time.h>)
https://www.opennet.ru/man.shtml?topic=gettimeofday&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- pthread_create -- (#include <pthread.h>)
https://www.opennet.ru/man.shtml?topic=pthread_create&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- pthread_detach -- (#include <pthread.h>)
https://www.opennet.ru/man.shtml?topic=pthread_detach&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- pthread_join -- (#include <pthread.h>)
https://www.opennet.ru/man.shtml?topic=pthread_join&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- pthread_mutex_init -- (#include <pthread.h>)
https://www.opennet.ru/man.shtml?topic=pthread_mutex_init&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- pthread_mutex_destroy -- (#include <pthread.h>)
https://www.opennet.ru/man.shtml?topic=pthread_mutex_destroy&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- pthread_mutex_lock -- (#include <pthread.h>)
https://www.opennet.ru/man.shtml?topic=pthread_mutex_lock&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- pthread_mutex_unlock -- (#include <pthread.h>)
https://www.opennet.ru/man.shtml?topic=pthread_mutex_unlock&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- memset -- (#include <string.h>)
https://www.opennet.ru/man.shtml?topic=memset&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- printf -- (#include <stdio.h>)
https://www.opennet.ru/man.shtml?topic=printf&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

-- write --
https://www.opennet.ru/man.shtml?topic=write&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/write-rtlwrite

-- malloc --
https://www.opennet.ru/man.shtml?topic=malloc&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://www.c-cpp.ru/content/write-rtlwrite

-- free --
http://www.c-cpp.ru/content/free


Обязательная часть

Вам придется написать одну программу для обязательной части и одну для бонусной части, но они будут иметь одинаковые основные правила:
- Этот проект должен быть написан на C, следуя нормам. Любая утечка, сбой, неопределенное поведение или ошибка нормы означает 0 баллов для проекта.
- Один или несколько философов сидят за круглым столом и занимаются одним из трех дел: едят, думают или спят.
- Во время еды они не думают и не спят, во время сна они не едят и не думают, и, конечно, во время размышлений они не едят и не спят.
- Философы сидят за круглым столом с большой миской спагетти в центре.
- На столе лежит несколько вилок.
- Поскольку спагетти трудно подавать и есть одной вилкой, предполагается, что философ должен есть двумя вилками, по одной в каждой руке.
- Философы никогда не должны голодать.
- Каждый философ должен есть.
- Философы не разговаривают друг с другом.
- Философы не знают, когда другой философ собирается умереть.
- Каждый раз, когда философ заканчивает есть, он бросает вилку и начинает спать.
- Когда философ закончит спать, он начнет думать.
- Симуляция останавливается, когда философ умирает.
- Каждая программа должна иметь одинаковые опции: number_of_philosophers time_to_dietime_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
  ◦ number_of_philosophers: количество философов, а также количество вилок
  ◦ time_to_die: указывается в миллисекундах, если философ не начнет есть через "time_to_die" миллисекунд после начала последнего приема пищи или начала симуляции, он умрет
  ◦ time_to_eat: выражается в миллисекундах и представляет собой время, необходимое философу, чтобы поесть. В течение этого времени ему нужно будет держать две вилки.
  ◦ time_to_sleep: выражается в миллисекундах и представляет собой время, которое философ потратит на сон.
  ◦ number_of_times_each_philosopher_must_eat: аргумент необязательный, если все философы съедят не менее 'number_of_times_each_philosopher_must_eat', симуляция будет остановлена. Если аргумент не указан, симуляция остановится только при смерти философа.
- Каждому философу должен быть присвоен номер от 1 до 'number_of_philosophers'.
- Философ с номером 1 находится рядом с философом с номером 'number_of_philosophers'. Любой другой философ с номером N сидит между философом N - 1 и философом N + 1.
- Любое изменение статуса философа должно быть записано следующим образом (при этом X заменяется номером философа, а timestamp_in_ms - текущей временной меткой в миллисекундах)
  ◦ timestamp_in_ms X взял вилку
  ◦ timestamp_in_ms X ест
  ◦ timestamp_in_ms X спит
  ◦ timestamp_in_ms X думает
  ◦ timestamp_in_ms X умер
- Напечатанный статус не должен быть скремблирован или переплетен со статусом другого философа.
- Не может быть более 10 мс между смертью философа и моментом, когда он напечатает свою смерть.
- Однако, философы должны избегать смерти!
- Одна вилка между каждым философом, поэтому если философов несколько, то справа и слева от каждого философа будет по вилке.
- Чтобы избежать дублирования форков философами, вы должны защитить состояние форков с помощью мьютекса для каждого из них.
- Каждый философ должен быть потоком.

Бонусная часть

В этой версии специфические правила таковы:
- Все вилки находятся в середине таблицы.
- У них нет состояний в памяти, но количество доступных вилок представлено семафором.
- Каждый философ должен быть процессом, а главный процесс не должен быть философом.


BONUS

You are allowed to use the following functions:
memset
printf
malloc
free
write
exit
pthread_create
pthread_detach
pthread_join
usleep
gettimeofday
waitpid
fork
kill
sem_open
sem_close
sem_post
sem_wait
sem_unlink

-- waitpid -- (ожидает завершения процесса  #include <sys/wait.h>)
https://www.opennet.ru/man.shtml?topic=waitpid&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://ru.manpages.org/waitpid/2

-- fork -- (создает дочерний процесс #include <unistd.h>)
https://www.opennet.ru/man.shtml?topic=fork&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man
http://ru.manpages.org/fork/2

-- kill -- (send a signal to a process or a group of processes #include <signal.h> )
https://www.opennet.ru/man.shtml?topic=kill&category=3&russian=5

-- sem_open -- (initialize/open a named semaphore #include <semaphore.h>)
http://ru.manpages.org/sem_open/3

-- sem_close -- (close a named semaphore #include <semaphore.h>)
http://ru.manpages.org/sem_close/3

-- sem_post -- (increment the count of a semaphore #include <semaphore.h>)
http://ru.manpages.org/sem_post/3

-- sem_wait -- (acquire or wait for a semaphore  #include <semaphore.h>)
http://ru.manpages.org/sem_wait/3

-- sem_unlink -- (remove a named semaphore #include <semaphore.h>)
http://ru.manpages.org/sem_unlink/3
