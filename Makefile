
daemon: daemon.c
	gcc daemon.c -Wall -o daemon

.PHONY: clean
clean:
	rm log_cpu.log
	rm daemon
