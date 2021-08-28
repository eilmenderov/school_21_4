<h1>-Philosophers-</h1>

<p>In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex.</p>


<h3>How to use:</h3>

<p>make re && make clean && ./philo 2 1010 500 450 2</p>

<h3>for bonus:</h3>

<p>make re && make clean && ./philo_bonus 2 1010 500 450 2</p>

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
    <li> Каждая программа должна иметь одинаковые опции:
    <ul>
        <li>    number_of_philosophers: количество философов, а также количество вилок</li>
        <li>    time_to_die: указывается в миллисекундах, если философ не начнет есть через "time_to_die" миллисекунд после начала последнего приема пищи или начала симуляции, он умрет</li>
        <li>    time_to_eat: выражается в миллисекундах и представляет собой время, необходимое философу, чтобы поесть. В течение этого времени ему нужно будет держать две вилки.</li>
        <li>    time_to_sleep: выражается в миллисекундах и представляет собой время, которое философ потратит на сон.</li>
        <li>    number_of_times_each_philosopher_must_eat: аргумент необязательный, если все философы съедят не менее 'number_of_times_each_philosopher_must_eat', симуляция будет остановлена. Если аргумент не указан, симуляция остановится только при смерти философа.</li>
    </ul>
	</li>
    <li> Каждому философу должен быть присвоен номер от 1 до 'number_of_philosophers'.</li>
    <li> Философ с номером 1 находится рядом с философом с номером 'number_of_philosophers'. Любой другой философ с номером N сидит между философом N - 1 и философом N + 1.</li>
    <li> Любое изменение статуса философа должно быть записано следующим образом (при этом X заменяется номером философа, а timestamp_in_ms - текущей временной меткой в миллисекундах)
    <ul>
        <li>timestamp_in_ms X взял вилку</li>
        <li>timestamp_in_ms X ест</li>
        <li>timestamp_in_ms X спит</li>
        <li>timestamp_in_ms X думает</li>
        <li>timestamp_in_ms X умер</li>
    </ul>
	</li>
    <li> Напечатанный статус не должен быть скремблирован или переплетен со статусом другого философа.</li>
    <li> Не может быть более 10 мс между смертью философа и моментом, когда он напечатает свою смерть.</li>
    <li> Однако, философы должны избегать смерти!</li>
    <li> Одна вилка между каждым философом, поэтому если философов несколько, то справа и слева от каждого философа будет по вилке.</li>
    <li> Чтобы избежать дублирования форков философами, вы должны защитить состояние форков с помощью мьютекса для каждого из них.</li>
    <li> Каждый философ должен быть потоком.</li>
</ul>

<h3>You are allowed to use the following functions:</h3>

<a href="https://www.opennet.ru/man.shtml?topic=usleep&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- usleep -- (засыпает на заданное количество микросекунд)</a>

<a href="https://www.opennet.ru/man.shtml?topic=gettimeofday&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- gettimeofday -- (определяет время  #include <sys/time.h>)</a>
<a href="https://www.opennet.ru/man.shtml?topic=pthread_create&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- pthread_create -- (#include <pthread.h>)</a>
<a href="https://www.opennet.ru/man.shtml?topic=pthread_detach&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- pthread_detach -- (#include <pthread.h>)</a>
<a href="https://www.opennet.ru/man.shtml?topic=pthread_join&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- pthread_join -- (#include <pthread.h>)</a>
<a href="https://www.opennet.ru/man.shtml?topic=pthread_mutex_init&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- pthread_mutex_init -- (#include <pthread.h>)</a>
<a href="https://www.opennet.ru/man.shtml?topic=pthread_mutex_destroy&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- pthread_mutex_destroy -- (#include <pthread.h>)</a>
<a href="https://www.opennet.ru/man.shtml?topic=pthread_mutex_lock&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- pthread_mutex_lock -- (#include <pthread.h>)</a>
<a href="https://www.opennet.ru/man.shtml?topic=pthread_mutex_unlock&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- pthread_mutex_unlock -- (#include <pthread.h>)</a>
<a href="https://www.opennet.ru/man.shtml?topic=memset&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- memset -- (#include <string.h>)</a>
<a href="https://www.opennet.ru/man.shtml?topic=printf&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- printf -- (#include <stdio.h>)</a>
<a href="http://www.c-cpp.ru/content/write-rtlwrite">-- write --</a>
<a href="https://www.opennet.ru/man.shtml?topic=malloc&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man">-- malloc --</a>
<a href="http://www.c-cpp.ru/content/free">-- free --</a>

<h2>BONUS</h2>

<h3>В этой версии специфические правила таковы:</h3>
<ul>
    <li>Все вилки находятся в середине таблицы.</li>
    <li>них нет состояний в памяти, но количество доступных вилок представлено семафором.</li>
    <li>Каждый философ должен быть процессом, а главный процесс не должен быть философом.</li>
</ul>

<h3>You are allowed to use the following functions:</h3>
<ul>
    <li>memset</li>
    <li>printf</li>
    <li>malloc</li>
    <li>free</li>
    <li>write</li>
    <li>exit</li>
    <li>pthread_create</li>
    <li>pthread_detach</li>
    <li>pthread_join</li>
    <li>usleep</li>
    <li>gettimeofday</li>
    <li>waitpid</li>
    <li>fork</li>
    <li>kill</li>
    <li>sem_open</li>
    <li>sem_close</li>
    <li>sem_post</li>
    <li>sem_wait</li>
    <li>sem_unlink</li>
</ul>

<a href="http://ru.manpages.org/waitpid/2">-- waitpid -- (ожидает завершения процесса  #include <sys/wait.h>)</a>
<a href="http://ru.manpages.org/fork/2">-- fork -- (создает дочерний процесс #include <unistd.h>)</a>
<a href="https://www.opennet.ru/man.shtml?topic=kill&category=3&russian=5">-- kill -- (send a signal to a process or a group of processes #include <signal.h>)</a>
<a href="http://ru.manpages.org/sem_open/3">-- sem_open -- (initialize/open a named semaphore #include <semaphore.h>)</a>
<a href="http://ru.manpages.org/sem_close/3">-- sem_close -- (close a named semaphore #include <semaphore.h>)</a>
<a href="http://ru.manpages.org/sem_post/3">-- sem_post -- (increment the count of a semaphore #include <semaphore.h>)</a>
<a href="http://ru.manpages.org/sem_wait/3">-- sem_wait -- (acquire or wait for a semaphore  #include <semaphore.h>)</a>
<a href="http://ru.manpages.org/sem_unlink/3">-- sem_unlink -- (remove a named semaphore #include <semaphore.h>)</a>
