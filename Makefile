
ejec: daemon
	./daemon
	chmod 777 log_cpu.log

daemon: daemon.c
	gcc daemon.c -Wall -o daemon

.PHONY: clean
clean:
	rm log_cpu.log
	rm daemon
