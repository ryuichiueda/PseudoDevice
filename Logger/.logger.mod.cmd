savedcmd_logger.mod := printf '%s\n'   logger.o | awk '!x[$$0]++ { print("./"$$0) }' > logger.mod
