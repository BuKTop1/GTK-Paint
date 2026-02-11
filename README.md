# PFL - GTK+ приложение для рисования

## Требования

- GCC или Clang компилятор
- GTK+ 3.0 или выше
- Инструменты сборки (make или cmake)

### Установка зависимостей (Debian/Ubuntu)

```bash
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install libgtk-3-dev
sudo apt-get install pkg-config
```

## Сборка

Из корня проекта:

### Способ 1
```bash
make
```

## 🔨 Способ 2

### Подготовка
```bash
mkdir build
cd build
cmake ..
```

### Сборка
```bash
make
```

### Запуск
```bash
./PFL
```