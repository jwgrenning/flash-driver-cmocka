# To compile this, cmocka must be installed.  
# See README.md and cmocka.org

INCLUDE_DIRS =\
  -I .\
  
CFLAGS	= \
		  -Wall -Wall -Werror -Wswitch-default  -Wfatal-errors\
		  $(INCLUDE_DIRS) \

LDFLAGS		= \
		  -lcmocka \

TARGET		= test_runner

SRCS		= all_tests.c assert_tests.c io_mock.c

OBJ		= $(SRCS:%.c=%.o) \

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%: %.c
	$(CC) $(CFLAGS) $^

clean:
	rm -f $(TARGET) *.o
  