<h1>-Philosophers-</h1>

<p>In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex.</p>


How to use:

make re && make clean && ./philo 2 1010 500 450 2

for bonus:

make re && make clean && ./philo_bonus 2 1010 500 450 2

ARGs:
<ul>
    <li>number_of_philosophers</li>
    <li>time_to_die</li>
    <li>time_to_eat</li>
    <li>time_to_sleep</li>
    <li>[number_of_times_each_philosopher_must_eat]</li>
</ul>

<h2>Обязательная часть</h2>

Вам придется написать одну программу для обязательной части и одну для бонусной части, но они будут иметь одинаковые основные правила:
<ul>
    <li> Этот проект должен быть написан на C, следуя нормам. Любая утечка, сбой, неопределенное поведение или ошибка нормы означает 0 баллов для проекта.</li>
    <li> Один или несколько философов сидят за круглым столом и занимаются одним из трех дел: едят, думают или спят.</li>
    <li> Во время еды они не думают и не спят, во время сна они не едят и не думают, и, конечно, во время размышлений они не едят и не спят.</li>
    <li> Философы сидят за круглым столом с большой миской спагетти в центре.</li>
    <li> На столе лежит несколько вилок.</li>
    <li> Поскольку спагетти трудно подавать и есть одной вилкой, предполагается, что философ должен есть двумя вилками, по одной в каждой руке.</li>
    <li> Философы никогда не должны голодать.</li>
    <li> Каждый философ должен есть.</li>
    <li> Философы не разговаривают друг с другом.</li>
    <li> Философы не знают, когда другой философ собирается умереть.</li>
    <li> Каждый раз, когда философ заканчивает есть, он бросает вилку и начинает спать.</li>
    <li> Когда философ закончит спать, он начнет думать.</li>
    <li> Симуляция останавливается, когда философ умирает.</li>
    <li> Каждая программа должна иметь одинаковые опции:</li>
    <ul>
        <li>    number_of_philosophers: количество философов, а также количество вилок</li>
        <li>    time_to_die: указывается в миллисекундах, если философ не начнет есть через "time_to_die" миллисекунд после начала последнего приема пищи или начала симуляции, он умрет</li>
        <li>    time_to_eat: выражается в миллисекундах и представляет собой время, необходимое философу, чтобы поесть. В течение этого времени ему нужно будет держать две вилки.</li>
        <li>    time_to_sleep: выражается в миллисекундах и представляет собой время, которое философ потратит на сон.</li>
        <li>    number_of_times_each_philosopher_must_eat: аргумент необязательный, если все философы съедят не менее 'number_of_times_each_philosopher_must_eat', симуляция будет остановлена. Если аргумент не указан, симуляция остановится только при смерти философа.</li>
    </ul>
    <li> Каждому философу должен быть присвоен номер от 1 до 'number_of_philosophers'.</li>
    <li> Философ с номером 1 находится рядом с философом с номером 'number_of_philosophers'. Любой другой философ с номером N сидит между философом N - 1 и философом N + 1.</li>
    <li> Любое изменение статуса философа должно быть записано следующим образом (при этом X заменяется номером философа, а timestamp_in_ms - текущей временной меткой в миллисекундах)</li>
    <ul>
        <li>timestamp_in_ms X взял вилку</li>
        <li>timestamp_in_ms X ест</li>
        <li>timestamp_in_ms X спит</li>
        <li>timestamp_in_ms X думает</li>
        <li>timestamp_in_ms X умер</li>
    </ul>
    <li> Напечатанный статус не должен быть скремблирован или переплетен со статусом другого философа.</li>
    <li> Не может быть более 10 мс между смертью философа и моментом, когда он напечатает свою смерть.</li>
    <li> Однако, философы должны избегать смерти!</li>
    <li> Одна вилка между каждым философом, поэтому если философов несколько, то справа и слева от каждого философа будет по вилке.</li>
    <li> Чтобы избежать дублирования форков философами, вы должны защитить состояние форков с помощью мьютекса для каждого из них.</li>
    <li> Каждый философ должен быть потоком.</li>
</ul>

Бонусная часть

В этой версии специфические правила таковы:
- Все вилки находятся в середине таблицы.
- У них нет состояний в памяти, но количество доступных вилок представлено семафором.
- Каждый философ должен быть процессом, а главный процесс не должен быть философом.

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
