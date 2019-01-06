zmysqlapitest.bin:
	g++ -o $@ -g -O0 test/zmysqlapitest.cpp src/zmysqlapi.cpp -Iinc `mysql_config --cflags --libs`

clean:
	rm -rf zmysqlapitest.bin