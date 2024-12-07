CC = clang
CFLAGS = -std=c23 -Wall -Wextra
LDFLAGS = -lcmocka
FORMATTER = clang-format

SRCS = $(shell find src/ -name '*.c')
OBJS = $(SRCS:src/%.c=build/%.o)

TARGET = build/target

all: $(TARGET)

run: $(TARGET)
	$(TARGET)

test: $(TARGET)
	$(TARGET) --test

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

format:
	$(FORMATTER) -i $(SRCS)

show_vars:
	@echo $(SRCS)


