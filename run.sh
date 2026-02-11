#!/bin/bash
# Скрипт для запуска PFL с обходом конфликтов snap библиотек

# Сохраняем оригинальные переменные окружения
ORIG_LD_LIBRARY_PATH="$LD_LIBRARY_PATH"
ORIG_LD_PRELOAD="$LD_PRELOAD"

# Отключаем snap
unset SNAP
unset SNAP_NAME
unset SNAP_REVISION

# Устанавливаем пути только к системным библиотекам (без snap)
export LD_LIBRARY_PATH="/usr/lib/x86_64-linux-gnu:/lib/x86_64-linux-gnu:$ORIG_LD_LIBRARY_PATH"

# Отключаем snap preload
unset LD_PRELOAD

# Запускаем приложение
exec "$(dirname "$0")/build/PFL" "$@"
