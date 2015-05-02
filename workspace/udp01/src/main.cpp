#include <iostream>
#include <string>
#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/lockfree/spsc_queue.hpp>
#include <boost/atomic.hpp>

using namespace std;

unsigned int random_number=0;
boost::mutex mutex;

void PrintHello()
{
   cout << "Hello World! Thread ID "<< endl;
}


void AddNumber(){
	while(true){
		mutex.lock();
		random_number++;
		mutex.unlock();
	}

	//random_numbers.push_back("Hello");

}

void GetNumber(){


}

int main(int argc, char* argv[])
{
	boost::thread producer_thread(AddNumber);
	//boost::thread consumer_thread(GetNumber);

	while(true)
	{
			//boost::unique_lock<boost::shared_mutex> lock(mutex);
			mutex.lock();
			cout<<"The number is :"<< to_string(random_number) << endl;
			mutex.unlock();
	}
	return 0;
}
