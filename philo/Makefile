.POSIX:
# this file is NOT generated

OBJS := main.o init.o monitor.o end.o routine.o taken.o eating.o sleeping.o thinking.o unit.o wait_until.o tv.o ft_strict_atoi.o

NAME = philo

EXECUTABLE_TARGETS = $(NAME)

OTHER_USEFUL_FILES = .editorconfig .gitignore

LDFLAGS =
CFLAGS = -Wall -Wextra -Werror -O
ARFLAGS = cr


default: all
.PHONY: default


.PHONY: all
all: $(NAME) $(OTHER_USEFUL_FILES)

.PHONY: clean
clean:
	rm -f $(OBJS) $(OTHER_USEFUL_FILES)

.PHONY: fclean
fclean: clean
	rm -f $(EXECUTABLE_TARGETS)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all


.editorconfig:
	printf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig

.gitignore:
	(printf ".*\n*.o\n\n" && echo "$(EXECUTABLE_TARGETS)" | xargs -n 1 echo) > $@


$(EXECUTABLE_TARGETS):
	$(CC) $(LDFLAGS) -o $@ $^

$(NAME): $(OBJS)
