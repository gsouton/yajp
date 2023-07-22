BUILD_DIR=./build
PROJECT_NAME=yajp

all: init_dir build compile

init_dir:
	mkdir -p $(BUILD_DIR)

.PHONY: build
build:
	cmake -B $(BUILD_DIR)

compile:
	make -C $(BUILD_DIR)

run:
	make && $(BUILD_DIR)/$(PROJECT_NAME)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
