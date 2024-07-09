cc = gcc

source_dir = source
include_dir = include
bin_dir = bin
libdir = libs

target = $(bin_dir)/main

source = $(shell find $(source_dir) -name "*.c")
object = $(patsubst %.c, $(bin_dir)/%.o, $(source))
header =  $(shell find $(include_dir) -name "*.h")

flags = -I$(include_dir) -Wall -Wextra -Werror -lm -lSDL2
del = rm -f
mkdir = mkdir -p
print = echo

file_nbr = $(words $(source))
file_count = 0

all: $(target)
	@$<

$(bin_dir):
	@$(mkdir) $@

$(target): $(object)
	@$(print) "[$(file_nbr)/$(file_nbr)] Linking $@"
	@$(cc) $^ -o $@ $(flags)

$(bin_dir)/%.o: %.c $(header)
	@$(mkdir) $(dir $@)
	@$(print) "[$(file_count)/$(file_nbr)] Compiling $<"
	@$(cc) -c $< -o $@ $(flags)
	@$(eval file_count = $(shell expr $(file_count) + 1))

clean:
	@$(del) $(object) $(target)

fclean: clean
	@$(del) -r $(bin_dir)

re: clean all

.PHNOY: all clean fclean re
