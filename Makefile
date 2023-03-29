all: self_src_test

self_src: self_src.c
		@gcc self_src.c -o self_src

self_src_print.c: self_src
		@$(realpath self_src) > self_src_print.c

self_src_test: self_src_test.sh self_src_print.c self_src.c
		@$(realpath self_src_test.sh) self_src_print.c self_src.c

clean:
	@rm -rf self_src_print.c self_src

.PHONY: all clean
