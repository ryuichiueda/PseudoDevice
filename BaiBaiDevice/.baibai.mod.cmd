savedcmd_baibai.mod := printf '%s\n'   baibai.o | awk '!x[$$0]++ { print("./"$$0) }' > baibai.mod
