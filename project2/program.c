#include <stdio.h>
#include <time.h>

/* Function: writes logs to a file*/
void write_log(const char *filename, const char *level, const char *message)
{
	FILE *file = fopen(filename, "a");
	if (!file) return;

	// get timestamp
	time_t now = time(NULL);
	char timestamp[20];

	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

	// write log entry
	fprintf(file, "[%s] [%s] %s\n", timestamp, level, message);

	fclose(file);
}

/* Function: reads logs from a file and displays them on the screen */
void read_logs(const char *filename)
{
	FILE *file = fopen(filename, "r");
	if (!file) return;

	// read logline
	char log[256];
	while(fgets(log, sizeof(log), file) != NULL)
	{
		printf("%s", log);
	}

	fclose(file);
}

/* Program's main entry point*/
int main()
{
	write_log("app.log", "INFO", "Application started");
	write_log("app.log", "WARNING", "Low memory detected");
	write_log("app.log", "ERROR", "Failed to connect to database");

	//reading log from file
	printf("Logs: \n");
	read_logs("app.log");

	return 0;
}
