#include <iostream>
#include <string>
using namespace std;

enum ERROR{fail_time};
struct Time{
private:
	int hours, minute, second;
public:
	Time(){};
	Time(int &hours, int &minute, int &second){
		this->hours=hours;
		this->minute=minute;
		this->second=second;
	}
	int time_to_second(){
		return (hours*60*60)+minute*60+second;
	}
	void set_time(int hours, int minute, int second){
		this->hours=hours;
		this->minute=minute;
		this->second=second;
	}
	void set_hours(int hours){
		this->hours=hours;
	}
	void set_minute(int minute){
		this->minute=minute;
	}
	void set_second(int second){
		this->second=second;
	}
	int get_hours(){
		return hours;
	}
	int get_minute(){
		return minute;
	}
	int get_second(){
		return second;
	}
};

Time TimeCall;
void timeOfCall(Time &start_call, Time &end_call){
	int call_second = end_call.time_to_second()-start_call.time_to_second();
	TimeCall.set_hours(call_second/3600);
	call_second = call_second%3600;
	TimeCall.set_minute(call_second/60);
	TimeCall.set_second(call_second%60);
};

int main(){
	int time_start_call[]={12,23,54};
	int time_end_call[]={12,32,32};
	Time start_call(time_start_call[0],time_start_call[1],time_start_call[2]);
	Time end_call(time_end_call[0],time_end_call[1],time_end_call[2]);
	timeOfCall(start_call, end_call);
	cout<<TimeCall.get_hours()<<":"<<TimeCall.get_minute()<<":"<<TimeCall.get_second()<<endl;
}