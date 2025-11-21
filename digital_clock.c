#include <stdio.h>
#include <string.h>
#include <time.h>
// unistd.h is not available in Windows
#ifdef _WIN32
#include <windows.h> // Sleep()
#else
#include <unistd.h> // sleep()
#endif

// Defining different functions for different OS
#ifdef _WIN32
#define SLEEP(number) Sleep(number * 1000) // Sleep is in milliseconds on Windows
#define LOCALTIME(timeinfo, rawtime) localtime_s(&timeinfo, &rawtime)
#else
#define SLEEP(number) sleep(number) // sleep in seconds on Unix-based systems
#define LOCALTIME(timeinfo, rawtime)          \
	{                                         \
		struct tm *tmp = localtime(&rawtime); \
		timeinfo = *tmp;                      \
	} // Dereference and assign in Unix
#endif

// ----------------------------
// Declarations
// ----------------------------

// define Time struct
typedef struct
{
	int hour;	// 0-23 hours in day
	int minute; // 0-59 minutes in hour
	int second; // 0-59 seconds in minute
} Time;

// Offset for 5 hour 30 minutes for UTC to IST conversion
Time offset = {5, 30, 0};

// forward declaration for functions
void time_formatted(int toggle, Time current_time);
void move_time(Time *current_time);
void print_help();
void print_version(char *str);

// ----------------------------
// Handling Time
// ----------------------------

// Handle the time format toggle (12-hour vs 24-hour)
void time_formatted(int toggle, Time current_time)
{
	// Offsetting time
	current_time.minute += offset.minute;
	if (current_time.minute > 60)
	{
		current_time.minute %= 60;
		current_time.hour++;
		current_time.hour += offset.hour;
		if (current_time.hour > 24)
			current_time.hour %= 24;
	}
	else
	{

		current_time.hour += offset.hour;
		if (current_time.hour > 24)
			current_time.hour %= 24;
	}
	// Clear the current line and move the cursor to the start
	printf("\r"); // This move the cursor back to the beginning of the line

	if (toggle == 1) // 24-hour format
	{
		printf("%02d:%02d:%02d",
			   current_time.hour,
			   current_time.minute,
			   current_time.second);
	}
	else if (toggle == 0) // 12-hour format
	{
		int display_hour = current_time.hour % 12;
		if (display_hour == 0)
			display_hour = 12; // Correct for midnight and noon
		char *period = (current_time.hour >= 12) ? "PM" : "AM";
		printf("%02d:%02d:%02d %s",
			   display_hour,
			   current_time.minute,
			   current_time.second,
			   period);
	}

	// Flush the output buffer to ensure immediate printing
	fflush(stdout);
}

void move_time(Time *current_time)
{
	// Placeholder for manual time adjustment
	// This can be implemented to allow the user to adjust the time
	// For now, it just increments the time by 1 second
	current_time->second++;

	if (current_time->second >= 60)
	{
		current_time->second = 0;
		current_time->minute++;

		if (current_time->minute >= 60)
		{
			current_time->minute = 0;
			current_time->hour++;

			if (current_time->hour >= 24)
			{
				current_time->hour = 0;
			}
		}
	}
}

// ----------------------------
// Print and Main Functions
// ----------------------------

void print_help()
{
	// printf(" -a --alarm		set alarm\n");
	printf(" -h --help		list all options\n");
	printf(" -m --move		move clock (for time adjustment)\n");
	printf(" -s --silent		silent/ suppress the welcome banner\n");
	printf(" -t --toggle		toggle between 12/24-hour format\n");
	printf(" -v --version		prints version\n");
}

void print_version(char *str)
{
	printf("%s: 1.0.0", str);
}

int main(int argc, char *argv[])
{
	int silent = 0;
	int toggle = 0; // default 0 for 12-hour and 1 for 24-hour format

	// Handle command-line arguments
	if (argc > 1)
	{
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
		{
			print_help(); // print the help command
			return 0;	  // Exit after printing help
		}
		// else if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "--move") == 0)
		//	move_time();
		else if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--silent") == 0)
			silent = 1; // Suppress the welcome message
		else if (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--toggle") == 0)
			toggle = 1; // Toggle between 12/24-hour format
		else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
		{
			print_version(argv[1]); // print program version
			return 0;				// Exit after printing version
		}
	}

	// If not silent, print the welcome message
	if (!silent)
		printf("Welcome to command line digital clock...(Press Ctrl+C to escape)\n");

	// Get the current system time
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	LOCALTIME(timeinfo, rawtime);
	// Initialize Time struct from system time
	Time current_time = {
		timeinfo.tm_hour,
		timeinfo.tm_min,
		timeinfo.tm_sec};

	// Main loop to update time
	while (1)
	{
		// Print the formatted time
		time_formatted(toggle, current_time);

		// Move the time forward by 1 second
		move_time(&current_time);

		// Sleep for 1 second before updating again
		SLEEP(1);
	}

	return 0;
}
