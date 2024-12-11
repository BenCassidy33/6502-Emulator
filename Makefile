CC = clang
CFLAGS = -Wall -Wextra
LDFLAGS = -lcmocka
FORMATTER = clang-format

SRCS = $(shell find core/ -name '*.c')
OBJS = $(SRCS:core/%.c=build/%.o)

TARGET = build/target

INPUT = test_program.asm

all: $(TARGET)

run: $(TARGET)
	$(TARGET) $(INPUT)

test: $(TARGET)
	$(TARGET) --test

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

build/%.o: core/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

format:
	$(FORMATTER) -i $(SRCS)

show_vars:
	@echo $(SRCS)


