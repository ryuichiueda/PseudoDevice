savedcmd_simple_ko.mod := printf '%s\n'   simple_ko.o | awk '!x[$$0]++ { print("./"$$0) }' > simple_ko.mod
