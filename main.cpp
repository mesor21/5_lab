#include <iostream>
#include <string>
using namespace std;

struct Time{
private:
	int hours, minute, second;
public:
	int time_to_second(){
		return (hours*60*60)+minute*60+second;
	}
	void set_time(int &hours, int &minute, int &second){
		if((hours<24&&hours>=0)&&(second<60&&second>=0)&&(minute<60&&minute>=0)){
			this->hours=hours;
			this->minute=minute;
			this->second=second;
		}
		else{
			cout<<"ERROR"<<endl;
		}
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
	int get_hours()const{
		return hours;
	}
	int get_minute()const{
		return minute;
	}
	int get_second()const{
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
void print(){
	cout<<TimeCall.get_hours()<<":"<<TimeCall.get_minute()<<":"<<TimeCall.get_second()<<endl;
};
int main(){
	Time start_call;
	Time end_call;
	int time_start_call[2];
	int time_end_call[2];
	cout<<"example"<<endl;
	cout<<"12:12:12"<<endl;
	string call_start;
	cout<<"Начало звонка"<<endl;
	cin>>call_start;
	time_start_call[0]=((call_start[0]-'0')*10)+call_start[1]-'0';
	time_start_call[1]=((call_start[3]-'0')*10)+call_start[4]-'0';
	time_start_call[2]=((call_start[6]-'0')*10)+call_start[7]-'0';
	cout<<"Конец звонка"<<endl;
	string call_end;
	cin>>call_end;
	time_end_call[0]=((call_end[0]-'0')*10)+(call_end[1]-'0');
	time_end_call[1]=((call_end[3]-'0')*10)+(call_end[4]-'0');
	time_end_call[2]=((call_end[6]-'0')*10)+(call_end[7]-'0');
	start_call.set_time(time_start_call[0],time_start_call[1],time_start_call[2]);
	end_call.set_time(time_end_call[0],time_end_call[1],time_end_call[2]);
	timeOfCall(start_call, end_call);
	print();
}