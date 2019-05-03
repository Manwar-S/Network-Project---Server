lurk_server: lurk_server.cpp
	g++ lurk_server.cpp  lurk_classes.cpp -pthread -g -o server

clean:
	rm server
