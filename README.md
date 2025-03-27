# 🔗 Philosophers - Dining Philosophers Problem

### 📝 Overview
Philosophers is a 42 project that simulates the Dining Philosophers Problem, a classic synchronization challenge in computer science. The goal is to manage multiple philosophers who think, eat, and avoid starvation while sharing limited resources (forks) without causing deadlocks.

#### This project focuses on multi-threading, mutexes, and concurrency using C and pthreads.

### 🧠 Understanding the Problem :
    Philosophers sit around a circular table, each with a fork on their left and right. However, they can only eat when they have both forks.  
    The challenge is to implement an algorithm that ensures:
      ✅ No deadlock (all philosophers waiting forever)
      ✅ No starvation (every philosopher gets to eat)
### ⚙️ How It Works :
    ./philo number_of_philos time_to_die time_to_eat time_to_sleep [number_of_times_each_philo_must_eat]
    number_of_philos → Total philosophers

    time_to_die → Time (ms) before a philosopher dies if they don’t eat 
    time_to_eat → Time (ms) they take to eat 
    time_to_sleep → Time (ms) they rest after eating 
    [optional] number_of_times_each_philo_must_eat → If provided, the simulation stops when all philosophers have eaten this many times 

### 🔁 Process Flow :
    1️⃣ Philosophers think 🤔  
    2️⃣ They pick up forks 🍴 (handled using mutexes)  
    3️⃣ They eat 🍝 (time tracked)  
    4️⃣ They put down forks & sleep 😴  
    5️⃣ Repeat until a philosopher dies or the required meals are completed  

### 🔄 Synchronization Techniques :
    Threads (pthread_create) → Each philosopher runs in a separate thread
    Mutexes (pthread_mutex_lock/unlock) → Used to control access to forks
    Time Management (gettimeofday) → Ensures accurate execution timing

### 🛠️ Features :
    ✅ Handles multiple philosophers
    ✅ Prevents deadlocks using mutexes
    ✅ Ensures fair resource allocation
    ✅ Supports an optional meal limit
    ✅ Implements precise time tracking

### 📌 Example Run :
    ./philo 5 800 200 200
    Expected Behavior:
    Philosophers start thinking 🤔
    They pick up forks 🍴 and eat 🍝
    They release forks and sleep 😴
    If a philosopher doesn’t eat within time_to_die, they die 💀

