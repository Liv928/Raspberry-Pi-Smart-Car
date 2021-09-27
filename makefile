all:part1 part2 part3

part1:all_movements.cpp
	g++ -o am.out -lwiringPi all_movements.cpp
part2:ColorLED.cpp
	g++ -o cl.out -lwiringPi ColorLED.cpp
part3:forward_a_back.cpp
	g++ -o fb.out -lwiringPi forward_a_back.cpp
.PHONY: clean
clean:
	rm *.out cpu_scheduling_output_file.txt