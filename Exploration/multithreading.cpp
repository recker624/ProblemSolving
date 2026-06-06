#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>


std::queue<int> taskQueue;
const unsigned int MAX_BUFFER_SIZE = 5;

std::mutex mtx; //lock
std::condition_variable cv; //the signal


void producer(){
    int value = 0;
    std::cout << "In Producer" << std::endl;
    while(true){
        std::unique_lock<std::mutex> lock(mtx);     //acquire the lock

        // wait if the buffer is full (OS will put the thread to sleep), otherwise the thread will continue to execute as 
        //long as the predicate is true
        cv.wait(lock, [] {return taskQueue.size() < MAX_BUFFER_SIZE; });
        taskQueue.push(value);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Produced: " << value++ << std::endl;

        lock.unlock();  // release lock
        cv.notify_one();    //wakes up a waiting consumer
    }
}

void consumer() {
    std::cout << "In Consumer" << std::endl;
    while(true) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] { return !taskQueue.empty(); });
        int value = taskQueue.front();
        taskQueue.pop();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Consumed : " << value << std::endl;

        lock.unlock();
        cv.notify_one();
    }
}

int main(){
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}

