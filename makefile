build:
	mkdir build
	cmake -B ./build -S .
	make -C build

run:
	./build/gitignore $(ARGS)

clean:
	rm -rf build
