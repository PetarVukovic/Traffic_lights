
#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

struct Traff_Lights
{
	enum TRAFFIC_LIGHTS
	{
		red,
		redyellow,
		yellow,
		green,
		doesnt_work

	};

	const int red_time = 7;
	const int red_yellow_time = 2;
	const int green_time = 5;
	const int yellow_time = 3;
	const int doesnt_work_time = 2;
	int remaining_state_duration = doesnt_work_time;

	TRAFFIC_LIGHTS lights_state(TRAFFIC_LIGHTS initial_state)
	{

		TRAFFIC_LIGHTS next_light_state;

		switch (initial_state)
		{
		case red:
			next_light_state = redyellow;
			remaining_state_duration = red_yellow_time;
			break;
		case redyellow:
			next_light_state = green;
			remaining_state_duration = green_time;
			break;
		case yellow:
			next_light_state = red;
			remaining_state_duration = red_time;
			break;
		case green:
			next_light_state = yellow;
			remaining_state_duration = yellow_time;
			break;
		case doesnt_work:
			next_light_state = red;
			remaining_state_duration = red_time;
			break;

		}
		return next_light_state;
	}

	void state(TRAFFIC_LIGHTS light)
	{
		system("cls");
		switch (light)
		{
		case red:
			std::cout << "X . .";

			remaining_state_duration--;
			break;
		case redyellow:
			std::cout << "X X .";

			remaining_state_duration--;
			break;
		case yellow:
			std::cout << ". X . ";

			remaining_state_duration--;
			break;
		case green:
			std::cout << ". . X";

			remaining_state_duration--;
			break;
		case doesnt_work:
			std::cout << "???";

			remaining_state_duration--;
			break;
		default:
			break;
		}
		std::cout << "-" << remaining_state_duration << std::endl;
		std::this_thread::sleep_for(1s);
	}
};

int main()
{
	Traff_Lights TF;
	auto initial_light =TF.doesnt_work;
	
	while(1)
	{
		
		TF.state(initial_light);
		if(TF.remaining_state_duration<1)
			initial_light = TF.lights_state(initial_light);

	}
	
	return 0;
}
